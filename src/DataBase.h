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
#include "PrintsNSorts.h"
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
	string productsFile, clientsFile, pharmaciesFile, staffFile, salesFile, prescriptionsFile;
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
	DataBase(string productsFile, string clientsFile, string pharmaciesFile, string staffFile, string salesFile);
	virtual ~DataBase();

	//Getters
	vector<Client> getClients() const;
	vector<Pharmacy> getPharmacies() const;
	const vector<Product*>& getProducts() const;
	vector<Prescription> getPrescriptions() const;
	vector<StaffMember> getStaff() const;
	void addClient();
	void addPharmacy();
	void addStaffMember();
	void addProduct();
	void addSale();
	void addPrescription();

	void writeToProductsFile();
	void writeToPharmaciesFile();
	void writeToClientsFile();
	void writeToStaffFile();
	void writeToSalesFile();

	void removeProduct();
	void removeClient();
	void removeSale();
	void removeStaffMember();
	void removePharmacy();

	Product getProductByName(string name) const;
	//adding elem to vector v
	template<class T>
	void addElement(T elem, vector<T> &v){
		v.push_back(elem);
	}

	void showAllClients();
	void showAllPharmacies();
	void showAllStaff();
	void showAllSales();
	void showAllPrescriptions();
	void showAllProducts();

	void readProductsFile();

	string readComplexString (istringstream &ss, char separate);
	void openproductsFile();
	void openClientsFile ();
	void openpharmaciesFile();
	void openstaffFile();
	void closeClientsFile();
	void closePharmaciesFile();
	void closeStaffFile();
	string parse(string in);
	//string parseStaf

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

class ItemDoesNotExist{
	string item;
public:
	ItemDoesNotExist(string n){item = n;}
	void printMsg(){cout << item << " does not exist in Database.";}
};

#endif /* SRC_DATABASE_H_ */
