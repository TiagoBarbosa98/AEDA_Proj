#ifndef SRC_DATABASE_H_
#define SRC_DATABASE_H_
#include <iostream>
#include <string>
#include <vector>

#include "Product.h"
#include "Pharmacy.h"
#include "Client.h"
#include "StaffMember.h"
#include "Receipt.h"

#include <vector>
#include <fstream>
#include <set>
#include <queue>
#include <unordered_set>
#include <sstream>

class DataBase {
private:
	string productsFile, clientsFile, pharmaciesFile, staffFile;
	vector<Product* > products;
	vector<Client> clients;
	vector<Pharmacy> pharmacies;
	vector<StaffMember> staff;
	vector<Receipt> receipts;
public:
	DataBase();
	DataBase(string productsFile, string clientsFile, string pharmaciesFile, string staffFile);
	virtual ~DataBase();

	//Getters
	vector<Client> getClients() const;
	vector<Pharmacy> getPharmacies() const;
	const vector<Product*>& getProducts() const;
	vector<Receipt> getReceipts() const;
	vector<StaffMember> getStaff() const;
	void addClient();
	//adding elem to vector v
	template<class T>
	void addElement(T elem, vector<T> &v){
		v.push_back(elem);
	}
	string readComplexString (istringstream &ss, char separate);
	void openproductsFile();
	void openclientsFile ();
	void openpharmaciesFile();
	void openstaffFile();

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
