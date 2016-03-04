AUX_SOURCE_DIRECTORY(cram/ CRAM)

set(SOURCES
    bgzf.c
    faidx.c
    hts.c
    hfile.c
    hfile_net.c
    kstring.c
    knetfile.c
    synced_bcf_reader.c
    tbx.c
    vcf.c
    sam.c)


include_directories(.)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wno-long-long")
find_package(Threads)
add_library(htslib ${SOURCES} ${CRAM})

#find zlib
find_package(ZLIB REQUIRED)
if(ZLIB_FOUND)
    include_directories(${ZLIB_INCLUDE_DIRS})
    target_link_libraries(htslib ${ZLIB_LIBRARIES} )
endif(ZLIB_FOUND)

target_link_libraries (htslib ${CMAKE_THREAD_LIBS_INIT})
