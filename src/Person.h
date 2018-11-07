#ifndef PERSON_H_
#define PERSON_H_

#include "Entity.h"

using namespace std;

class Person:public Entity{
	unsigned int contribNo;
public:
	Person(string n, string addr, unsigned int contribNo);
	unsigned int getContribNo() const;
	bool operator==(const Person & p);
	bool operator< (const Person & p);
	virtual string getInfo() const;
};


#endif /* PERSON_H_ */
