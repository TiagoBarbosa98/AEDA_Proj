#include <iostream>
#include <vector>
#include "Entity.h"
#include "Person.h"
#include "StaffMember.h"
#include "Pharmacy.h"
using namespace std;

int main() {
	StaffMember p("João Vitor", "CDUP", 420, 420000, "Dos Queijos", "Baws");
	StaffMember q("Maria Leal", "Hell", 0, 6969, "Dos Queijos", "Cantora?");
	vector<StaffMember> s; s.push_back(p); s.push_back(q);
	Pharmacy f("Dos Queijos", "FEUP", s);
	cout <<"Pharmacy: " << f.getName() << endl;
	cout << "Address: " << f.getAddress() << endl;
	cout << "Staff: " << endl;
	for(unsigned int i = 0; i != f.getStaff().size(); i++)
		cout << f.getStaff().at(i).getName() << endl;

	return 0;
}
