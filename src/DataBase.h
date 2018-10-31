/*
 * DataBase.h
 *
 *  Created on: 30/10/2018
 *      Author: tiagobarbosa 
 */

/*
 * Class for saving all the data about the pharmacies, sales, employees, etc.
 */

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

class DataBase {
private:
	vector<Product* > products;
	vector<Client> clients;
	vector<Pharmacy> pharmacies;
	vector<StaffMember> staff;
	vector<Receipt> receipts;
public:
	DataBase();
	virtual ~DataBase();

	//Getters
	vector<Client> getClients() const;
	vector<Pharmacy> getPharmacies() const;
	const vector<Product*>& getProducts() const;
	vector<Receipt> getReceipts() const;
	vector<StaffMember> getStaff() const;

	//adding elem to vector v
	template<class T>
	void addElement(T elem, vector<T> &v){
		v.push_back(elem);
	}

};

#endif /* SRC_DATABASE_H_ */
