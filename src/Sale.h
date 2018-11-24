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
 * @class Sale class.
 * 
 */
class Sale {
private:
	tm *date;/** < @brief Time and Date of Sale*/
	static unsigned int lastCode; /** < @brief Code of the last sale in the system*/
	eunsigned int code; /** < @brief Code of the Sale*/
	vector<tuple<string , unsigned int, unsigned int>> prodPriceQtt;/** < @brief Vector containing a tuples of product names, price paid and quantity. */
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
	Sale(vector<tuple<string , unsigned int, unsigned int>> cart);
	//Getters and setters
	/**
	 * @brief Get the Date object
	 * 
	 * @return tm* time and date
	 */
	tm * getDate() const;
	/**
	 * @brief Get the Code object
	 * 
	 * @return unsigned int code
	 */
	unsigned int getCode() const;
	/**
	 * @brief Write sale to Outstream
	 * 
	 * @param os outstream
	 * @param s Sale to be written
	 * @return ostream& 
	 */
	friend ostream & operator << (ostream & os,  Sale & s);
	/**
	 * @brief 
	 * 
	 * @param p product to be add
	 * @param qtt quantity
	 */
	void addProdPriceQtt(Product p, int q);

};

#endif /* SRC_SALE_H_ */
