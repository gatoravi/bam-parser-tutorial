##Synopsis
This is a simple BAM parsing tutorial. This uses the htslib API and
is supposed to help get started quickly when building with CMake.

##Install
```
mkdir build
cd build
cmake ..
make
```

##Usage
###BAM parsing - no region
```
./bam-parser ../../regtools/tests/integration-test/data/test_hcc1395.bam
```
###BAM parsing - specify region in chr:start-end format
```
./bam-parser ../../regtools/tests/integration-test/data/test_hcc1395.bam 1
```
