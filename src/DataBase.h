/*
 * DataBase.h
 *
 *  Created on: 30/10/2018
 *      Author: tiagobarbosa 
 */

/*
 * Class for saving all the data about the pharmacies, sales, employees, etc.
 */

#ifndef SRC_DATABASE_H_
#define SRC_DATABASE_H_
#include <iostream>
#include <string>
#include <vector>

#include "Product.h"

class DataBase {
private:
	vector<Product* > products;
public:
	DataBase();
	virtual ~DataBase();
};

#endif /* SRC_DATABASE_H_ */
