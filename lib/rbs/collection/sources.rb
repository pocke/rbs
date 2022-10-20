# frozen_string_literal: true

require_relative './sources/base'
require_relative './sources/git'
require_relative './sources/stdlib'
require_relative './sources/rubygems'

module RBS
  module Collection
    module Sources
      def self.from_config_entry(source_entry, base_dir:)
        case source_entry['type']
        when 'git', nil # git source by default
          __skip__ = Git.new(**source_entry.slice('name', 'revision', 'remote', 'repo_dir').transform_keys(&:to_sym))
        when 'local'
          __skip__ = Local.new(path: source_entry['path'], base_dir: base_dir)
        when 'stdlib'
          Stdlib.instance
        when 'rubygems'
          Rubygems.instance
        else
          raise
        end
      end
    end
  end
end
