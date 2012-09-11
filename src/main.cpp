#include <iostream>

#include "Statistic.h"
#include "Huffman.h"


using namespace std;

int main(int argc, char* argv[]) {

	string fileMe(argv[1]);
	string fileDe(argv[2]);
	

	Statistic stats(fileMe, fileDe);
	stats.processMvdFiles();

	Huffman h0(stats.getOccMap(X_ME));
	
	h0.buildTree();
	h0.genBitLengthTable();
	h0.reportBitLengthTable();
	
}
