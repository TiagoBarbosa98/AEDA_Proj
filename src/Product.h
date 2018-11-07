#ifndef SRC_PRODUCT_H_
#define SRC_PRODUCT_H_
#include <iostream>
#include <string>
using namespace std;

class Product {
private:
	string name, description;
	float price, iva;
	int code;

public:
	Product();
	Product(string name, string description, float price, float iva, int code);
	virtual ~Product();

	//Getters And Setters
	int getCode() const;
	const string& getDescription() const;
	float getIva() const;
	const string& getName() const;
	float getPrice() const;
	friend ostream & operator << (ostream & os, const Product & p);
	float getTotalPrice() const;

};



#endif /* SRC_PRODUCT_H_ */
