#ifndef PHARMACY_H_
#define PHARMACY_H_

#include <vector>
#include "Entity.h"
#include "StaffMember.h"

using namespace std;

class Pharmacy: public Entity{
	vector<StaffMember> staff;
public:
	Pharmacy(string n, string addr);
	Pharmacy(string n, string addr, vector<StaffMember> sl);
	vector<StaffMember> getStaff() const;
	void addStaff(StaffMember *s);
	void removeStaff(StaffMember s);
	void setManager(StaffMember m); //Manager has to exist in list
};

#endif /* PHARMACY_H_ */
