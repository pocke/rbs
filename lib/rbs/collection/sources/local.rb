module RBS
  module Collection
    module Sources
      class Local
        attr_reader :path

        def initialize(path:, base_dir:)
          # TODO: resolve relative path from dir of rbs_collection.yaml
          @path = bae_dir.join(path)
        end

        def has?(config_entry)
          gem_name = config_entry['name']
          @path.join(gem_name).directory?
        end

        def versions(config_entry)
          gem_name = config_entry['name']
          @path.join(gem_name).glob('*/').map { |path| path.basename.to_s }
        end

        # This method does nothing except printing message.
        # RBS runtime refers @path directory directly.
        # It will be useful because users do not need to re-run `rbs collection install`
        # when the RBS files are updated.
        def install(dest:, config_entry:, stdout:)
          name = config_entry['name']
          version = config_entry['version'] or raise
          from = @path.join(name, version)
          stdout.puts "Using #{name}:#{version} (#{from})"
        end

        def manifest_of(config_entry)
          gem_name = config_entry['name']
          version = config_entry['version'] or raise
          gem_dir = @path.join(gem_name, version)

          manifest_path = gem_dir.join('manifest.yaml')
          YAML.safe_load(manifest_path.read) if manifest_path.exist?
        end

        def to_lockfile
          {
            'type' => 'local',
            'path' => @path.to_s,
          }
        end
      end
    end
  end
end
