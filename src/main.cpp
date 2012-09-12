#include <iostream>
#include <vector>
#include "Statistic.h"
#include "Huffman.h"
#include "Compressor.h"


using namespace std;

int main(int argc, char* argv[]) {

	string fileMe(argv[1]);
	string fileDe(argv[2]);
	string dataMe(argv[3]);
	string dataDe(argv[4]);

	Statistic stats(fileMe, fileDe);
	stats.processMvdFiles();

	vector<Huffman*> h(4);
	/*
	h[X_ME] = new Huffman(stats.getOccMap(X_ME));
	h[Y_ME] = new Huffman(stats.getOccMap(Y_ME));
	h[X_DE] = new Huffman(stats.getOccMap(X_DE));
	h[Y_DE] = new Huffman(stats.getOccMap(Y_DE));
	*/

	for (int i = 0; i < 4; i++) {
		h[i] = new Huffman(stats.getOccMap(i));
		h[i]->buildTree();
		h[i]->genBitLengthTable();
		//h[i]->reportStats();
		//h[i]->reportBitLengthTable();
	}

	Compressor comp(dataMe, dataDe, h);
	comp.compress();
	comp.report();
	
}
