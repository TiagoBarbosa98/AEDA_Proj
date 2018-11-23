#ifndef CLIENT_H_
#define CLIENT_H_
#include <vector>
#include "Person.h"
#include "Client.h"
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
	Client(string n, string addr,  unsigned int  contribNo);
	/**
	 * @brief Get the History object
	 * 
	 * @return vector<unsigned int> Client's purchases history
	 */
	vector<unsigned int> getHistory();
	/**
	 * @brief Get the Info object
	 * 
	 * @return string prints all the the Clientsr's information
	 */
	string getInfo() const;

};


#endif /* CLIENT_H_ */
