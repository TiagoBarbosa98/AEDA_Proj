#include "Client.h"

Client::Client(string n, string addr,  unsigned int  contribNo):Person(n, addr, contribNo){}

vector<unsigned int> Client::getHistory(){
	return history;
}

string Client::getInfo() const{
	stringstream ss;
	ss << Person::getInfo();
	return ss.str();
}

