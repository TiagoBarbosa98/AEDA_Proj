#include "Sale.h"
#include "Medicine.h"

unsigned int Sale::lastCode = 0;

Sale::Sale():code(++lastCode){
	// TODO Auto-generated constructor stub
	time_t now = time(0);
	date = localtime(&now);

}

Sale::Sale(vector<pair<Product *, unsigned int>> cart):code(++lastCode){
	time_t now = time(0);
	date = localtime(&now);
	prodQtt = cart;
}


tm * Sale::getDate() const{
	return date;
}

unsigned int Sale::getCode() const{
	return code;
}

const vector<pair<Product *, unsigned int> >& Sale::getProdQtt() const {
	return prodQtt;
}


void Sale::addProdQtt(Product * p, int q){
	pair<Product *, unsigned int> prod(p, q);
	prodQtt.push_back(prod);
}

ostream & operator << (ostream & os, Sale & m){
	os << "Sale Number: " << m.code << endl;
	os << "Date: " << m.date->tm_mday << "/" << m.date->tm_mon + 1 << "/" << 1900 + m.date->tm_year << " ";
	if (m.date->tm_hour < 10) os << "0";
	os << m.date->tm_hour << ":";
	if(m.date->tm_min < 0) os << "0";
	os << m.date->tm_min << endl;
	os << "Products: " << endl;
	for (vector<pair<Product  *, unsigned int>>::iterator it = m.prodQtt.begin(); it != m.prodQtt.end(); it++){
		os << (*it).first->getName() << " " << (*it).second << endl;
		os << "Price: " << (*it).first->getTotalPrice() << endl;
		if((*it).first->getMedicine()){
			os << "Price After Discount: " << " " <<  static_cast<Medicine *>(it->first)->getPriceWithDiscount() << endl;
		}
	}
	os << endl;
	return os;
}

Sale::~Sale() {
	// TODO Auto-generated destructor stub
}

