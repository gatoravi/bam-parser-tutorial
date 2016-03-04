cmake_minimum_required(VERSION 2.8)

project(hts-parser)

include_directories ("${PROJECT_SOURCE_DIR}/htslib/")
include_directories ("${PROJECT_SOURCE_DIR}/htslib/htslib")
add_subdirectory ("${PROJECT_SOURCE_DIR}/htslib/")

#The bam-parser executable
add_executable (bam-parser parse_bam.cc)
target_link_libraries (bam-parser htslib)

#The bam-parser-from-start executable
add_executable (bam-parser-from-start parse_bam_from_start.cc)
target_link_libraries (bam-parser-from-start htslib)

#The vcf-parser executable
add_executable (vcf-parser parse_vcf.cc)
target_link_libraries (vcf-parser htslib)

#The vcf-parser executable
add_executable (vcf-parser-region parse_vcf_by_region.cc)
target_link_libraries (vcf-parser-region htslib)
