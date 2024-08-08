#include "rbs_extension.h"

#ifdef RB_PASS_KEYWORDS
  // Ruby 2.7 or later
  #define CLASS_NEW_INSTANCE(klass, argc, argv)\
          rb_class_new_instance_kw(argc, argv, klass, RB_PASS_KEYWORDS)
#else
  // Ruby 2.6
  #define CLASS_NEW_INSTANCE(receiver, argc, argv)\
          rb_class_new_instance(argc, argv, receiver)
#endif

VALUE rbs_base_type(VALUE klass, VALUE location) {
  return rb_class_new_instance(
    1,
    &location,
    klass
  );
}


VALUE rbs_namespace(VALUE path, VALUE absolute) {
  VALUE args[2];
  args[0] = path;
  args[1] = absolute;
  return rb_class_new_instance(
    2,
    args,
    RBS_Namespace
  );
}

VALUE rbs_type_name(VALUE namespace, VALUE name) {
  VALUE args[2];
  args[0] = namespace;
  args[1] = name;

  return rb_class_new_instance(
    2,
    args,
    RBS_TypeName
  );
}

VALUE rbs_class_instance(VALUE typename, VALUE type_args, VALUE location) {
  VALUE args[3];
  args[0] = typename;
  args[1] = type_args;
  args[2] = location;

  return rb_class_new_instance(
    3,
    args,
    RBS_Types_ClassInstance
  );
}

VALUE rbs_class_singleton(VALUE typename, VALUE location) {
  VALUE args[2];
  args[0] = typename;
  args[1] = location;

  return rb_class_new_instance(
    2,
    args,
    RBS_Types_ClassSingleton
  );
}

VALUE rbs_alias(VALUE typename, VALUE args, VALUE location) {
  VALUE init_args[3];
  init_args[0] = typename;
  init_args[1] = args;
  init_args[2] = location;

  return rb_class_new_instance(
    3,
    init_args,
    RBS_Types_Alias
  );
}

VALUE rbs_interface(VALUE typename, VALUE type_args, VALUE location) {
  VALUE args[3];
  args[0] = typename;
  args[1] = type_args;
  args[2] = location;

  return rb_class_new_instance(
    3,
    args,
    RBS_Types_Interface
  );
}

VALUE rbs_union(VALUE types, VALUE location) {
  VALUE args[2];
  args[0] = types;
  args[1] = location;

  return rb_class_new_instance(
    2,
    args,
    RBS_Types_Union
  );
}

VALUE rbs_intersection(VALUE types, VALUE location) {
  VALUE args[2];
  args[0] = types;
  args[1] = location;

  return rb_class_new_instance(
    2,
    args,
    RBS_Types_Intersection
  );
}

VALUE rbs_tuple(VALUE types, VALUE location) {
  VALUE args[2];
  args[0] = types;
  args[1] = location;

  return rb_class_new_instance(
    2,
    args,
    RBS_Types_Tuple
  );
}

VALUE rbs_optional(VALUE type, VALUE location) {
  VALUE args[2];
  args[0] = type;
  args[1] = location;

  return rb_class_new_instance(
    2,
    args,
    RBS_Types_Optional
  );
}

VALUE rbs_block(VALUE type, VALUE required, VALUE self_type) {
  VALUE args[3];
  args[0] = type;
  args[1] = required;
  args[2] = self_type;

  return rb_class_new_instance(
    3,
    args,
    RBS_Types_Block
  );
}

VALUE rbs_function_param(VALUE type, VALUE name, VALUE location) {
  VALUE args[3];
  args[0] = type;
  args[1] = name;
  args[2] = location;

  return rb_class_new_instance(
    3,
    args,
    RBS_Types_Function_Param
  );
}

VALUE rbs_untyped_function(VALUE return_type) {
  return rb_class_new_instance(
    1,
    &return_type,
    RBS_Types_UntypedFunction
  );
}

VALUE rbs_function(
  VALUE required_positional_params,
  VALUE optional_positional_params,
  VALUE rest_positional_param,
  VALUE trailing_positional_params,
  VALUE required_keyword_params,
  VALUE optional_keyword_params,
  VALUE rest_keyword_param,
  VALUE return_type
) {
  VALUE args[8];
  args[0] = required_positional_params;
  args[1] = optional_positional_params;
  args[2] = rest_positional_param;
  args[3] = trailing_positional_params;
  args[4] = required_keyword_params;
  args[5] = optional_keyword_params;
  args[6] = rest_keyword_param;
  args[7] = return_type;
  return rb_class_new_instance(
    8,
    args,
    RBS_Types_Function
  );
}

VALUE rbs_proc(VALUE function, VALUE block, VALUE location, VALUE self_type) {
  VALUE args[4];
  args[0] = function;
  args[1] = block;
  args[2] = location;
  args[3] = self_type;

  return rb_class_new_instance(
    4,
    args,
    RBS_Types_Proc
  );
}

