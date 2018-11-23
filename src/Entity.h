#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>
#include <iostream>
#include <sstream>

using namespace std;
/*
 * @class Entity Class that represents a entity(can be a Person or a Pharmacy) where are stored the name and address
 */
class Entity{
	string name; /** < @brief name of the Entity */
	string address; /** < @brief address of the Entity */
public:
/**
 * @brief Construct a new Entity object
 * 
 * @param n The name of the Entity to be created
 * @param addr The adress of the Entity to be created
 */
	Entity(string n, string addr);

	/* get and set methods */

	/**
	 * @brief Get the Name object
	 * 
	 * @return string Entity's name
	 */
	string getName() const;
	/**
	 * @brief Get the Address object
	 * 
	 * @return string Entity's address
	 */
	string getAddress() const;
	/**
	 * @brief Get the Info object
	 * 
	 * @return string prints all the the Entity's information
	 */
	virtual string getInfo() const;
	/**
	 * @brief Set the Name object
	 * 
	 * @param nn new Entity's name
	 */
	void setName(string nn);
	/**
	 * @brief Set the Address object
	 * 
	 * @param naddr new Entity's address
	 */
	void setAddress(string naddr);
	/**
	 * @brief 
	 * 
	 * @param os 
	 * @param e 
	 * @return ostream& 
	 */
	friend ostream & operator <<(ostream &os, const Entity & e);
	
};



#endif /* ENTITY_H_ */
