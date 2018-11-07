#include "Pharmacy.h"

using namespace std;

Pharmacy::Pharmacy(string n, string addr, string manager):Entity(n, addr){
	this->manager=manager;
}

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

string Pharmacy::getManager() const{
	return manager;
}

string Pharmacy::getInfo() const{
	stringstream ss;
	ss << Entity::getInfo() << ", " << this->getManager();
	return ss.str();
}
