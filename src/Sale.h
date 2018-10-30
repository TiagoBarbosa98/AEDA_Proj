/*
 * Sale.h
 *
 *  Created on: 30/10/2018
 *      Author: tiagobarbosa
 */

#ifndef SRC_SALE_H_
#define SRC_SALE_H_
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sale {
private:
	int hour, min;
	//string -> product name; int -> product quantity
	vector<pair<string, int>> prodQtd;
public:
	Sale();
	virtual ~Sale();
	int getHour() const;
	int getMin() const;
	const vector<pair<string, int> >& getProdQtd() const;
};

#endif /* SRC_SALE_H_ */
