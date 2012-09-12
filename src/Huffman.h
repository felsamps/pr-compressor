#ifndef _HUFFMAN_H
#define	_HUFFMAN_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node {
    int symbol;
    long long int occ;
    Node *s0, *s1;

    Node(int s, long long int o) {
        this->symbol = s;
        this->occ = o;
        s0 = NULL;
        s1 = NULL;
    }

    Node(Node* n0, Node* n1) {
        this->symbol = 666;
        this->occ = n0->occ + n1->occ;
        this->s0 = n0;
        this->s1 = n1;
    }
    void insertCurrOcc(map<int,short>& m, short d) {
        if(this->s0 == NULL && this->s1 == NULL) {
            m[symbol] = d;
        }
        else {
            this->s0->insertCurrOcc(m, d+1);
            this->s1->insertCurrOcc(m, d+1);
        }
    }
};

class Huffman {

private:
    list<Node*> l;
    Node* head;
    map<int, short> bitLength;
    long long int total;
    double mean;
    double std;
    int thL, thH;

public:
    Huffman(map<int, long long int> occ);

    double xCalcStdDev(map<int,long long int> occ);
    void buildTree();
    void genBitLengthTable();
    int getBitLength(int symbol);
    
    void reportBitLengthTable();
    void reportList();
    void reportStats();
    int getTableSize();

};

#endif	/* _HUFFMAN_H */

