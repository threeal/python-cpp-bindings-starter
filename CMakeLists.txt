cmake_minimum_required(VERSION 3.19)
project(bonacci LANGUAGES CXX)

find_package(Python COMPONENTS Interpreter Development.Module REQUIRED)

execute_process(
  COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
  OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE nanobind_ROOT
  COMMAND_ERROR_IS_FATAL ANY)

find_package(nanobind CONFIG REQUIRED)

nanobind_add_module(sequence src/bonacci/sequence.cpp)
install(TARGETS sequence DESTINATION bonacci)
