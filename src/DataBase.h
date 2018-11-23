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
#include "Medicine.h"

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
	void addProduct();

	void removeProduct();

	void showAllClients();
	void showAllProducts();
	void showAllPharmacies();
	void showAllStaff();

	void readProductsFile();

	string readComplexString (istringstream &ss, char separate);
	void openClientsFile ();
	void openPharmaciesFile();
	void openStaffFile();
	void openProductsFile();
	void openSalesFile();
	void writeToClientsFile();
	void writeToPharmaciesFile();
	void writeToStaffFile();
	void writeToSalesFile();
	void writeToProductsFile();

	string parse(string in);
	string parseStaff(string in);


	template<class T>
	void writeToFile(string fileName, vector<T> v){
		ofstream saveData;

		saveData.open(fileName, ios::out | ios::trunc);

		if (saveData.fail()){
			//TODOthrow ErrorOpeningFile (fileName);
		}

		for (unsigned int i = 0; i < v.size(); i++) {

			saveData << v[i] << endl;
		}
		saveData << endl;

		saveData.close();
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

class ItemDoesNotExist{
	string item;
public:
	ItemDoesNotExist(string i){
		item = i;
	}
	void printMsg(){
		cout << item << " does not exist in Database." << endl;
	}
};


#endif /* SRC_DATABASE_H_ */
