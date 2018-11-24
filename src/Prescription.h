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
	/**
	 * @brief Construct a new Prescription object
	 *
	 * @param number number of the Prescription to be created
	 * @param client Client that owns the prescription to be created
	 * @param doctor Doctor that wrote the prescription to be created
	 */
		Prescription(int number, string client, string doctor, string product);
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
	friend ostream &operator<<(ostream &os, const Prescription &p);

	
	/**
	 * @brief      Sets the client.
	 *
	 * @param  c     Client Name
	 */
	void setClient(string c);

	/**
	 * @brief      Sets the Doctor
	 *
	 * @param  c     Doctor Name
	 */
	void setDr(string c);
	/**
	 * @brief      Sets the Product
	 *
	 * @param      c     Product Name
	 */
	void setProduct(string c);


	/**
	 * @brief Overload ostream << operator to write Prescripiton to an outstream
	 * 
	 * @param 		os 		Outstream
	 * 
	 * @param 		p		Prescription to be written
	 * 
	 * @return     Outstream
	 *
	 */
	friend ostream & operator <<(ostream &os, const Prescription &p);

};

#endif /* SRC_RECEIPT_H_ */
