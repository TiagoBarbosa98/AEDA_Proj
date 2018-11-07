#ifndef SRC_SALE_H_
#define SRC_SALE_H_
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sale {
private:
	int hour, min;
	//int -> product code; int -> product quantity
	vector<pair<int, int>> prodQtt;
public:
	Sale();
	virtual ~Sale();

	//Getters and setters
	int getHour() const;
	int getMin() const;
	const vector<pair<int, int> >& getProdQtt() const;

	//adds a new product to prodQtt
	//void addProdQtt(int code, int qtt);

};

#endif /* SRC_SALE_H_ */
