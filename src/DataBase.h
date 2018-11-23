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

class DataBase {
private:
	string productsFile, clientsFile, pharmaciesFile, staffFile, salesFile;
	vector<Product* > products;
	vector<Client> clients;
	vector<Pharmacy> pharmacies;
	vector<StaffMember> staff;
	vector<Prescription> prescriptions;
	vector<Sale> sales;
public:
	DataBase();
	DataBase(string prodFile, string cliFile, string pharmFile, string staffFile);
	DataBase(string productsFile, string clientsFile, string pharmaciesFile, string staffFile, string salesFile);
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

	void readProductsFile();

	string readComplexString (istringstream &ss, char separate);
	void openproductsFile();
	void openClientsFile ();
	void openPharmaciesFile();
	void openStaffFile();
	void closeClientsFile();
	void closePharmaciesFile();
	void closeStaffFile();
	void closeSalesFile();

	//Utilities
	int checkForInt(){
		int input;
		cin >> input;
		while(cin.fail()){
			cout << "Your input is not a valid number, please try again.\n"
			cin >> input;
		}
		return input;
	}

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
