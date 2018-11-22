#ifndef PHARMACY_H_
#define PHARMACY_H_

#include <vector>
#include "Entity.h"
#include "StaffMember.h"
#include "PrintsNSorts.h"

using namespace std;

class Pharmacy: public Entity{
	string manager;
	vector<StaffMember> staff;
public:
	Pharmacy(string n, string addr,string manager);
	Pharmacy(string n, string addr, vector<StaffMember> sl);
	vector<StaffMember> getStaff() const;
	string getInfo() const;
	void addStaff(StaffMember s);
	void removeStaff(StaffMember s);
	string getManager() const;
	void setManager(StaffMember m); //Manager has to exist in list
	friend ostream & operator <<(ostream &os, const Pharmacy &p);
};

#endif /* PHARMACY_H_ */
