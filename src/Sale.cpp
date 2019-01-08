#include "Sale.h"
#include "Medicine.h"
#include <sstream>

unsigned int Sale::lastCode = 0;

Sale::Sale():code(++lastCode){
	// TODO Auto-generated constructor stub
	time_t now = time(0);
	date = 0;
	price = 0;

}

Sale::Sale(vector<tuple<string, unsigned int, float>>cart):code(++lastCode){
	time_t now = time(0);
	date = 0;
	prodPriceQtt = cart;
	this->price = 0;
}

Sale::Sale(tm* time, vector<tuple<string, unsigned int, float> > cart, float price):code(++lastCode) {
	this->date = time;
	prodPriceQtt = cart;
	this->price = price;
}


tm * Sale::getDate() const{
	return date;
}


unsigned int Sale::getCode() const{
	return code;
}

void Sale::addProdPriceQtt(Product p, int q){
	tuple<string, unsigned int, float> t(p.getName(), q, q*p.getPrice());
	prodPriceQtt.push_back(t);
	price += q*p.getPrice();
}

ostream & operator << (ostream & os, Sale & m){
	os << "Sale Number: " << m.code << endl;
	os << "Date: " << m.date->tm_mday << "/" << m.date->tm_mon + 1 << "/" << 1900 + m.date->tm_year << " ";
	if (m.date->tm_hour < 10) os << "0";
	os << m.date->tm_hour << ":";
	if(m.date->tm_min < 0) os << "0";
	os << m.date->tm_min << endl;
	os << "Price: " << m.price << endl;
	os << "Products: " << endl;
	for(unsigned int i = 0; i < m.prodPriceQtt.size(); i++){
		os << "-Product: "<< get<0>(m.prodPriceQtt.at(i)) << ", Quantity: " << get<2>(m.prodPriceQtt.at(i))  <<  ", Total Price: " <<  get<1>(m.prodPriceQtt.at(i)) << endl;
	}
	return os;
}

string Sale::display(){
	string out;

	out = out + "Sale Number: " + to_string(code) + "\n" +
			"Date: " + to_string(date->tm_mday) + "/" + to_string(date->tm_mon + 1) + "/" + to_string(1900) + to_string(date->tm_year) + " ";
	if (date->tm_hour < 10) out = out + "0";
		out + to_string(date->tm_hour) + ":";
	if(date->tm_min < 0) out = out + "0";
	out = out + to_string(date->tm_min) + "\n";
	out = out + "Price: " + to_string(price) + "\n";
	out = out + "Products: \n";
	for(unsigned int i = 0; i < prodPriceQtt.size(); i++){
			out = out + "-Product: " +get<0>(prodPriceQtt.at(i)) + ", Quantity: " + to_string(get<1>(prodPriceQtt.at(i)))  +  ", Total Price: " + to_string(get<2>(prodPriceQtt.at(i))) + "\n";
		}

	return out;
}


