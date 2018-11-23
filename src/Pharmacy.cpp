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

void Pharmacy::addStaff(StaffMember p){
	staff.push_back(p);
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
	printVector(staff);
	return ss.str();
}



ostream & operator <<(ostream &os, const Pharmacy &p){
	const Entity *e = &p;
	os << *e;
	os << "Manager: " << p.manager
		 << "\nStaff: \n";
	for(unsigned int i = 0; i < p.staff.size(); i++){
		os << "  -" << p.staff[i].getName() << endl;
	}

	return os;
}

istream & operator >>(istream &is, Pharmacy &p){
	string line;
	getline(is, line);
	istringstream iss(line);
	return is;
}
