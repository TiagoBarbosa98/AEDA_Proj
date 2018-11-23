#ifndef STAFFMEMBER_H_
#define STAFFMEMBER_H_

#include "Person.h"

using namespace std;
/*
 * @class StaffMember Class that represents a staff member from a pharmacy where are stored is salary and the position in that pharmacy
 */
class StaffMember: public Person{
	unsigned int salary;/** < @brief Salary of the Staff Member */
	string pharmacy; /** < @brief Pharmacy where the Staff Member works */
	string position;/** < @brief Position of the  Staff Member in the Pharmacy */
public:
/**
 * @brief Construct a new Staff Member object
 * 
	 * @param n The name of the Staff Member to be created
	 * @param addr The adress of the Staff Member to be created
	 * @param contribNo The tax number of the Staff Member to be created
	 * @param sal The Salary of the Staff Member to be created
	 * @param ph The Pharmacy where the Staff Member to be created works
	 * @param pos The Position of the Staff Member to be created
 */
	StaffMember(string n, string addr, unsigned int contribNo, unsigned int sal , string ph, string pos);
	StaffMember();

	/* get and set methods */

	/**
	 * @brief Get the Salary object
	 * 
	 * @return unsigned int Staff Member's Salary
	 */
	unsigned int getSalary() const;
	/**
	 * @brief Get the Pharmacy object
	 * 
	 * @return string Staff Member's Pharmacy
	 */
	string getPharmacy() const;
	/**
	 * @brief Get the Position object
	 * 
	 * @return string Staff Member's Position
	 */
	string getPosition() const;
	/**
	 * @brief Get the Info object
	 * 
	 * @return string prints all the the Staff Member's information
	 */
	string getInfo() const;
	/**
	 * @brief Set the Salary object
	 * 
	 * @param ns new Staff Member's Salary
	 */
	void setSalary(unsigned int ns);
	/**
	 * @brief Set the Pharmacy object
	 * 
	 * @param ph new Staff Member's Pharmacy
	 */
	void setPharmacy(string ph);
	/**
	 * @brief Set the Position object
	 * 
	 * @param pos new Staff Member's Position
	 */
	void setPosition(string pos);

	friend ostream& operator<<(ostream &os, const StaffMember &s);
};



#endif /* STAFFMEMBER_H_ */
