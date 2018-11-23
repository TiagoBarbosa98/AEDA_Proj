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
	friend ostream& operator <<(ostream &os, const Person &p);
	void setNc(unsigned int Nc){
		this->contribNo = Nc;
	}
};


#endif /* PERSON_H_ */
