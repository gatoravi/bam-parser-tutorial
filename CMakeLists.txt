cmake_minimum_required(VERSION 2.8)

project(bam-parser)

include_directories ("${PROJECT_SOURCE_DIR}/htslib/")
add_subdirectory ("${PROJECT_SOURCE_DIR}/htslib/")

#The main executable
add_executable (bam-parser parse_bam.cc)
target_link_libraries (bam-parser htslib)
