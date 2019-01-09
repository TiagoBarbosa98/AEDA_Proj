#ifndef SRC_DATABASE_H_
#define SRC_DATABASE_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <queue>
#include <iomanip>

using namespace std;

#include "Product.h"
#include "Pharmacy.h"
#include "Client.h"
#include "StaffMember.h"
#include "Prescription.h"
#include "Sale.h"
#include "Medicine.h"
#include "BST.h"

class DataBase {
private:
	string prescFile, productsFile, clientsFile, pharmaciesFile, staffFile, salesFile; /** @brief files names*/
	//vector<Product* > products; /** @brief vector for products*/
	vector<Client> clients;/** @brief vector for clients*/
	vector<Pharmacy> pharmacies;/** @brief vector for pharmacies*/
	vector<StaffMember> staff;/** @brief vector for staff*/
	vector<Prescription> prescriptions;/** @brief vector for prescriptions*/
	vector<Sale> sales;/** @brief vector for sales*/
	BST<Client> clientsA;
	priority_queue <Product> products;
public:
	void lessProductsThan();
	priority_queue<Product> getProducts() const;
	/**
	 * @brief      Constructs the object.
	 */
	DataBase();

	/**
	 * @brief      Constructs the object.
	 *
	 * @param prodFile 		products File
	 *
	 * @param cliFile		clients File
	 *
	 * @param pharmFile		pharmacies File
	 *
	 * @param staffFile		staff File
	 */
	DataBase(string prodFile, string cliFile, string pharmFile, string staffFile);

	/**
	 * @brief      Constructs the object.
	 *
	 * @param productsFile 		products File
	 *
	 * @param clientsFile		clients File
	 *
	 * @param pharmaciesFile		pharmacies File
	 *
	 * @param staffFile		staff File
	 *
	 * @param salesFile 	sales File
	 *
	 * @param prescFile 	prescriptions File
	 */
	DataBase(string productsFile, string clientsFile, string pharmaciesFile, string staffFile, string salesFile, string prescFile);

	/*
	 * @brief Destructor
	 */
	virtual ~DataBase();

	/**
	 * @brief Gets clients vector
	 */
	vector<Sale> getSales(){return sales;}

	//Getters
	vector<Client> getClients() const;

	/**
	 * @brief Gets pharmacies vector
	 */
	vector<Pharmacy> getPharmacies() const;

	/**
	 * @brief Gets products vector
	 */
//	const vector<Product*>& getProducts() const;

	/**
	 * @brief Gets prescriptions vector
	 */
	vector<Prescription> getPrescriptions() const;

	/**
	 * @brief Gets staff vector
	 */
	vector<StaffMember> getStaff() const;


	/*
	 * @brief Function for adding clients to DB.
	 */
	void addClient();

	/*
	 * @brief Function for adding pharmacies to DB.
	 */
	void addPharmacy();

	/*
	 * @brief Function for adding staff members to DB.
	 */
	void addStaffMember();

	/*
	 * @brief Function for adding sales to DB.
	 */
	void addSale();

	/*
	 * @brief Function for adding prescriptions to DB.
	 */
	void addPrescription();

	/*
	 * @brief Function for adding products to DB.
	 */
	void addProduct();

	/*
	 * @brief function for removing products from DB
	 */
	void removeProduct();

	/*
	 * @brief function for removing sales from DB
	 */
	void removeSale();

	/*
	 * @brief function for removing clients from DB
	 */
	void removeClient();

	/*
	 * @brief function for removing pharmacies from DB
	 */
	void removePharmacy();

	/*
	 * @brief function for removing staff from DB
	 */
	void removeStaffMember();

	/*
	 * @brief function for displaying all clients on screen
	 */
	void showAllClients();

	/*
	 * @brief function for displaying all pharmacies on screen
	 */
	void showAllPharmacies();

	/*
	 * @brief function for displaying all staff on screen
	 */
	void showAllStaff();

	/*
	 * @brief function for displaying all sales on screen
	 */
	void showAllSales();

	/*
	 * @brief function for displaying all prescriptions on screen
	 */
	void showAllPrescriptions();

	/*
	 * @brief function for displaying all products on screen
	 */
	void showAllProducts();


	/*
	 * @brief function for reading products file
	 */
	void readProductsFile();

	/*
	 * @brief Function to get a product from DB by its name
	 *
	 * @param 	name 	The name
	 *
	 * @return     said product
	 */
	Product getProductByName(string name);


	/*
	 * @brief function for reading clients file
	 */
	void openClientsFile ();

	/*
	 * @brief function for reading pharmacies file
	 */
	void openPharmaciesFile(); //

	/*
	 * @brief function for reading staff file
	 */
	void openStaffFile(); //

	/*
	 * @brief function for reading products file
	 */
	void openProductsFile(); //

	/*
	 * @brief function for reading sales file
	 */
	void openSalesFile();

	/*
	 * @brief function for reading prescriptions file
	 */
	void openPrescriptionFile();

	/*
	 * @brief function to write to clients file
	 */
	void writeToClientsFile();

	/*
	 * @brief function to write to pharmacies file
	 */
	void writeToPharmaciesFile();

	/*
	 * @brief function to write to staff file
	 */
	void writeToStaffFile();

	/*
	 * @brief function to write to sales file
	 */
	void writeToSalesFile();

	/*
	 * @brief function to write to products file
	 */
	void writeToProductsFile();

