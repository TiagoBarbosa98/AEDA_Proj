#ifndef SRC_DATABASE_H_
#define SRC_DATABASE_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>

#include "Product.h"
#include "Pharmacy.h"
#include "Client.h"
#include "StaffMember.h"
#include "Prescription.h"
#include "Sale.h"
#include "Medicine.h"

class DataBase {
private:
	string prescFile, productsFile, clientsFile, pharmaciesFile, staffFile, salesFile;
	vector<Product* > products;
	vector<Client> clients;
	vector<Pharmacy> pharmacies;
	vector<StaffMember> staff;
	vector<Prescription> prescriptions;
	vector<Sale> sales;
public:
	DataBase();
	DataBase(string prodFile, string cliFile, string pharmFile, string staffFile);
	DataBase(string productsFile, string clientsFile, string pharmaciesFile, string staffFile, string salesFile, string prescFile);
	virtual ~DataBase();

	vector<Sale> getSales(){return sales;}

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
	string parseProduct(string in);
	StaffMember getStaffM(string name);
	Sale getSale(unsigned int code);
	tm parseDate(string in);


	void writeToSales(string fileName){
		ofstream saveData;

		saveData.open(fileName);

		if (saveData.fail()){
			//throw ErrorOpeningFile(fileName);
		}

		for(int i = 0; i < sales.size(); i++){
			if(i != sales.size() - 1)
				saveData << sales[i] << endl;
			else
				saveData << sales[i];
		}

		saveData.close();
	}


	template<class T>
	void writeToFileW(string fileName, vector<T> v){
		ofstream saveData;

		saveData.open(fileName);

		if (saveData.fail()){
			cout << "poop";
			//throw ErrorOpeningFile(fileName);
		}

		for (unsigned int i = 0; i < v.size(); i++) {

			if(i != v.size() - 1)
				saveData << v[i]  << endl;
			else
				saveData << v[i];
		}

		saveData.close();
	}

	void writeToProductsFile2(string fileName){
		ofstream saveData;

		saveData.open(fileName);

		if (saveData.fail()){
			//throw ErrorOpeningFile(fileName);
		}

		for(unsigned int i = 0; i < products.size(); i++){
			if(i != products.size() - 1)
				saveData << products[i]->display() << endl;
			else
				saveData << products[i]->display();

		}

		saveData.close();
	}
	template<class T>
		void writeToFile(string fileName, vector<T> v){
			ofstream saveData;

			saveData.open(fileName);

			if (saveData.fail()){
				//throw ErrorOpeningFile(fileName);
			}

			for (unsigned int i = 0; i < v.size(); i++) {

				saveData << v[i] << endl;
			}

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
	void printMsg(){cout << item << " does not exist in Database, try again.\n\n";}
};

#endif /* SRC_DATABASE_H_ */
