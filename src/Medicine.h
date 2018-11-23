#ifndef SRC_MEDICINE_H_
#define SRC_MEDICINE_H_

#include "Product.h"

class Medicine: public Product {
private:
	float discount;
	/*TODO fazer excepção para quando se tentam criar medicamentos sem receita,
	 * mas com discount? (ganhar uns pontitos extra no projeto mesmo que nao seja preciso
	 * fazer desta forma)
	 */
	//true if the medicine can be sold without a receipt
	bool prescription;
public:
	Medicine();
	Medicine(string name, string description, float price, float iva, int code, float discount, bool pres);
	virtual ~Medicine();
	float getDiscount() const;
	float getPriceWithDiscount() const;
	bool isNoReceipt() const;
	bool prescriptionRequired() const;
	friend ostream & operator << (ostream & os, const Medicine & m);
};

#endif /* SRC_MEDICINE_H_ */
