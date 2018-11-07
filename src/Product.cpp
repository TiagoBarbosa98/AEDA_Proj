#include "Product.h"

Product::Product() {
	// TODO Auto-generated constructor stub

}

Product::~Product() {
	// TODO Auto-generated destructor stub
}

Product::Product(string n, string d, float p, float iva, int c)
: name(n), description(d), price(p), iva(iva), code(c){}


int Product::getCode() const {
	return code;
}

const string& Product::getDescription() const {
	return description;
}

float Product::getIva() const {
	return iva;
}

const string& Product::getName() const {
	return name;
}

float Product::getPrice() const {
	return price;
}

float Product::getTotalPrice() const{
	return price + price * iva;
}

ostream& operator <<(ostream& os, const Product& p) {
	os << "Name: " << p.name
	   << "\nCode: " << p.code
	   << "\nPrice: " << p.price //TODO price or price + iva?
	   << "\nDescription: " << p.description << endl;

	return os;
}
