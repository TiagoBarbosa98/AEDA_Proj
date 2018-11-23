#include "Prescription.h"

Prescription::Prescription() {
	// TODO Auto-generated constructor stub

}

Prescription::Prescription(int n, string c, string d, vector<string> p)
: number(n), client(c), doctor(d), products(p){}

Prescription::~Prescription() {
	// TODO Auto-generated destructor stub
}

int Prescription::getNumber() const {
	return number;
}

vector<string> Prescription::getProducts() const {
	return products;
}

const string& Prescription::getClient() const {
	return client;
}

const string& Prescription::getDoctor() const{
	return doctor;
}

void Prescription::addProduct(string c){
	products.push_back(c);
}

ostream & operator<< (ostream & os, Prescription const & s){
	os << "Prescription no: " << s.getNumber() << endl;
	os << "Client: " << s.getClient() << endl;
	os << "Doctor: " << s.getDoctor() << endl;
	os << "Products: " << endl;
	for(unsigned int i = 0; i < s.getProducts().size(); i++)
		os << s.getProducts()[i] << endl;
	return os;
}
