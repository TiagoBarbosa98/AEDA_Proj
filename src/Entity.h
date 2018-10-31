#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>
#include <iostream>

using namespace std;

class Entity{
	string name;
	string address;
public:
	Entity(string n, string addr);
	string getName() const;
	string getAddress() const;
	void setName(string nn);
	void setAddress(string naddr);
	friend ostream & operator <<(ostream &os, const Entity & e);
};



#endif /* ENTITY_H_ */
