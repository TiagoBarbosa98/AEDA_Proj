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
	string product;

public:
	Prescription();
	Prescription(int number, string client, string doctor, string product);
	virtual ~Prescription();

	//Getters and Setters
	int getNumber() const;
	const string& getClient() const;
	const string& getDoctor() const;
	string getProduct() const;

	//adds the product with code c to products
	void setClient(string c);
	void setDr(string c);
	void setProduct(string c);
	friend ostream & operator <<(ostream &os, const Prescription &p);
};

#endif /* SRC_RECEIPT_H_ */
