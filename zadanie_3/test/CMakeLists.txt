cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test catch.hh product_tests.cpp catch_config.cpp ../include/product.h ../src/product.cpp ../src/date.cpp ../include/date.h ../include/producer.h ../src/producer.cpp ../src/component.cpp ../include/component.h)
