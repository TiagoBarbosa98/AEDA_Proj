/*
 * DataBase.cpp
 *
 *  Created on: 30/10/2018
 *      Author: tiagobarbosa 
 */

#include "DataBase.h"

DataBase::DataBase() {
	// TODO Auto-generated constructor stub

}

DataBase::~DataBase() {
	// TODO Auto-generated destructor stub
}

vector<Client> DataBase::getClients() const {
	return clients;
}

vector<Pharmacy> DataBase::getPharmacies() const {
	return pharmacies;
}

const vector<Product*>& DataBase::getProducts() const {
	return products;
}

vector<Receipt> DataBase::getReceipts() const {
	return receipts;
}

vector<StaffMember> DataBase::getStaff() const {
	return staff;
}
