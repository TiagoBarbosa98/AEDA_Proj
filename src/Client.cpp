#include "Client.h"

Client::Client(string n, string addr,  unsigned int  contribNo):Person(n, addr, contribNo){}

vector<unsigned int> Client::getHistory(){
	return history;
}
