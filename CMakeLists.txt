cmake_minimum_required(VERSION 3.19)
project(bonacci_bindings LANGUAGES CXX)

find_package(Python COMPONENTS Interpreter Development.Module REQUIRED)

execute_process(
  COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
  OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE nanobind_ROOT
  COMMAND_ERROR_IS_FATAL ANY)

find_package(nanobind CONFIG REQUIRED)

nanobind_add_module(sequence src/bonacci_bindings/sequence.cpp)
install(TARGETS sequence DESTINATION bonacci_bindings)
