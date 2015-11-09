/*  parse_vcf.cc

    Copyright (c) 2015, Washington University

    Author: Avinash Ramu <avinash3003@yahoo.co.in>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.  */

#include <iostream>
#include <stdexcept>
#include "vcf.h"

int usage() {
    std::cerr << "Usage: ./vcf-parser example.vcf" << std::endl;
    return 1;
}

int main(int argc, char* argv[]) {
    if(argc == 2) {
        htsFile *test_bcf = NULL;
        bcf_hdr_t *test_header = NULL;
        bcf1_t *test_record = bcf_init();
        test_bcf = bcf_open(argv[1], "r");
        if(test_bcf == NULL) {
            throw std::runtime_error("Unable to open file.");
        }
        test_header = bcf_hdr_read(test_bcf);
        if(test_header == NULL) {
            throw std::runtime_error("Unable to read header.");
        }
        std::cout << "chromosome\tposition\tnum_alleles" << std::endl;
        while(bcf_read(test_bcf, test_header, test_record) == 0) {
            std::cout << bcf_hdr_id2name(test_header, test_record->rid) << "\t" <<
                         test_record->pos << "\t" <<
                         test_record->n_allele << "\t" <<
                         std::endl;
        }
        bcf_hdr_destroy(test_header);
        bcf_destroy(test_record); 
        bcf_close(test_bcf);
    } else {
        return usage();
    }
    return 0;
}
