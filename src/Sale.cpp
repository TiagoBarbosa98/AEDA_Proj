#include "Sale.h"
#include "Medicine.h"
#include <sstream>

unsigned int Sale::lastCode = 0;

Sale::Sale():code(++lastCode){
	// TODO Auto-generated constructor stub
	time_t now = time(0);
	date = localtime(&now);

}

Sale::Sale(vector<tuple<string , unsigned int, unsigned int>>cart):code(++lastCode){
	time_t now = time(0);
	date = localtime(&now);
	prodPriceQtt = cart;
}


tm * Sale::getDate() const{
	return date;
}


unsigned int Sale::getCode() const{
	return code;
}

void Sale::addProdPriceQtt(Product p, int q){
	tuple<string, unsigned int, unsigned int> t(p.getName(), q*p.getPrice(), q);
	prodPriceQtt.push_back(t);
}

ostream & operator << (ostream & os, Sale & m){
	os << "Sale Number: " << m.code << endl;
	os << "Date: " << m.date->tm_mday << "/" << m.date->tm_mon + 1 << "/" << 1900 + m.date->tm_year << " ";
	if (m.date->tm_hour < 10) os << "0";
	os << m.date->tm_hour << ":";
	if(m.date->tm_min < 0) os << "0";
	os << m.date->tm_min << endl;
	os << "Products: " << endl;
	for(unsigned int i = 0; i < m.prodPriceQtt.size(); i++){
		os << "Product: "<< get<0>(m.prodPriceQtt.at(i)) << " Quantity: " << get<2>(m.prodPriceQtt.at(i))  <<  " Total Price: " <<  get<1>(m.prodPriceQtt.at(i)) << endl;
	}
	os << endl;
	return os;
}


