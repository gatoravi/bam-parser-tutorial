/*  parse_bam.cc -- Example BAM parser using the htslib API

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

#include "hts.h"
#include "sam.h"

using namespace std;

int usage() {
    cerr << "./parse_bam_from_start example.bam";
    cerr << endl << "Useful for BAMs with unmapped reads.";
    return 0;
}

int parse_bam_from_start(int argc, char* argv[]) {
    if(argc < 2) {
        return usage();
    }
    string bam = string(argv[1]);
    string region_ = ".";
    if(argc > 2) {
        region_ = string(argv[2]);
    }
    if(!bam.empty()) {
        //open BAM for reading
        samFile *in = sam_open(bam.c_str(), "r");
        if(in == NULL) {
            throw runtime_error("Unable to open BAM/SAM file.");
        }
        //Get the header
        bam_hdr_t *header = sam_hdr_read(in);
        if(header == NULL) {
            sam_close(in);
            throw runtime_error("Unable to open BAM header.");
        }
        //Initiate the alignment record
        bam1_t *aln = bam_init1();
        while(sam_read1(in, header, aln) >= 0) {
            cout << "Read Chr: " << header->target_name[aln->core.tid];
            cout << "\tPos: " << aln->core.pos;
            string seq, qual;
            uint8_t *quali = bam_get_qual(aln);
            uint8_t *seqi = bam_get_seq(aln);
            for (int i = 0; i < aln->core.l_qseq; i++) {
                seq += seq_nt16_str[bam_seqi(seqi, i)];
                qual += 33 + quali[i];
            }
            cout << "\tSeq: " << seq << "\tQual: " << qual;
            cout << endl;
        }
        bam_destroy1(aln);
        bam_hdr_destroy(header);
        sam_close(in);
    }
    return 0;
}

int main(int argc, char* argv[]) {
    try {
        parse_bam_from_start(argc, argv);
    } catch (const runtime_error& e) {
        cerr << e.what();
    }
}
