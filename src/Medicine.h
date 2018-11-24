#ifndef SRC_MEDICINE_H_
#define SRC_MEDICINE_H_

#include "Product.h"

/**
 * @brief      Class for medicine.
 */
class Medicine: public Product {
private:
	float discount; /** < @brief State discount on Medicine*/
	bool prescription; /** < @brief If said Medicine requires a precription */
public:
	/**
	 * @brief Medicine Constructor
	 */
	Medicine();
	/**
	 * @brief Medicine Constructor
	 * 
	 * @param name 		Product name
	 * 
	 * @param description	Description
	 * 
	 * @param 	prince 		Price
	 * 
	 * @param 	iva		IVA
	 * 
	 * @param Code 		Product Code
	 * 
	 * @param Discount 	State discount
	 * 
	 * @param noReceipt If said Medicine requeires a prescription
	 */
	Medicine(string name, string description, float price, float iva, int code, float discount, bool noReceipt);
	
	/**
	 * @brief Gets the Discount
	 * 
	 * @return The discount
	 */
	float getDiscount() const;

	/**
	 * @brief Calculates price with discount
	 *
	 * @return Price with discount applied
	 */
	float getPriceWithDiscount() const;

	/*
	 * @brief Gets prescription bool
	 * 
	 * @return true if presciption is required
	 */
	bool prescriptionRequired() const;

	/**
	 * @brief Overload ostream operator << to write Medicine's info to an outstream
	 * 
	 * @param os 	outstream
	 * 
	 * @param m 	Medicine to be written
	 * 
	 * @return outstream
	 */
	friend ostream & operator << (ostream & os, const Medicine & m);

	/*
	 * @brief Get's wether or not the calling product is Medicine
	 * 
	 * @param true if calling obj. is Medicine.
	 */
	string display() const;

	/*
	 * @brief represents prescriptionRequired() in a string format
	 * 
	 * @return string with prescriptionRequired() value.
	 */
	string prescr() const;
};

#endif /* SRC_MEDICINE_H_ */
