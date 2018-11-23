#include "Client.h"

Client::Client(string n, string addr,  unsigned int  contribNo, vector<unsigned int> h):Person(n, addr, contribNo), history(h){}

vector<unsigned int> Client::getHistory(){
	return history;
}

ostream& operator <<(ostream& os, const Client& c) {
	const Person *p = &c;
	os << *p;
	os << "Purchases id's:\n";
	for(unsigned int i = 0; i < c.history.size(); i++){
		os <<"  -" << c.history[i] << endl;
	}
	return os;
}