VALUE rbs_void(VALUE location) {
  return rb_class_new_instance(
    1,
    &location,
    RBS_Types_Bases_Void
  );
}

VALUE rbs_literal(VALUE literal, VALUE location) {
  VALUE args[2];
  args[0] = literal;
  args[1] = location;
  
  return rb_class_new_instance(
    2,
    args,
    RBS_Types_Literal
  );
}

VALUE rbs_record(VALUE fields,VALUE location) {
  VALUE args = rb_hash_new();
  rb_hash_aset(args, ID2SYM(rb_intern("location")), location);
  rb_hash_aset(args, ID2SYM(rb_intern("all_fields")), fields);

  return CLASS_NEW_INSTANCE(
    RBS_Types_Record,
    1,
    &args
  );
}

VALUE rbs_variable(VALUE name, VALUE location) {
  VALUE args[2];
  args[0] = name;
  args[1] = location;

  return rb_class_new_instance(
    2,
    args,
    RBS_Types_Variable
  );
}

VALUE rbs_method_type(VALUE type_params, VALUE type, VALUE block, VALUE location) {
  VALUE args[4];
  args[0] = type_params;
  args[1] = type;
  args[2] = block;
  args[3] = location;

  return rb_class_new_instance(
    4,
    args,
    RBS_MethodType
  );
}

VALUE rbs_ast_comment(VALUE string, VALUE location) {
  VALUE args[2];
  args[0] = string;
  args[1] = location;

  return rb_class_new_instance(
    2,
    args,
    RBS_AST_Comment
  );
}

VALUE rbs_ast_annotation(VALUE string, VALUE location) {
  VALUE args[2];
  args[0] = string;
  args[1] = location;

  return rb_class_new_instance(
    2,
    args,
    RBS_AST_Annotation
  );
}

VALUE rbs_ast_type_param(VALUE name, VALUE variance, bool unchecked, VALUE upper_bound, VALUE location) {
  VALUE args[4];
  args[0] = name;
  args[1] = variance;
  args[2] = upper_bound;
  args[3] = location;

  VALUE type_param = rb_class_new_instance(
    4,
    args,
    RBS_AST_TypeParam
  );

  if (unchecked) {
    rb_funcall(type_param, rb_intern("unchecked!"), 0);
  }

  return type_param;
}

VALUE rbs_ast_decl_constant(VALUE name, VALUE type, VALUE location, VALUE comment) {
  VALUE args[4];
  args[0] = name;
  args[1] = type;
  args[2] = location;
  args[3] = comment;

  return rb_class_new_instance(
    4,
    args,
    RBS_AST_Declarations_Constant
  );
}

VALUE rbs_ast_decl_global(VALUE name, VALUE type, VALUE location, VALUE comment) {
  VALUE args[4];
  args[0] = name;
  args[1] = type;
  args[2] = location;
  args[3] = comment;

  return rb_class_new_instance(
    4,
    args,
    RBS_AST_Declarations_Global
  );
}

VALUE rbs_ast_decl_type_alias(VALUE name, VALUE type_params, VALUE type, VALUE annotations, VALUE location, VALUE comment) {
  VALUE args[6];
  args[0] = name;
  args[1] = type_params;
  args[2] = type;
  args[3] = annotations;
  args[4] = location;
  args[5] = comment;

  return rb_class_new_instance(
    6,
    args,
    RBS_AST_Declarations_TypeAlias
  );
}

VALUE rbs_ast_decl_interface(VALUE name, VALUE type_params, VALUE members, VALUE annotations, VALUE location, VALUE comment) {
  VALUE args[6];
  args[0] = name;
  args[1] = type_params;
  args[2] = members;
  args[3] = annotations;
  args[4] = location;
  args[5] = comment;

  return rb_class_new_instance(
    6,
    args,
    RBS_AST_Declarations_Interface
  );
}

VALUE rbs_ast_decl_module_self(VALUE name, VALUE args, VALUE location) {
  VALUE init_args[3];
  init_args[0] = name;
  init_args[1] = args;
  init_args[2] = location;

  return rb_class_new_instance(
    3,
    init_args,
    RBS_AST_Declarations_Module_Self
  );
}

VALUE rbs_ast_decl_module(VALUE name, VALUE type_params, VALUE self_types, VALUE members, VALUE annotations, VALUE location, VALUE comment) {
  VALUE args[7];
  args[0] = name;
  args[1] = type_params;
  args[2] = members;
  args[3] = self_types;
  args[4] = annotations;
  args[5] = location;
  args[6] = comment;
  return rb_class_new_instance(
    7,
    args,
    RBS_AST_Declarations_Module
  );
}

VALUE rbs_ast_decl_class_alias(VALUE new_name, VALUE old_name, VALUE location, VALUE comment) {
  VALUE args[4];
  args[0] = new_name;
  args[1] = old_name;
  args[2] = location;
  args[3] = comment;

  return rb_class_new_instance(
    4,
    args,
    RBS_AST_Declarations_ClassAlias
  );
}

