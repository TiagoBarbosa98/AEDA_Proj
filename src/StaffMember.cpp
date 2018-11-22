#include "StaffMember.h"
#include "Person.h"

StaffMember::StaffMember(string n, string addr, unsigned int cN, unsigned int sal, string ph, string pos):Person(n, addr, cN) {
	salary = sal;
	pharmacy = ph;
	position = pos;
}

StaffMember::StaffMember(): Person("www", "wqq", 221){
	salary = 0;
	pharmacy = "w";
	position = "d";
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

ostream& operator<<(ostream &os, const StaffMember &s){
	const Person *p = &s;
	os << *p;
	os << "Salary: " << s.salary
	   << "\nWorks for: " << s.pharmacy << " Pharmacy"
	   << "\nWorks as: " << s.position << endl;

	return os;
}
