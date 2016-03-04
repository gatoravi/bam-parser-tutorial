[![Build Status](https://travis-ci.org/gatoravi/bam-parser-tutorial.svg?branch=master)](https://travis-ci.org/gatoravi/bam-parser-tutorial)

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
###BAM parsing - no region(entire BAM file)
```
./bam-parser test/example.bam
```
###BAM parsing - specify region in chr:start-end format
```
./bam-parser test/example.bam 1
```

###VCF parsing
####Print every record in the VCF
```
./vcf-parser test/example.vcf
```

####Pull out variants in a specified region from the VCF
```
./vcf-parser-region  test/example.vcf 22:167679-175311
```
