#ifndef CLIENT_H_
#define CLIENT_H_
#include <vector>
#include "Person.h"
#include "Client.h"

using namespace std;

class Client:  public Person{
	vector<unsigned int> history;
public:
	Client(string n, string addr, string contribNo):Person(n, addr, contribNo){};
	vector<unsigned int> getHistory(){return history;};

};


#endif /* CLIENT_H_ */
