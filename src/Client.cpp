#include "Client.h"

Client::Client(string n, string addr,  unsigned int  contribNo):Person(n, addr, contribNo){}

vector<unsigned int> Client::getHistory(){
	return history;
}

ostream& operator <<(ostream& os, const Client& c) {
	const Person *p = &c;
	os << *p;
	os << "Purchases made:\n";
	for(unsigned int i = 0; i < c.history.size(); i++){
		os << c.history[i] << endl;
	}
	return os;
}
