/* 
 * File:   Compressor.h
 * Author: felsamps
 *
 * Created on September 11, 2012, 7:02 PM
 */

#ifndef _COMPRESSOR_H
#define	_COMPRESSOR_H

#include <vector>
#include <string>

#include "Huffman.h"
#include "Defines.h"

using namespace std;

class Compressor {
private:
    vector<Huffman*> tables;
    FILE *fpMe, *fpDe;

    /*Compressor Results*/
    long long int compressBW, uncompressBW;

public:
    Compressor(string me, string de, vector<Huffman*> h);

    void compress();
    void report();

};

#endif	/* _COMPRESSOR_H */

