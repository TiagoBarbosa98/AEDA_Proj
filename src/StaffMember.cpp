#include "StaffMember.h"
#include "Person.h"

StaffMember::StaffMember(string n, string addr, unsigned int cN, unsigned int sal, string ph, string pos):Person(n, addr, cN) {
	salary = sal;
	pharmacy = ph;
	position = pos;
}

unsigned int StaffMember::getSalary() const{
	return salary;
}

string StaffMember::getPharmacy() const{
	return pharmacy;
}

string StaffMember::getPosition() const{
	return position;
}

void StaffMember::setPharmacy(string ph) {
	pharmacy = ph;
}

void StaffMember::setPosition(string pos){
	position = pos;
}

void StaffMember::setSalary(unsigned int ns){
	salary = ns;
}

string StaffMember::getInfo() const{
	stringstream ss;
	ss << Person::getInfo() << "salary: " << this->getSalary();
	ss << "pharmacy name: "<<  this->getPharmacy();
	ss << "position: " << this->getPosition();
	return ss.str();
}
