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
	int number; /** < @brief number of the Prescription */
	string client; /** < @brief Client that owns the prescription  */
	string doctor; /** < @brief Doctor that wrote the prescription  */
	vector<int> products; /** < @brief Products of the Prescription */

public:
/**
 * @brief Construct a new Prescription object
 * 
 */
	Prescription();
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
