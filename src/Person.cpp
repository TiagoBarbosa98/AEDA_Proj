#include "Person.h"

Person::Person(string n, string addr, unsigned int contribNo):Entity(n, addr){
	this->contribNo = contribNo;
}

unsigned int Person::getContribNo() const{
	return contribNo;
}

bool Person::operator ==(const Person & p){
	return contribNo == p.getContribNo();
}

bool Person::operator< (const Person & p){
	return getName() < p.getName();
}

ostream& operator <<(ostream &os, const Person &p){
	const Entity *e = &p;
	os << *e;
	os << "Identification number: " << p.contribNo << endl;
	return os;
}
