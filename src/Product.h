#ifndef SRC_PRODUCT_H_
#define SRC_PRODUCT_H_
#include <iostream>
#include <string>
using namespace std;

/*
 * @class Product Class that represents a prescription where are stored the number, client, doctor and products os the prescription
 */
class Product {
private:
	string name;/** < @brief Name of the Product */
	string description;/** < @brief Description of the Product */
	float price;/** < @brief Price of the Product */
	float iva;/** < @brief Iva of the Product */
	int code;/** < @brief Code of the Product */
	bool medicine;

public:
/**
 * @brief Construct a new Product object
 * 
 */
	Product();
	/**
	 * @brief Construct a new Product object
	 * 
	 * @param name The name of the Product to be created
	 * @param description The description of the Product to be created
	 * @param price The price of the Product to be created
	 * @param iva The iva of the Product to be created
	 * @param code The code of the Product to be created
	 */
	Product(string name, string description, float price, float iva, int code, bool m);
	/**
	 * @brief Destroy the Product object
	 * 
	 */
	virtual ~Product();

	/* get and set methods */
	/**
	 * @brief Get the Code object
	 * 
	 * @return int Product's code
	 */
	int getCode() const;
	/**
	 * @brief Get the Description object
	 * 
	 * @return const string& Product's description
	 */
	const string& getDescription() const;
	/**
	 * @brief Get the Iva object
	 * 
	 * @return float Product's iva
	 */
	float getIva() const;
	/**
	 * @brief Get the Name object
	 * 
	 * @return const string& Product's name
	 */
	const string& getName() const;
	/**
	 * @brief Get the Price object
	 * 
	 * @return float Product's price
	 */
	float getPrice() const;
	/**
	 * @brief prints all the the product's information
	 * 
	 * @param os 
	 * @param p product 
	 * @return ostream& the information
	 */
	friend ostream & operator << (ostream & os, const Product & p);
	/**
	 * @brief Get the Total Price object
	 * 
	 * @return float total price of the product with the iva added
	 */
	float getTotalPrice() const;

	bool getMedicine() const;

};



#endif /* SRC_PRODUCT_H_ */
