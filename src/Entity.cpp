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
}

void Entity::setAddress(string naddr){
	this->address = naddr;
}

ostream & operator <<(ostream &os, const Entity & e){
	os << "Name: " << e.name << "\nAddress: " << e.address << endl;

	return os;
}
string Entity::getInfo() const{
stringstream ss;
ss << this->getName() << ", " << this->getAddress()<<'\n';
return ss.str();
}

