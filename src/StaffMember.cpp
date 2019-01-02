#include "StaffMember.h"
#include "Person.h"

StaffMember::StaffMember(string n, string addr, unsigned int contribNo, unsigned int sal , string ph, string pos):Person(n, addr, contribNo) {
	salary = sal;
	pharmacy = ph;
	position = pos;
}

StaffMember::StaffMember(): Person("error", "error", 60), salary(1), pharmacy("error"), position("error"){

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


ostream& operator<<(ostream &os, const StaffMember &s){
	const Person *p = &s;
	os << *p;
	os << "Salary: " << s.salary
	   << "\nWorks for: " << s.pharmacy
	   << "\nWorks as: " << s.position << endl;

	return os;
}
/*
istream& operator>>(istream &is, StaffMember &s){
	string name, address, salary, pharmacy, pos, id, garbage;
	string name2, address2, salary2, pharmacy2, pos2, id2;
	getline(is, name);
	getline(is, address);
	getline(is, salary);
	getline(is, pharmacy);
	getline(is, pos);

	istringstream iss1(name);
	istringstream iss2(address);
	istringstream iss3(salary);
	istringstream iss4(pharmacy);
	istringstream iss5(pos);
	istringstream iss6(id);

	getline(iss1, garbage, ' ');
	getline(iss1, name2);

	getline(iss2, garbage, ' ');
	getline(iss2, address2);

	getline(iss6, garbage, ' ');
	getline(iss6, id2);

	getline(iss3, garbage, ' ');
	getline(iss3, salary2);

	getline(iss4, garbage, ' ');
	getline(iss4, pharmacy2);

	getline(iss5, garbage, ' ');
	getline(iss5, pos2);

	int sal = stoi(salary2);
	int nc = stoi(id2);

	s.setAddress(address2);
	s.setName(name2);
	s.setPharmacy(pharmacy2);
	s.setPosition(pos2);
	s.setSalary(sal);
	s.setNc(nc);

	return is;
}*/
