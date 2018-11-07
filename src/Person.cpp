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

string Person::getInfo() const{
	stringstream ss;
	ss << Entity::getInfo() << ", " << this->getContribNo();
	return ss.str();
}
