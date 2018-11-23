#ifndef SRC_PRESCRIPTION_H_
#define SRC_PRESCRIPTION_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * @class Prescription Class that represents a prescription where are stored the number, client, doctor and products os the prescription
 */
class Prescription {
	//numero, numero, cliente, medico e lista produtos
private:
	int number;
	string client, doctor;
	string product;

public:
/**
 * @brief Construct a new Prescription object
 * 
 */
	Prescription();
	Prescription(int number, string client, string doctor, string product);
	/**
	 * @brief Construct a new Prescription object
	 * 
	 * @param number number of the Prescription to be created
	 * @param client Client that owns the prescription to be created
	 * @param doctor Doctor that wrote the prescription to be created
	 * @param products Products of the Prescription to be created
	 */
	Prescription(int number, string client, string doctor, vector<int> products);
	/**
	 * @brief Destroy the Prescription object
	 * 
	 */
	virtual ~Prescription();

	/* get and set methods */
	
	/**
	 * @brief Get the Number object
	 * 
	 * @return int Prescription's number
	 */
	int getNumber() const;
	/**
	 * @brief Get the Client object
	 * 
	 * @return const string& Prescription's Client
	 */
	const string& getClient() const;
	/**
	 * @brief Get the Doctor object
	 * 
	 * @return const string& Prescription's Doctor
	 */
	const string& getDoctor() const;
	string getProduct() const;

	//adds the product with code c to products
	void setClient(string c);
	void setDr(string c);
	void setProduct(string c);
	friend ostream & operator <<(ostream &os, const Prescription &p);
	/**
	 * @brief Get the Products object
	 * 
	 * @return vector<int> Prescription's products
	 */
	vector<int> getProducts() const;

/**
 * @brief adds the product with number c to products
 * 
 * @param c number of the product
 */
	void addProduct(int c);
};

#endif /* SRC_RECEIPT_H_ */
