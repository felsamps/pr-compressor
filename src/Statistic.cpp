#include <map>

#include "Statistic.h"

Statistic::Statistic(string fileMvdMe, string fileMvdDe) {
	this->fpMe = fopen(fileMvdMe.c_str(), "r");
	this->fpDe = fopen(fileMvdDe.c_str(), "r");

	this->xMe.clear();
	this->xDe.clear();
	this->yMe.clear();
	this->yDe.clear();
}

void Statistic::processMvdFiles() {
	/*Motion Estimation Mvd Counting*/
	while( !feof(this->fpMe) ) {
		int x, y;
		fscanf(this->fpMe, "%d %d", &x, &y);
		xMe[x] = ( xMe.find(x) == xMe.end() ) ?	1 :	xMe[x] + 1;
		yMe[y] = ( yMe.find(y) == yMe.end() ) ?	1 :	yMe[y] + 1;
		/*TODO: mean and std deviation*/
	}
	/*Disparity Estimation Mvd Counting*/
	while( !feof(this->fpDe) ) {
		int x, y;
		fscanf(this->fpDe, "%d %d", &x, &y);
		xDe[x] = ( xDe.find(x) == xDe.end() ) ?	1 :	xDe[x] + 1;
		yDe[y] = ( yDe.find(y) == yDe.end() ) ?	1 :	yDe[y] + 1;
		/*TODO: mean and std deviation*/
	}

	fclose(this->fpMe);
	fclose(this->fpDe);
}

map<int, long long int> Statistic::getOccMap(int idx) {
	return  (idx == X_ME) ? xMe : (idx == Y_ME) ? yMe : (idx == X_DE) ? xDe : yDe;
}