/* 
 * File:   Compressor.cpp
 * Author: felsamps
 * 
 * Created on September 11, 2012, 7:02 PM
 */

#include "Compressor.h"

Compressor::Compressor(string me, string de, vector<Huffman*> h) {
	this->fpMe = fopen(me.c_str(), "r");
	this->fpDe = fopen(de.c_str(), "r");
	this->tables = h;
	compressBW = 0;
	uncompressBW = 0;
}

void Compressor::compress() {
	/*Motion Estimation*/
	while( !feof(this->fpMe) ) {
		int x, y;
		fscanf(this->fpMe, "%d %d", &x, &y);
		/*compressed bandwidth accumulation */
		compressBW += this->tables[X_ME]->getBitLength(x);
		compressBW += this->tables[Y_ME]->getBitLength(y);
		compressBW += UNCOMPRESSED_SAD_BIT_L;
		
		/*uncompressed bandwidth accumulation */
		uncompressBW += UNCOMPRESSED_VECTOR_BIT_L;
		uncompressBW += UNCOMPRESSED_VECTOR_BIT_L;
		uncompressBW += UNCOMPRESSED_SAD_BIT_L;
	}

	/*Disparity Estimation*/
	while( !feof(this->fpDe) ) {
		int x, y;
		fscanf(this->fpDe, "%d %d", &x, &y);
		/*compressed bandwidth accumulation */
		this->compressBW += this->tables[X_DE]->getBitLength(x);
		this->compressBW += this->tables[Y_DE]->getBitLength(y);
		this->compressBW += UNCOMPRESSED_SAD_BIT_L;

		/*uncompressed bandwidth accumulation */
		this->uncompressBW += UNCOMPRESSED_VECTOR_BIT_L;
		this->uncompressBW += UNCOMPRESSED_VECTOR_BIT_L;
		this->uncompressBW += UNCOMPRESSED_SAD_BIT_L;
	}

	fclose(this->fpMe);
	fclose(this->fpDe);
}

void Compressor::report() {
	double savingBW = (this->uncompressBW - this->compressBW) / (double)this->uncompressBW;
	cout << "Compress BW:\t" << this->compressBW << endl;
	cout << "Original BW:\t" << this->uncompressBW << endl;
	cout << "Ratio (%):\t" << savingBW*100 << endl;
	cout << "Table Sizes: " <<
			tables[0]->getTableSize() << " " <<
			tables[1]->getTableSize() << " " <<
			tables[2]->getTableSize() << " " <<
			tables[3]->getTableSize() << endl;

}