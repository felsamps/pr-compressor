#include "Huffman.h"
#include "Defines.h"

Huffman::Huffman(map<int,long long int> occ) {
	this->l.clear();
	this->bitLength.clear();
	this->total = 0;
	this->mean = 0.0;

	for(map<int,long long int>::iterator it = occ.begin(); it != occ.end(); it++) {
		Node *n = new Node((*it).first, (*it).second);
		this->mean += n->occ * n->symbol;
		this->total += n->occ;
	}
	this->mean = this->mean / this->total;
	this->std = xCalcStdDev(occ);
	this->thL = (int) this->mean - SIGMA_TIMES * this->std;
	this->thH = (int) this->mean + SIGMA_TIMES * this->std;

	for(map<int,long long int>::iterator it = occ.begin(); it != occ.end(); it++) {
		Node *n = new Node((*it).first, (*it).second);
		if( n->symbol >= this->thL && n->symbol <= this->thH ) {
			this->l.push_back(n);
		}
	}

	Node *special = new Node(OUT_OF_RANGE_SYMBOL, (SIGMA_PCTG * this->total));
	this->l.push_back(special);

}

double Huffman::xCalcStdDev(map<int,long long int> occ) {
	double acum1 = 0.0;
	for(map<int,long long int>::iterator it = occ.begin(); it != occ.end(); it++) {
		acum1 += (pow(this->mean - (*it).first, 2) * (*it).second);
	}
	return pow(acum1 / (this->total-1), 0.5);
}

bool compareNodes(Node *n0, Node *n1) {
    return n0->occ > n1->occ;
}

void Huffman::reportList() {
	for(list<Node*>::iterator it = this->l.begin(); it != this->l.end(); it++) {
		cout << (*it)->symbol << "\t" << (*it)->occ << endl;
	}
}

void Huffman::buildTree() {
	while(this->l.size() != 1) {
		this->l.sort(compareNodes);
		Node *n0 = this->l.back();
		this->l.pop_back();
		Node *n1 = this->l.back();
		this->l.pop_back();
		Node *nNew = new Node(n0, n1);
		this->l.push_back(nNew);
	}
	
	this->head = this->l.front();
}

void Huffman::genBitLengthTable() {
	this->head->insertCurrOcc(this->bitLength, 0);
	
}

void Huffman::reportBitLengthTable() {
	for(map<int,short>::iterator it = this->bitLength.begin(); it != this->bitLength.end(); it++) {
		cout << (*it).first << "\t" << (*it).second << endl;
	}
}

void Huffman::reportStats() {
	cout << this->mean << " " << this->std << " " << this->thL << " " << this->thH << endl;
}

int Huffman::getBitLength(int symbol) {
	if(symbol >= this->thL && symbol <= this->thH) {
		return bitLength[symbol];
	}
	else {
		return bitLength[OUT_OF_RANGE_SYMBOL] + UNCOMPRESSED_VECTOR_BIT_L;
	}
}

int Huffman::getTableSize() {
	return bitLength.size();
}