VALUE rbs_ast_decl_module_alias(VALUE new_name, VALUE old_name, VALUE location, VALUE comment) {
  VALUE args[4];
  args[0] = new_name;
  args[1] = old_name;
  args[2] = location;
  args[3] = comment;

  return rb_class_new_instance(
    4,
    args,
    RBS_AST_Declarations_ModuleAlias
  );
}

VALUE rbs_ast_members_method_definition_overload(VALUE annotations, VALUE method_type) {
  VALUE args[2];
  args[0] = method_type;
  args[1] = annotations;

  return rb_class_new_instance(
    2,
    args,
    RBS_AST_Members_MethodDefinition_Overload
  );
}

VALUE rbs_ast_members_method_definition(VALUE name, VALUE kind, VALUE overloads, VALUE annotations, VALUE location, VALUE comment, VALUE overloading, VALUE visibility) {
  VALUE args[8];
  args[0] = name;
  args[1] = kind;
  args[2] = overloads;
  args[3] = annotations;
  args[4] = location;
  args[5] = comment;
  args[6] = overloading;
  args[7] = visibility;
  return rb_class_new_instance(
    8,
    args,
    RBS_AST_Members_MethodDefinition
  );
}

VALUE rbs_ast_members_variable(VALUE klass, VALUE name, VALUE type, VALUE location, VALUE comment) {
  VALUE args[4];
  args[0] = name;
  args[1] = type;
  args[2] = location;
  args[3] = comment;
  return rb_class_new_instance(
    4,
    args,
    klass
  );
}

VALUE rbs_ast_members_mixin(VALUE klass, VALUE name, VALUE module_args, VALUE annotations, VALUE location, VALUE comment) {
  VALUE args[5];
  args[0] = name;
  args[1] = module_args;
  args[2] = annotations;
  args[3] = location;
  args[4] = comment;

  return rb_class_new_instance(
    5,
    args,
    klass
  );
}

VALUE rbs_ast_members_attribute(VALUE klass, VALUE name, VALUE type, VALUE ivar_name, VALUE kind, VALUE annotations, VALUE location, VALUE comment, VALUE visibility) {
  VALUE args[8];
  args[0] = name;
  args[1] = type;
  args[2] = ivar_name;
  args[3] = kind;
  args[4] = annotations;
  args[5] = location;
  args[6] = comment;
  args[7] = visibility;
  return rb_class_new_instance(
    8,
    args,
    klass
  );
}

VALUE rbs_ast_members_visibility(VALUE klass, VALUE location) {
  return rb_class_new_instance(
    1,
    &location,
    klass
  );
}

VALUE rbs_ast_members_alias(VALUE new_name, VALUE old_name, VALUE kind, VALUE annotations, VALUE location, VALUE comment) {
  VALUE args[6];
  args[0] = new_name;
  args[1] = old_name;
  args[2] = kind;
  args[3] = annotations;
  args[4] = location;
  args[5] = comment;

  return rb_class_new_instance(
    6,
    args,
    RBS_AST_Members_Alias
  );
}

VALUE rbs_ast_decl_class_super(VALUE name, VALUE args, VALUE location) {
  VALUE init_args[3];
  init_args[0] = name;
  init_args[1] = args;
  init_args[2] = location;

  return rb_class_new_instance(
    3,
    init_args,
    RBS_AST_Declarations_Class_Super
  );
}

VALUE rbs_ast_decl_class(VALUE name, VALUE type_params, VALUE super_class, VALUE members, VALUE annotations, VALUE location, VALUE comment) {
  VALUE init_args[7];
  init_args[0] = name;
  init_args[1] = type_params;
  init_args[2] = super_class;
  init_args[3] = members;
  init_args[4] = annotations;
  init_args[5] = location;
  init_args[6] = comment;

  return rb_class_new_instance(
    7,
    init_args,
    RBS_AST_Declarations_Class
  );
}

VALUE rbs_ast_directives_use(VALUE clauses, VALUE location) {
  VALUE args[2];
  args[0] = clauses;
  args[1] = location;

  return rb_class_new_instance(
    2,
    args,
    RBS_AST_Directives_Use
  );
}

VALUE rbs_ast_directives_use_single_clause(VALUE type_name, VALUE new_name, VALUE location) {
  VALUE args[3];
  args[0] = type_name;
  args[1] = new_name;
  args[2] = location;
  return rb_class_new_instance(
    3,
    args,
    RBS_AST_Directives_Use_SingleClause
  );
}

VALUE rbs_ast_directives_use_wildcard_clause(VALUE namespace, VALUE location) {
  VALUE args[2];
  args[0] = namespace;
  args[1] = location;
  return rb_class_new_instance(
    2,
    args,
    RBS_AST_Directives_Use_WildcardClause
  );
}
