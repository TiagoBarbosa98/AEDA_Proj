#include "Medicine.h"
#include "Product.h"

Medicine::Medicine() {
	// TODO Auto-generated constructor stub

}

Medicine::Medicine(string n, string desc, float p, float iva, int c, float disc, bool nr)
: Product(n, desc, p, iva, c, true), discount(disc), prescription(nr){}


float Medicine::getDiscount() const {
	return discount;
}

float Medicine::getPriceWithDiscount() const{
	return getPrice() - getDiscount()*getPrice();
}


bool Medicine::prescriptionRequired() const {
	return prescription;

}

ostream & operator << (ostream & os, const Medicine & m){
	const Product *l = &m;
	os << *l;
	if(m.discount > 0){
		os << "Discount: " << m.discount << endl;
	}
	os << "Prescription Required: " << m.prescriptionRequired() << endl;
	return os;
}

string Medicine::display() const {
	string out = Product::display();
	out = out + "Discount: " + 	to_string(discount) + "\nPrescription Required: " + prescr() + "\n";
	return out;
}

string Medicine::prescr() const {
	if(prescription){
		return "1";
	}
	else
		return "0";
}
