cmake_minimum_required( VERSION 3.0 )

project(huffman)

file(
    GLOB_RECURSE
    source_files
    src/*
)

add_executable(
    huffamn
    ${source_files}
)
