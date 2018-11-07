#include "Receipt.h"

Receipt::Receipt() {
	// TODO Auto-generated constructor stub

}

Receipt::Receipt(int n, string c, string d, vector<int> p)
: number(n), client(c), doctor(d), products(p){}

Receipt::~Receipt() {
	// TODO Auto-generated destructor stub
}

int Receipt::getNumber() const {
	return number;
}

vector<int> Receipt::getProducts() const {
	return products;
}

const string& Receipt::getClient() const {
	return client;
}

void Receipt::addProduct(int c){
	products.push_back(c);
}