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
	void addPharmacy();
	void addStaffMember();
	void addSale();
	void addPrescription();
	void addProduct();

	void removeProduct();
	void removeSale();
	void removeClient();
	void removePharmacy();
	void removeStaffMember();

	void showAllClients();
	void showAllPharmacies();
	void showAllStaff();
	void showAllSales();
	void showAllPrescriptions();
	void showAllProducts();

	void readProductsFile();

	Product getProductByName(string name) const;

	void openClientsFile ();
	void openPharmaciesFile(); //
	void openStaffFile(); //
	void openProductsFile(); //
	void openSalesFile();
	void openPrescriptionFile();
	void writeToClientsFile();
	void writeToPharmaciesFile();
	void writeToStaffFile();
	void writeToSalesFile();
	void writeToProductsFile();
	void writeToPrescriptionFile();

	string parse(string in);
	string parseStaff(string in);
	string parseProductSale(string sale);
	StaffMember getStaffM(string name);
	Sale getSale(unsigned int code);

	//Utilities
	int checkForInt(){
		int nr;
		cin >> nr;

			while (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input, try again: ";
				cin >> nr;
			}
			return nr;
	}

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
	ItemDoesNotExist(string n){item = n;}
	void printMsg(){cout << item << " does not exist in Database.";}
};

#endif /* SRC_DATABASE_H_ */
