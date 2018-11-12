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
	vector<int> products;

public:
	Prescription();
	Prescription(int number, string client, string doctor, vector<int> products);
	virtual ~Prescription();

	//Getters and Setters
	int getNumber() const;
	const string& getClient() const;
	const string& getDoctor() const;
	vector<int> getProducts() const;

	//adds the product with code c to products
	void addProduct(int c);
};

#endif /* SRC_RECEIPT_H_ */
