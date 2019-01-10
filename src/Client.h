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

/**
 * @brief Client Class that represents a client
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
 Client(unsigned int nc);
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

	/**
	 * @brief Operator overload of <
	 *
	 * @param c Client to compare this object to
	 *
	 * @return Boolean value -> true if this object is "smaller" than the other one
	 */
	bool operator <(const Client &c) const;

	/**
	 * @brief Operator overload of ==
	 *
	 * @param c Client to compare this object to
	 *
	 * @return Boolean value -> true if both objects are equal
	 */
	bool operator== (const Client & c) const;

	/**
	 * @brief Get function of the variable district
	 *
	 * @return The district name
	 */
	string getDistrict() const;
};



#endif /* CLIENT_H_ */
