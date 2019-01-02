#include "Client.h"

Client::Client(string n, string dis, string addr,  unsigned int  contribNo, vector<unsigned int> h):Person(n, addr, contribNo), history(h), district(dis){}
Client::Client(): Person("", "", 0){
}

vector<unsigned int> Client::getHistory() const{
	return history;
}

ostream& operator <<(ostream& os, const Client& c) {
	const Person *p = &c;
	os << *p;
	os << "District: " << c.district << endl;
	os << "Purchases id's:\n";
	for(unsigned int i = 0; i < c.history.size(); i++){
		os <<"  -" << c.history[i] << endl;
	}
	return os;
}

bool Client::operator <(const Client &c) const{
	if(district != c.district)
		return district < c.district;
	else
		return this->getName() < c.getName();
}

bool Client::operator== (const Client & c) const{
	return this->getContribNo() == c.getContribNo();
}
string Client::getDistrict() const{
	return district;
}
