 /*
 * Receipt.h
 *
 *  Created on: 30/10/2018
 *      Author: tiagobarbosa 
 */

#ifndef SRC_RECEIPT_H_
#define SRC_RECEIPT_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Receipt {
	//numero, numero, cliente, medico e lista produtos
private:
	int number;
	string client, doctor;
	vector<int> products;

public:
	Receipt();
	Receipt(int number, string client, string doctor, vector<int> products);
	virtual ~Receipt();

	//Getters and Setters
	int getNumber() const;
	const string& getClient() const;
	const string& getDoctor() const;
	vector<int> getProducts() const;

	//adds the product with code c to products
	void addProduct(int c);
};

#endif /* SRC_RECEIPT_H_ */
