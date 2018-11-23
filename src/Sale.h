#ifndef SRC_SALE_H_
#define SRC_SALE_H_
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Product.h"

using namespace std;

class Sale {
private:
	tm *date;
	static unsigned int lastCode;
	unsigned int code;
	vector<pair<Product *, unsigned int>> prodQtt;
public:
	Sale();
	virtual ~Sale();
	Sale(vector<pair<Product *, unsigned int>> cart);
	//Getters and setters
	tm * getDate() const;
	unsigned int getCode() const;
	const vector<pair<Product *, unsigned int> >& getProdQtt() const;
	friend ostream & operator << (ostream & os,  Sale & s);
	void addProdQtt(Product * p, int qtt);
	//adds a new product to prodQtt

};

#endif /* SRC_SALE_H_ */
