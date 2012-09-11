#include <iostream>

#include "Statistic.h"
#include "Huffman.h"


using namespace std;

int main(int argc, char* argv[]) {

	string fileMe(argv[1]);
	string fileDe(argv[2]);
	int idx = atoi(argv[3]);

	Statistic stats(fileMe, fileDe);
	stats.processMvdFiles();

	Huffman h0(stats.getOccMap(idx));
	
	h0.buildTree();
	h0.genBitLengthTable();
	h0.reportStats();
	//h0.reportBitLengthTable();
	
}
