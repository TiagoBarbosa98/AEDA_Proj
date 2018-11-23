#ifndef SRC_PRESCRIPTION_H_
#define SRC_PRESCRIPTION_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Prescription {
	//numero, numero, cliente, medico e lista produtos
private:
	int number;
	string client, doctor;
	vector<string> products;

public:
	Prescription();
	Prescription(int number, string client, string doctor, vector<string> products);
	virtual ~Prescription();

	//Getters and Setters
	int getNumber() const;
	const string& getClient() const;
	const string& getDoctor() const;
	vector<string> getProducts() const;
	friend ostream & operator<< (ostream & os, Prescription const & s);

	//adds the product with code c to products
	void addProduct(string  c);
};

#endif /* SRC_RECEIPT_H_ */
