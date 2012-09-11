#include <iostream>

#include "Statistic.h"


using namespace std;

int main(int argc, char* argv[]) {

	string fileMe(argv[1]);
	string fileDe(argv[2]);

	Statistic stats(fileMe, fileDe);
	stats.processMvdFiles();

	map<int, long long int> m = stats.getOccMap(X_ME);

}
