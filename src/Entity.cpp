#include "Entity.h"

Entity::Entity(string n, string addr){
	name = n;
	address = addr;
}

string Entity::getAddress() const{
	return address;
}

string Entity::getName() const{
	return name;
}

void Entity::setName(string nn){
	this->name = nn;
	cout << "New name set!\n";
}

void Entity::setAddress(string naddr){
	this->address = naddr;
	cout << "New address set!\n";
}

ostream & operator <<(ostream &os, const Entity & e){
	os << "Name: " << e.name << "\nAddress: " << e.address << endl;

	return os;
}

