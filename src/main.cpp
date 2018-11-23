#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
#include <fstream>
#include "Sale.h"
#include "Product.h"
#include "Medicine.h"
#include "DataBase.h"
#include "Entity.h"
#include "StaffMember.h"

using namespace std;


int checkBoundaries(int linf, int lsup) {
	int nr;

	cin >> nr;

	while (cin.fail() || nr > lsup || nr < linf) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, try again: ";
		cin >> nr;
	}

	return nr;
}

void pharmaciesMenu(DataBase & d){
	int op = 0;
	while(op != 4){
		cout << "|                PHARMACIES MENU                   |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) List Pharmacies                           |" << endl;
		cout << "|     2) Add Pharmacy                              |" << endl;
		cout << "|     3) Remove Pharmacy                           |" << endl;
		cout << "|     4) Exit                                      |" << endl;
		cout << "|    Option: ";
		op = checkBoundaries(1, 4);
		switch(op){
		case 1:
			d.showAllPharmacies();
			break;
		case 2:
			d.addPharmacy();
			break;
		case 3:
			try{d.removePharmacy();}
			catch(ItemDoesNotExist & e){e.printMsg();}
			break;
		default:
			break;
		}
	}
}

void staffMenu(DataBase & d){
	int op = 0;
	while(op != 4){
		cout << "|                STAFF MENU                        |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) List Staff                                |" << endl;
		cout << "|     2) Add Staff                                 |" << endl;
		cout << "|     3) Remove Staff                              |" << endl;
		cout << "|     4) Exit                                      |" << endl;
		cout << "|    Option: ";
		op = checkBoundaries(1, 4);
		switch(op){
		case 1:
			d.showAllStaff();
			break;
		case 2:
			d.addStaffMember();
			break;
		case 3:
			try{d.removeStaffMember();}
			catch(ItemDoesNotExist & e){e.printMsg();}
			break;
		default:
			break;
		}
	}
}

void clientsMenu(DataBase & d){
	int op = 0;
	while(op != 4){
		cout << "|                CLIENTS MENU                      |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) List Clients                              |" << endl;
		cout << "|     2) Add Client                                |" << endl;
		cout << "|     3) Remove Client                             |" << endl;
		cout << "|     4) Exit                                      |" << endl;
		cout << "|    Option: ";
		op = checkBoundaries(1, 4);
		switch(op){
		case 1:
			cout << "Listing Clients" << endl;
			d.showAllClients();
			break;
		case 2:
			cout << "Adding Client" << endl;
			d.addClient();
			break;
		case 3:
			cout << "Removing Client" << endl;
			try {d.removeClient();}
			catch (ItemDoesNotExist & e){ e.printMsg();}
			break;
		default:
			break;

		}

	}
}

void productsMenu(DataBase & d){

	int op = 0;
	while(op != 4){
		cout << "|                PRODUCTS MENU                     |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) List Products                             |" << endl;
		cout << "|     2) Add Product                               |" << endl;
		cout << "|     3) Remove Product                            |" << endl;
		cout << "|     4) Exit                                      |" << endl;
		cout << "|    Option: ";
		op = checkBoundaries(1, 4);
		switch(op){
		case 1:
			cout << "Listing Products" << endl;
			d.showAllProducts();
			break;
		case 2:
			cout << "Adding Product" << endl;
			d.addProduct();
			break;
		case 3:
			cout << "Removing Product" << endl;
			try {d.removeProduct();}
			catch (ItemDoesNotExist & e){ e.printMsg();}
			break;
		default:
			break;
		}
	}
}

void salesMenu(DataBase & d){

	int op = 0;
		while(op != 4){
			cout << "|                SALES MENU                        |" << endl;
			cout << "|                                                  |" << endl;
			cout << "|        Type your option:                         |" << endl;
			cout << "|     1) List Sales                                |" << endl;
			cout << "|     2) Add Sale                                  |" << endl;
			cout << "|     3) Remove Sale                               |" << endl;
			cout << "|     4) Exit                                      |" << endl;
			cout << "|    Option: ";
			op = checkBoundaries(1, 4);
			switch(op){
			case 1:
				cout << "Listing Sales" << endl;
				d.showAllSales();
				break;
			case 2:
				cout << "Adding Sale" << endl;
				d.addSale();
				break;
			case 3:
				cout << "Removing Sale" << endl;
				try {d.removeSale();}
				catch (ItemDoesNotExist & e){ e.printMsg();}
				break;
			default:
				break;
			}
		}

}

void prescriptionsMenu(DataBase & d){
	int op = 0;
	while(op != 3){
		cout << "|                PRESCRIPTIONS MENU                |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) List Prescriptions                        |" << endl;
		cout << "|     2) Add Prescription                          |" << endl;
		cout << "|     3) Exit                                      |" << endl;
		cout << "|    Option: ";
		op = checkBoundaries(1, 3);
		switch(op){
		case 1:
			d.showAllPrescriptions();
			break;
		case 2:
			d.addPrescription();
			break;
		default:
			break;
		}

	}
}

