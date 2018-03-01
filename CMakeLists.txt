cmake_minimum_required(VERSION 3.7)
project(cpp_learning)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        tcpppl/ch13/error_handle.cc
        tcpppl/ch16/access_control.cc
        tcpppl/ch16/class_struct.cc
        tcpppl/ch16/concrete_class.cc
        tcpppl/ch16/constructor.cc
        tcpppl/ch16/in_class_func.cc
        tcpppl/ch16/member_access.cc
        tcpppl/ch16/member_functions.cc
        tcpppl/ch16/member_type.cc
        tcpppl/ch16/mutable.cc
        tcpppl/ch16/pointer_to_func.cc
        tcpppl/ch16/self_reference.cc
        tcpppl/ch16/static_member.cc
        tcpppl/arguments_passing.cc
        tcpppl/array_arguments.cc
        tcpppl/array_generic.cc
        tcpppl/array_ref_argument.cc
        tcpppl/default_argument_repeat.cc
        tcpppl/function_dec_def.cc
        tcpppl/function_return_type.cc
        tcpppl/function_static.cc
        tcpppl/function_unused_arguments.cc
        tcpppl/lambda_func.cc
        tcpppl/list_arguments.cc
        tcpppl/macro_pre.cc
        tcpppl/macro_predefine.cc
        tcpppl/macro_spec.cc
        tcpppl/main.cc
        tcpppl/overloading_scope.cc
        tcpppl/pointer_to_function.cc
        tcpppl/reference_arguments.cc
        tcpppl/size_t.cc
        tcpppl/std_printf.cc
        tcpppl/support.cc
        tcpppl/type_conversion.cc
        tcpppl/variable_arguments.cc tcpppl/ch16/helper_func.cc tcpppl/ch16/overloaded_operator.cc)

add_executable(cpp_learning ${SOURCE_FILES})