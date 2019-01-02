#ifndef CLIENT_H_
#define CLIENT_H_
#include <vector>
#include "Person.h"
#include "Client.h"
#include "Sale.h"
#include "BST.h"
#include <iostream>
#include <fstream>

using namespace std;

class Person;

/*
 * @class Client Class that represents a client
 */
class Client:  public Person{
	vector<unsigned int> history; /** < @brief history of Clients purchases */
	string district;
public:
/**
 * @brief Construct a new Client object
 *
 * @param n The name of the Client be created
 * @param addr The adress the Client be created
 * @param contribNo The tax number of the Client to be created
 */
 Client(string n, string dis, string addr,  unsigned int  contribNo, vector<unsigned int> history);
 Client();
	/**
	 * @brief      Get the History object
	 *
	 * @return     vector<unsigned int> Client's purchases history
	 */
	vector<unsigned int> getHistory() const;

	/**
	 * @brief 		Overload outstream operator << to write a Client to an outstream
	 *
	 * @param 		os 		Outstream
	 *
	 * @param 		c 		Client to be written
	 *
	 * @return outstream
	 */
	friend ostream& operator <<(ostream& os, const Client& c);

	bool operator <(const Client &c) const;

	bool operator== (const Client & c) const;

	string getDistrict() const;
};



#endif /* CLIENT_H_ */
