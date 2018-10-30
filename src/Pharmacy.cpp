#include "Pharmacy.h"

using namespace std;

Pharmacy::Pharmacy(string n, string addr):Entity(n, addr){}

Pharmacy::Pharmacy(string n, string addr, vector<StaffMember> sl): Entity(n, addr){
	this->staff = sl;
}

vector<StaffMember> Pharmacy::getStaff() const{
	return staff;
}

void Pharmacy::addStaff(StaffMember *p){
	staff.push_back(*p);
}

void Pharmacy::removeStaff(StaffMember s){
	for(vector<StaffMember>::iterator it = staff.begin(); it != staff.end(); it++){
		if((*it) == s) staff.erase(it);
	}
}



