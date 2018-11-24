#ifndef PHARMACY_H_
#define PHARMACY_H_

#include <vector>
#include "Entity.h"
#include "StaffMember.h"

using namespace std;
/*
 * @class Pharmacy Class that represents a Pharmacy
 */
class Pharmacy: public Entity{
	string manager;/** < @brief Manager of the Pharmacy */
	vector<StaffMember> staff;/** < @brief Staff of the Pharmacy (all the members working in that Pharmacy) */
public:
/**
 * @brief Construct a new Pharmacy object
 * 
 * @param n The name of the Pharmacy to be created
 * @param addr The adress of the Pharmacy to be created
 * @param manager The manager of the Pharmacy to be created
 */
	Pharmacy(string n, string addr,string manager);
	/**
	 * @brief Construct a new Pharmacy object
	 * 
	 * @param n The name of the Pharmacy to be created
 	 * @param addr The adress of the Pharmacy to be created
	 * @param sl All of the staff members of the Pharmacy to be created
	 */
	Pharmacy(string n, string addr, string manager, vector<StaffMember> sl);

	/* get and set methods */

	/**
	 * @brief Get the Staff object
	 * 
	 * @return vector<StaffMember> the staff members of the Pharmacy
	 */
	vector<StaffMember> getStaff() const;
	/**
	 * @brief Get the Manager object
	 * 
	 * @return string the manager of the Pharmacy
	 */
	string getManager() const;
	/**
	 * @brief Get the Info object
	 * 
	 * @return string prints all the the Pharmacy's information
	 */
	string getInfo() const;
	/**
	 * @brief Set the Manager object
	 * 
	 * @param m new Pharmacy's manager
	 */
	void setManager(StaffMember m); //Manager has to exist in list
	
	/**
	 * @brief adds the Staff Member s the vector with all the Staff Members
	 * 
	 * @param s new Staff Member to be added
	 */
	void addStaff(StaffMember s);
	/**
	 * @brief removes the Staff Member s the vector with all the Staff Members
	 * 
	 * @param s Staff Member to be removed
	 */
	void removeStaff(StaffMember s);
	
	/**
	 * @brief Overload outstream operator << to write a Pharmacy to an outstream
	 * 
	 * @param    		os 		Outstream
	 * 
	 * @param 			p		Pharmacy to be written
	 * 
	 * @return     Outstream
	 */
	friend ostream & operator <<(ostream &os, const Pharmacy &p);

};

#endif /* PHARMACY_H_ */
