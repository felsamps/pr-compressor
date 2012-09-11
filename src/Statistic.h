#ifndef _STATISTIC_H
#define	_STATISTIC_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <list>
#include <map>

#include "Defines.h"

using namespace std;

struct Node {
    int symbol;
    long long int occ;
    Node *s0, *s1;

    Node(int s) {
        this->symbol = s;
        this->occ = 0;
        s0 = NULL;
        s1 = NULL;
    }
};

class Statistic {
    FILE *fpMe, *fpDe;
    map<int, long long int> xMe, xDe;
    map<int, long long int> yMe, yDe;
public:
    Statistic(string fileMvdMe, string fileMvdDe);

    void processMvdFiles();
    map<int, long long int> getOccMap(int idx);
    
private:

};

#endif	/* _STATISTIC_H */

