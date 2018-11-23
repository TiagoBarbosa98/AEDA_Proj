#ifndef PERSON_H_
#define PERSON_H_

#include "Entity.h"

using namespace std;
/*
 * @class Person Class that represents a Person where is stored the person's  tax number
 */
class Person:public Entity{
	unsigned int contribNo;/** < @brief tax number of the Person */
public:
/**
 * @brief Construct a new Person object
 * 
 * @param n The name of the Person to be created
 * @param addr The adress of the Person be created
 * @param contribNo The tax number of the Person to be created
 */
	Person(string n, string addr, unsigned int contribNo);
	/**
	 * @brief Get the Contrib No object
	 * 
	 * @return unsigned int person's tax number
	 */
	unsigned int getContribNo() const;
		/**
	 * @brief Get the Info object
	 * 
	 * @return string prints all the the Person's information
	 */
	virtual string getInfo() const;
	/**
	 * @brief compares two person's tax numbers
	 * 
	 * @param p person to compare to
	 * @return true if Person's tax number is equal to p's tax number
	 * @return false if Person's tax number ism't equal to p's tax number
	 */
	
	bool operator==(const Person & p);
	/**
	 * @brief compares two person's name
	 * 
	 * @param p person to compare to
	 * @return true if Person's name is alphabetical smaller than to p's name
	 * @return false if Person's name isn't alphabetical smaller than to p's name
	 */
	bool operator< (const Person & p);

	friend ostream& operator <<(ostream &os, const Person &p);
};


#endif /* PERSON_H_ */
