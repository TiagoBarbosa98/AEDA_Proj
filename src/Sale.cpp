/*
 * Sale.cpp
 *
 *  Created on: 30/10/2018
 *      Author: tiagobarbosa 
 */

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

const vector<pair<string, int> >& Sale::getProdQtd() const {
	return prodQtd;
}

Sale::~Sale() {
	// TODO Auto-generated destructor stub
}

