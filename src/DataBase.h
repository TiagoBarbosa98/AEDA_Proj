#ifndef SRC_DATABASE_H_
#define SRC_DATABASE_H_
#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <fstream>
#include <set>
#include <queue>
#include <unordered_set>
#include <sstream>

#include "Product.h"
#include "Pharmacy.h"
#include "Client.h"
#include "StaffMember.h"
#include "Prescription.h"
#include "Sale.h"
/**
 * @brief 
 * 
 */
class DataBase {
private:
/**
 * @brief 
 * 
 */
	string productsFile, clientsFile, pharmaciesFile, staffFile;
	/**
	 * @brief 
	 * 
	 */
	vector<Product* > products;
	/**
	 * @brief 
	 * 
	 */
	vector<Client> clients;
/**
 * @brief 
 * 
 */
	vector<Pharmacy> pharmacies;
	/**
	 * @brief 
	 * 
	 */
	vector<StaffMember> staff;
	/**
	 * @brief 
	 * 
	 */
	vector<Prescription> prescriptions;
	/**
	 * @brief 
	 * 
	 */
	vector<Sale> sales;
public:
	DataBase();
	DataBase(string productsFile, string clientsFile, string pharmaciesFile, string staffFile);
	virtual ~DataBase();

	//Getters
	vector<Client> getClients() const;
	vector<Pharmacy> getPharmacies() const;
	const vector<Product*>& getProducts() const;
	vector<Prescription> getPrescriptions() const;
	vector<StaffMember> getStaff() const;
	void addClient();
	void addFarmacy();
	void addStaffMember();
	//adding elem to vector v
	template<class T>
	void addElement(T elem, vector<T> &v){
		v.push_back(elem);
	}

	void showAllClients();
	void showAllPharmacies();
	void showAllStaff();

	string readComplexString (istringstream &ss, char separate);
	void openproductsFile();
	void openClientsFile ();
	void openpharmaciesFile();
	void openstaffFile();
	void closeClientsFile();
	void closePharmaciesFile();
	void closeStaffFile();

};

class ErrorOpeningFile {
    string nameFile;
public:
    ErrorOpeningFile (string name) {
        nameFile = name;
    }
    string getFileName () {
        return nameFile;
    }
};


#endif /* SRC_DATABASE_H_ */