void mainMenu(DataBase & d){

	int op = 0;
	while(op != 7){
		cout << "|                  MAIN MENU                       |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) Manage Pharmacies                         |" << endl;
		cout << "|     2) Manage Staff                              |" << endl;
		cout << "|     3) Manage Clients                            |" << endl;
		cout << "|     4) Manage Products                           |" << endl;
		cout << "|     5) Manage Sales                              |" << endl;
		cout << "|     6) Manage Prescriptions                      |" << endl;
		cout << "|     7) Exit                                      |" << endl;
		cout << "|    Option: ";
		op = checkBoundaries(1, 7);
		switch(op){
		case 1:
			pharmaciesMenu(d);
			break;
		case 2:
			staffMenu(d);
			break;
		case 3:
			clientsMenu(d);
			break;
		case 4:
			productsMenu(d);
			break;
		case 5:
			salesMenu(d);
			break;
		case 6:
			prescriptionsMenu(d);
			break;
			break;
		default:
			cout << "Goodbye!" << endl;
			break;
		}

	}

}

int main(){
	/*Product * p = new Product("name", "desc", 10, 0.2, 0, false);
	vector<tuple<string, unsigned int, unsigned int >> v;
	Sale *s = new Sale(v);
	s->addProdPriceQtt(*p, 5);
	cout << *s << endl;*/

	DataBase * d = new DataBase("TextFiles/Products.txt", "TextFiles/Clients.txt","TextFiles/Pharmacies.txt", "TextFiles/Staff.txt", "TextFiles/Sales.txt");
	mainMenu(*d);
	/*
	Prescription p(0, "Joao Vitor", "Dr. Pontes", "Benurom");
	cout << p;*/
	return 0;
}


void mainMenu(DataBase d) {
	int choice;

	while (choice != 5) {
		cout << "____________________________________________________" << endl;
		cout << "|                  MAIN MENU                       |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) Manage Pharmacy                           |" << endl;
		cout << "|     2) Manage Staff                              |" << endl;
		cout << "|     3) Manage Clients                            |" << endl;
		cout << "|     4) Manage Products                           |" << endl;
		cout << "|     5) Exit                                      |" << endl;
		cout << "|    Option: ";

		choice = checkBoundaries(1, 5);


		switch (choice) {
		case 1:
			pharmaciesMenu(d);
			break;

		case 2:
			staffMenu(d);
			break;

		case 3:
			clientsMenu(d);
			break;

		case 4:
			//products menu
			break;

		case 5:
			cout << endl;
			cout << "See you next time!\n";
			break;
		}
	}
}

void clientMenu(DataBase d){
	int choice;

	while (choice != 4) {
		cout << "____________________________________________________" << endl;
		cout << "|                 CLIENTS MENU                     |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) Print clients                             |" << endl;
		cout << "|     2) Show client history                       |" << endl;
		cout << "|     3) Add Client                                |" << endl;
		cout << "|     4) Go Back to Main Menu                                      |" << endl;
		cout << "|    Option: ";

		choice = checkBoundaries(1, 4);

		switch (choice) {
		case 1:
			d.showAllClients();
			break;

		case 2:
			//staff menu
			break;

		case 3:
			d.addClient();
			break;

		case 4:
			d.writeToClientsFile();
			cout << endl;
			break;
		}
	}
}


void pharmacyMenu(DataBase d){
	int choice;

	while (choice != 4) {
		cout << "____________________________________________________" << endl;
		cout << "|                PHARMACY MENU                     |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) Show Pharmacies                           |" << endl;
		cout << "|     2) Show Pharmacy information                 |" << endl;
		cout << "|     3) Add Pharmacy                              |" << endl;
		cout << "|     4) Go Back to Main Menu                                    |" << endl;
		cout << "|    Option: ";

		choice = checkBoundaries(1, 4);

		switch (choice) {
		case 1:
			d.showAllPharmacies();
			break;

		case 2:
			//staff menu
			break;

		case 3:
			d.addPharmacy();
			break;

		case 4:
			d.writeToPharmaciesFile();
			cout << endl;
			break;
		}
	}
}


void staffMenu(DataBase d){
	int choice;

	while (choice != 4) {
		cout << "____________________________________________________" << endl;
		cout << "|                STAFF MENU                        |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) Show Staff                                |" << endl;
		cout << "|     2) Show Staff information                    |" << endl;
		cout << "|     3) Add Staff                                 |" << endl;
		cout << "|     4) Go Back to Main Menu                                    |" << endl;
		cout << "|    Option: ";

		choice = checkBoundaries(1, 4);

		switch (choice) {
		case 1:
			d.showAllStaff();
			break;

		case 2:
			//staff menu
			break;

		case 3:
			d.addStaffMember();
			break;

		case 4:
			d.writeToStaffFile();
			cout << endl;
			break;
		}
	}
}