	/*
	 * @brief function to write to prescriptions file
	 */
	void writeToPrescriptionFile();

	/*
	 * @brief parses a string
	 *
	 * @param in 	said string
	 *
	 * @return parsed string
	 */
	string parse(string in);


	/*
	 * @brief parses a string with staff member
	 *
	 * @param in 	said string
	 *
	 * @return parsed string
	 */
	string parseStaff(string in);


	/*
	 * @brief parses a string with products for a sale
	 *
	 * @param sale 	said string
	 *
	 * @return parsed string
	 */
	string parseProductSale(string sale);

	string parseProduct(string in);
	/**
	 * @brief      Gets the staff Member with name name.
	 *
	 * @param      name  The name
	 *
	 * @return     The staff member.
	 */
	StaffMember* getStaffM(string name);

	/**
	 * @brief      Gets the sala with code code.
	 *
	 * @param      code The code
	 *
	 * @return     The staff code.
	 */
	Sale getSale(unsigned int code);
	tm parseDate(string in);

	void writeToSales(string fileName){
		ofstream saveData;

		saveData.open(fileName);

		if (saveData.fail()){
			//throw ErrorOpeningFile(fileName);
		}

		for(int i = 0; i < sales.size(); i++){
			if(i != sales.size() - 1)
				saveData << sales[i] << endl;
			else
				saveData << sales[i];
		}

		saveData.close();
	}



	/*
	 * @brief template to write to files a vector
	 *
	 * @tparam T		type of vector
	 *
	 * @param fileName	name of File
	 *
	 * @param v			vector to be written
	 */
	template<class T>
	void writeToFileW(string fileName, vector<T> v){
		ofstream saveData;

		saveData.open(fileName);

		if (saveData.fail()){
			cout << "poop";
			//throw ErrorOpeningFile(fileName);
		}

		for (unsigned int i = 0; i < v.size(); i++) {

			if(i != v.size() - 1)
				saveData << v[i]  << endl;
			else
				saveData << v[i];
		}

		saveData.close();
	}

	void writeToProductsFile2(string fileName){
		ofstream saveData;

		saveData.open(fileName);

		if (saveData.fail()){
		//	throw ErrorOpeningFile(fileName);
		}

		while (!products.empty()) {
			Product p = products.top();

			saveData << p.display();

			saveData << endl;

			products.pop();
		}
	/*	for(unsigned int i = 0; i < products.size(); i++){
			if(i != products.size() - 1)
				saveData << products[i]->display() << endl;
			else
				saveData << products[i]->display();

		}*/

		saveData.close();
	}


	/**
	 * @brief Displays all the clients in the DataBase
	 */
	void showAllClientsA();

	/**
	 * @brief Displays all clients from a specific district
	 *
	 * @param district Name of the district we want to show the clients from
	 */
	void showClientsByDistrict(string district);

	/**
	* @brief Displays the client with specific id info
	*
	* @param nc Id of the client
	*/
	void getClientInfo(unsigned int nc);

	/**
	* @brief Looks for a Client in the DataBase with specific id and returns it
	*
	* @param nc Id of the Client
	*
	* @return The Client object we want to get
	*/
	Client clientExists(unsigned int nc);

	/**
	 * @brief Displays the clients on the top 3 of most purchases made
	 */
	void showClientsWithMostPurchases();

	/**
	 * @brief Asks the user to assign some StaffMember 's to existing Pharmacy 's
	 *
	 * @param members Vector containing the StaffMember 's to be assigned
	 */
	void assignStaff(vector<StaffMember> members);

	/**
	 * @brief Asks the user to assign all StaffMember 's in the DataBase
	 * with no Pharmacy assigned
	 */
	void assignStaffWithNoPh();

	/**
	 * @brief Displays all StaffMember 's in the DataBase
	 * with no Pharmacy assigned
	 */
	void showStaffWithoutPh();

	/**
	 * @brief Keeps asking the user for the name of a Pharmacy until
	 * an existing one is given
	 *
	 * return String with an existing Pharmacy name
	 */
	string checkPhName();

	/**
	 * @brief Displays the names of the pharmacies available in the DB
	 */
	void showPharmaciesNames();

	//TODO
	/**
	 * @brief Asks the user edit a Pharmacy 's info
	 */
	void changePharmacyInfo();

	/**
	 * @brief Searches through pharmacies vector and removes the StaffMember
	 * with a specific name from one of those pharmacies
	 *
	 * @param name Name of the staff to be removed
	 */
	void removeStaffM(string name);

	void staffPhToNone(string name);

	//bool isPharmacy(string name);

};


/**
 * @brief      Class for error opening file.
 */
class ErrorOpeningFile {
    string nameFile; /** <	@brief name of File*/
public:

    /**
     * @brief      Constructs the object.
     *
     * @param  name  The name of the file
     */
    ErrorOpeningFile (string name) {
        nameFile = name;
    }


    /**
     * @brief      Gets the file name.
     *
     * @return     The file name.
     */
    string getFileName () {
        return nameFile;
    }
};


/**
 * @brief      Class for when an item does not exist.
 */
class ItemDoesNotExist{
	string item; /** < @brief item name*/
public:

	/**
	 * @brief      Constructs the object.
	 *
	 * @param      n     name
	 */
	ItemDoesNotExist(string n){item = n;}


	void printMsg(){cout << item << " does not exist in Database, try again.\n\n";}
};

#endif /* SRC_DATABASE_H_ */
