#include "Pharmacy.h"

using namespace std;

Pharmacy::Pharmacy(string n, string addr, string manager):Entity(n, addr){
	this->manager=manager;
}

Pharmacy::Pharmacy(string n, string addr, string manager, vector<StaffMember*> sl): Entity(n, addr){
	this->staff = sl;
	this->manager = manager;
}

vector<StaffMember*> Pharmacy::getStaff() const{
	return staff;
}

void Pharmacy::addStaff(StaffMember *p){
	staff.push_back(p);
}

void Pharmacy::removeStaff(StaffMember s){
	for(vector<StaffMember*>::iterator it = staff.begin(); it != staff.end(); it++){
		if(*(*it) == s){
			//*it->setPharmacy("None");
			staff.erase(it);
		}
	}
}

bool Pharmacy::removeStaff(string name){

	for(unsigned int i = 0; i < staff.size(); i++){
		if(staff[i]->getName() == name){
			staff.erase(staff.begin() + i);
			return true;
		}
	}
	return false;
}

string Pharmacy::getManager() const{
	return manager;
}


ostream & operator <<(ostream &os, const Pharmacy &p){
	const Entity *e = &p;
	os << *e;
	os << "Manager: " << p.manager
		 << "\nStaff: \n";
	for(unsigned int i = 0; i < p.staff.size(); i++){
		os << "  -" << p.staff[i]->getName() << endl;
	}

	return os;
}

bool Pharmacy::operator ==(const Pharmacy &p) const{
	return this->getName() == p.getName();
}

void Pharmacy::setStaffPhToNone() {
	for(unsigned int i = 0; i < staff.size(); i++){
		staff[i]->setPharmacy("None");
	}
}

bool Pharmacy::containsStaff(string name) {
	for(unsigned int i = 0; i < staff.size(); i++){
		if(name == staff[i]->getName())
			return true;
	}
	return false;
}
