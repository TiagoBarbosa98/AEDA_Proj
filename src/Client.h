#ifndef CLIENT_H_
#define CLIENT_H_
#include <vector>
#include "Person.h"
#include "Client.h"
#include "Sale.h"
#include <iostream>
#include <fstream>

using namespace std;

class Person;

/*
 * @class Client Class that represents a client
 */
class Client:  public Person{
	vector<unsigned int> history; /** < @brief history of Clients purchases */
public:
/**
 * @brief Construct a new Client object
 *
 * @param n The name of the Client be created
 * @param addr The adress the Client be created
 * @param contribNo The tax number of the Client to be created
 */
 Client(string n, string addr,  unsigned int  contribNo, vector<unsigned int> history);
	/**
	 * @brief      Get the History object
	 *
	 * @return     vector<unsigned int> Client's purchases history
	 */
	vector<unsigned int> getHistory();
	
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

};


#endif /* CLIENT_H_ */
