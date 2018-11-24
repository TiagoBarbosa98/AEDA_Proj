#ifndef SRC_SALE_H_
#define SRC_SALE_H_
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <tuple>
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
	vector<tuple<string , unsigned int, float>> prodPriceQtt;

	float price;
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
	/**
	 * @brief Construct a new Sale object
	 * 
	 * @param cart 
	 */
	Sale(vector<tuple<string , unsigned int, float>> cart);
	Sale(tm *time, vector<tuple<string , unsigned int, float>> cart, float price);
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
	/**
	 * @brief 
	 * 
	 * @param os 
	 * @param s 
	 * @return ostream& 
	 */
	friend ostream & operator << (ostream & os,  Sale & s);
	/**
	 * @brief 
	 * 
	 * @param p 
	 * @param qtt 
	 */
	void addProdPriceQtt(Product p, int q);
	//adds a new product to prodQtt

	string display();

};

#endif /* SRC_SALE_H_ */
