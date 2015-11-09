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
./bam-parser test/example.bam 1
```
###BAM parsing - specify region in chr:start-end format
```
./bam-parser test/example.bam 1
```

###VCF parsing
```
./vcf-parser test/example.vcf
```
