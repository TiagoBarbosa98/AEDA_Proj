#ifndef SRC_SALE_H_
#define SRC_SALE_H_
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <tuple>
#include "Product.h"

using namespace std;

class Sale {
private:
	tm *date;
	static unsigned int lastCode;
	unsigned int code;
	vector<tuple<string , unsigned int, unsigned int>> prodPriceQtt;
public:
	Sale();
	virtual ~Sale();
	Sale(vector<tuple<string , unsigned int, unsigned int>> cart);
	//Getters and setters
	tm * getDate() const;
	unsigned int getCode() const;
	friend ostream & operator << (ostream & os,  Sale & s);
	void addProdPriceQtt(Product p, int qtt);
	string getInfo() const;
	//adds a new product to prodQtt

};

#endif /* SRC_SALE_H_ */
