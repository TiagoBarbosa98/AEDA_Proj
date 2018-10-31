/*
 * Medicine.cpp
 *
 *  Created on: 30/10/2018
 *      Author: tiagobarbosa 
 */

#include "Medicine.h"

Medicine::Medicine() {
	// TODO Auto-generated constructor stub

}

Medicine::Medicine(string n, string desc, float p, float iva, int c, float disc, bool nr)
: Product(n, desc, p, iva, c), discount(disc), noReceipt(nr){}


float Medicine::getDiscount() const {
	return discount;
}

bool Medicine::isNoReceipt() const {
	return noReceipt;
}

Medicine::~Medicine() {
	// TODO Auto-generated destructor stub
}

ostream & operator << (ostream & os, const Medicine & m){
	const Product *l = &m;
	cout << *l;
	if(m.discount > 0){
		os << "Price with discount: " << m.getPrice() - m.getPrice() * m.discount << endl;
	}
	if(m.noReceipt)
		os << "This medicine can be bought without a receipt" << endl;
	else
		os << "This medicine cannot be bought without a receipt" << endl;
	return os;
}


