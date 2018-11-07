#ifndef STAFFMEMBER_H_
#define STAFFMEMBER_H_

#include "Person.h"

using namespace std;

class StaffMember: public Person{
	unsigned int salary;
	string pharmacy;
	string position;
public:
	StaffMember(string n, string addr, unsigned int contribNo, unsigned int sal , string ph, string pos);
	unsigned int getSalary() const;
	string getPharmacy() const;
	string getPosition() const;
	void setSalary(unsigned int ns);
	void setPharmacy(string ph);
	void setPosition(string pos);
};



#endif /* STAFFMEMBER_H_ */