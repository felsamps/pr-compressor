#include "Huffman.h"

Huffman::Huffman(map<int,long long int> occ) {
	this->l.clear();
	this->bitLength.clear();

	for(map<int,long long int>::iterator it = occ.begin(); it != occ.end(); it++) {
		Node *n = new Node((*it).first, (*it).second);
		this->l.push_back(n);
	}
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
	cout << this->bitLength.size() << endl;
	
}

void Huffman::reportBitLengthTable() {
	for(map<int,short>::iterator it = this->bitLength.begin(); it != this->bitLength.end(); it++) {
		cout << (*it).first << "\t" << (*it).second << endl;
	}
}