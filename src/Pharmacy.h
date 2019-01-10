#ifndef PHARMACY_H_
#define PHARMACY_H_

#include <vector>
#include "Entity.h"
#include "StaffMember.h"

using namespace std;

/**
 * @brief Pharmacy Class that represents a Pharmacy
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
	//vector<StaffMember*> getStaff() const;
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
	 * @brief Sets the manager variable to a new one
	 * 
	 * @param name Name of the new manager
	 */
	void setManager(string name); //Manager has to exist in list
	
	/**
	 * @brief adds the Staff Member s the vector with all the Staff Members
	 * 
	 * @param s new Staff Member to be added
	 */
	//void addStaff(StaffMember *s);
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

	/**
	* @brief Compares two pharmacies and
	*
	* @param p Pharmacy to be compared with
	*
	* @return Boolean value of whether they're equal or not
	*/
	bool operator ==(const Pharmacy &p) const;

	/**
	* @brief Sets the pharmacy variable of the StaffMember 's from this
	* pharmacy to None. Used when deleting a Pharmacy
	*/
	void setStaffPhToNone();

	/**
	 * @brief Removes a certain StaffMember from this pharmacy
	 *
	 * @param name Name of the staff to be removed
	 *
	 * @return Boolean value of whether it was removed or not
	 */
	bool removeStaff(string name);

	/**
	 * @brief Checks if a StaffMember with a certain name exists in
	 * this Pharmacy
	 *
	 * @param name Name of the staff to be checked
	 *
	 * @return Boolean value of whether it contains the StaffMember or not
	 */
	bool containsStaff(string name);

	/**
	 * @brief Displays the names of the StaffMember 's from this Pharmacy
	 */
	void showStaffsName();

};

#endif /* PHARMACY_H_ */
