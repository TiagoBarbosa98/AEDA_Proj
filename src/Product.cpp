#include "Product.h"

Product::Product() {
	// TODO Auto-generated constructor stub

}

Product::~Product() {
	// TODO Auto-generated destructor stub
}

Product::Product(string n, string d, float p, float q, float iva, int c, bool m)
: name(n), description(d), price(p), quantity(q), iva(iva), code(c), medicine(m){}


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

bool Product::getMedicine() const{
	return medicine;
}
float Product::getQuantity() const{
	return quantity;
}
ostream& operator <<(ostream& os, const Product& p) {
	os << "Name: " << p.name << endl;
	os << "Code: " << p.code << endl;
	os << "Price: " << p.getTotalPrice() << endl; //TODO price or price + iva?
	os << "Description: " << p.description << endl;
	os << "Medicine: " << p.medicine << endl;

	return os;
}

bool Product::operator<(const Product &prod1) const {
    return (this->getQuantity() < prod1.getQuantity());
}

string Product::display() const {
	string out;
	out = "Name: " + name +
			"\nCode: " + to_string(code) +
			"\nPrice: " + to_string(getTotalPrice()) +
			"\nQuantity: " + to_string(quantity) +
			"\nDescription: " + description +
			"\nMedicine: " + med() + "\n";
	return out;
}

string Product::med() const {
	if(medicine)
		return "1";
	else
		return "0";
}
