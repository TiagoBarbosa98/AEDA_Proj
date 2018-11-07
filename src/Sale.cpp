#include "Sale.h"

Sale::Sale() {
	// TODO Auto-generated constructor stub

}

int Sale::getHour() const {
	return hour;
}

int Sale::getMin() const {
	return min;
}

const vector<pair<int, int> >& Sale::getProdQtt() const {
	return prodQtt;
}

Sale::~Sale() {
	// TODO Auto-generated destructor stub
}
/*
void Sale::addProdQtt(int c, int q){
	pair<c, q> prod;
	prodQtt.push_back(prod);
}*/

