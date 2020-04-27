cmake_minimum_required(VERSION 3.16)
project(Modificacion)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Modificacion
        dll_node_t.hpp
        dll_t.hpp
        main_sparse_matrix_t.cpp
        matrix_t.hpp
        pair_t.hpp
        sparse_matrix_t.hpp
        sparse_vector_t.hpp
        vector_t.hpp)
