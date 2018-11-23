#ifndef SRC_SALE_H_
#define SRC_SALE_H_
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "Product.h"

using namespace std;

/**
 * @brief 
 * 
 */
class Sale {
private:
/**
 * @brief 
 * 
 */
	tm *date;
	/**
	 * @brief 
	 * 
	 */
	static unsigned int lastCode;
	/**
	 * @brief 
	 * 
	 */
	unsigned int code;
	/**
	 * @brief 
	 * 
	 */
	vector<pair<Product, unsigned int>> prodQtt;
public:
/**
 * @brief Construct a new Sale object
 * 
 */
	Sale();
	/**
	 * @brief Destroy the Sale object
	 * 
	 */
	virtual ~Sale();
	/**
	 * @brief Construct a new Sale object
	 * 
	 * @param cart 
	 */
	Sale(vector<pair<Product, unsigned int>> cart);
	//Getters and setters
	/**
	 * @brief Get the Date object
	 * 
	 * @return tm* 
	 */
	tm * getDate() const;
	/**
	 * @brief Get the Code object
	 * 
	 * @return unsigned int 
	 */
	unsigned int getCode() const;
	/**
	 * @brief Get the Prod Qtt object
	 * 
	 * @return const vector<pair<Product, unsigned int> >& 
	 */
	const vector<pair<Product, unsigned int> >& getProdQtt() const;
	/**
	 * @brief 
	 * 
	 * @param os 
	 * @param s 
	 * @return ostream& 
	 */
	friend ostream & operator << (ostream & os, const Sale & s);
	/**
	 * @brief 
	 * 
	 * @param p 
	 * @param qtt 
	 */
	void addProdQtt(Product p, int qtt);
	//adds a new product to prodQtt

};

#endif /* SRC_SALE_H_ */
