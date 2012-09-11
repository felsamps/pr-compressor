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

class Statistic {

private:
    FILE *fpMe, *fpDe;
    map<int, long long int> xMe, xDe;
    map<int, long long int> yMe, yDe;

public:
    Statistic(string fileMvdMe, string fileMvdDe);

    void processMvdFiles();
    map<int, long long int> getOccMap(int idx);
    
};

#endif	/* _STATISTIC_H */

