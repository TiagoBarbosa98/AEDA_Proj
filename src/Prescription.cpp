#include "Prescription.h"

Prescription::Prescription() {
	// TODO Auto-generated constructor stub

}

Prescription::Prescription(int n, string c, string d, string p)
: number(n), client(c), doctor(d), product(p){}

Prescription::~Prescription() {
	// TODO Auto-generated destructor stub
}

int Prescription::getNumber() const {
	return number;
}

string Prescription::getProduct() const {
	return product;
}

const string& Prescription::getClient() const {
	return client;
}

void Prescription::setProduct(string c){
	product = c;
}

void Prescription::setClient(string c){
	client = c;
}

void Prescription::setDr(string dr){
	doctor = dr;
}

ostream & operator <<(ostream &os, const Prescription &p){
	os << "Number: " << p.number << endl;
	os << p.doctor << endl;
	os << "Pacient: " << p.client << endl;
	os << "For: "<< p.product << endl;
}
