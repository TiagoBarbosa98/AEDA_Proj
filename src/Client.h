#ifndef CLIENT_H_
#define CLIENT_H_
#include <vector>
#include "Person.h"
#include "Client.h"
#include <iostream>
#include <fstream>

using namespace std;

class Person;

class Client:  public Person{
	vector<unsigned int> history;
public:
	Client(string n, string addr,  unsigned int  contribNo);
	vector<unsigned int> getHistory();
	string getInfo() const;

};


#endif /* CLIENT_H_ */
