#include "Prescription.h"

Prescription::Prescription() {
	// TODO Auto-generated constructor stub

}

Prescription::Prescription(int n, string c, string d, vector<int> p)
: number(n), client(c), doctor(d), products(p){}

Prescription::~Prescription() {
	// TODO Auto-generated destructor stub
}

int Prescription::getNumber() const {
	return number;
}

vector<int> Prescription::getProducts() const {
	return products;
}

const string& Prescription::getClient() const {
	return client;
}

void Prescription::addProduct(int c){
	products.push_back(c);
}

ostream &operator<<(ostream &os, const Prescription &p){
	os << "Number: " << p.number <<
			"\nClient: " << p.client <<
			"\nDoctor who prescribed: " << p.doctor <<
			"\nProducts id's:\n";
	for(unsigned int i = 0; i < p.products.size(); i++){
		os << "  -" << p.products[i] << endl;
	}
	return os;
}
