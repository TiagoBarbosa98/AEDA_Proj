
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
#include <fstream>
#include "Sale.h"
#include "BST.h"
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
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
		cout << "|     4) Edit Pharmacy info                        |" << endl;
		cout << "|     5) Exit                                      |" << endl;
		cout << "|    Option: ";
		op = checkBoundaries(1, 5);
		switch(op){
		case 1:
			cout << endl;
			d.showAllPharmacies();
			break;
		case 2:
			cout << endl;
			d.addPharmacy();
			break;
		case 3:
			cout << endl;
			try{d.removePharmacy();}
			catch(ItemDoesNotExist & e){e.printMsg();}
			break;
		case 4:
			cout << endl;
			d.changePharmacyInfo();
			break;
		default:
			return;
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
		cout << "|     4) Assign staff with no current pharmacy     |" << endl;
		cout << "|     5) Exit                                      |" << endl;
		cout << "|    Option: ";
		op = checkBoundaries(1, 5);
		switch(op){
		case 1:
			cout << endl;
			d.showAllStaff();
			break;
		case 2:
			cout << endl;
			d.addStaffMember();
			break;
		case 3:
			cout << endl;
			try{d.removeStaffMember();}
			catch(ItemDoesNotExist & e){e.printMsg();}
			break;
		case 4:
			cout << endl;
			d.assignStaffWithNoPh();
			break;
		default:
			return;
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
		cout << "|     4) Show clients with most purchases made     |" << endl;
		cout << "|     5) Show clients in a certain district        |" << endl;
		cout << "|     6) Search client by ID                       |" << endl;
		cout << "|     7) Exit                                      |" << endl;
		cout << "|    Option: ";
		op = checkBoundaries(1, 7);
		switch(op){
		case 1:
			cout << endl;
			cout << "Listing Clients" << endl;
			d.showAllClientsA();
			break;
		case 2:
			cout << endl;
			cout << "Adding Client" << endl;
			d.addClient();
			break;
		case 3:
			cout << endl;
			cout << "Removing Client" << endl;
			try {d.removeClient();}
			catch (ItemDoesNotExist & e){ e.printMsg();}
			break;
		case 4:
			cout << endl;
			d.showClientsWithMostPurchases();
			break;
		case 5:
			cout << endl;
			d.showClientsByDistrict();
			break;
		case 6:
			cout << endl;
			d.getClientInfo();
			break;
		default:
			return;

		}

	}
}

void productsMenu(DataBase & d){

	int op = 0;
	while(op != 5){
		cout << "|                PRODUCTS MENU                     |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) List Products                             |" << endl;
		cout << "|     2) Add Product                               |" << endl;
		cout << "|     3) Remove Product                            |" << endl;
		cout << "|     4) Show less than N                          |" << endl;
		cout << "|     5) Exit                                      |" << endl;
		cout << "|    Option: ";
		op = checkBoundaries(1, 5);
		switch(op){
		case 1:
			cout << endl;
			cout << "Listing Products" << endl;
			d.showAllProducts();
			break;
		case 2:
			cout << endl;
			cout << "Adding Product" << endl;
			d.addProduct();
			break;
		case 3:
			cout << endl;
			cout << "Removing Product" << endl;
			try {d.removeProduct();}
			catch (ItemDoesNotExist & e){ e.printMsg();}
			break;
		case 4:
			cout << endl;
			cout << "Show products with less than N in stock" << endl;
			d.lessProductsThan();
			break;
		default:
			return;
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
				cout << endl;
				cout << "Listing Sales" << endl;
				d.showAllSales();
				break;
			case 2:
				cout << endl;
				cout << "Adding Sale" << endl;
				d.addSale();
				break;
			case 3:
				cout << endl;
				cout << "Removing Sale" << endl;
				try {d.removeSale();}
				catch (ItemDoesNotExist & e){ e.printMsg();}
				break;
			default:
				return;
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
			cout << endl;
			d.showAllPrescriptions();
			break;
		case 2:
			cout << endl;
			d.addPrescription();
			break;
		default:
			return;
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
			cout << endl;
			pharmaciesMenu(d);
			break;
		case 2:
			cout << endl;
			staffMenu(d);
			break;
		case 3:
			cout << endl;
			clientsMenu(d);
			break;
		case 4:
			cout << endl;
			productsMenu(d);
			break;
		case 5:
			cout << endl;
			salesMenu(d);
			break;
		case 6:
			cout << endl;
			prescriptionsMenu(d);
			break;
		default:
			cout << endl;
			cout << "Goodbye!" << endl;
			break;
		}

		d.writeToClientsFile();
		d.writeToPharmaciesFile();
		d.writeToPrescriptionFile();
		d.writeToProductsFile();
		d.writeToSalesFile();
		d.writeToStaffFile();

	}

}

int main(){
	cout << "Do you wish to import data from existing Data Base (y/n)?\n";
	string in;
	cin >> in;
	DataBase * d;
	if(in == "Y" || in == "y" || in == "yes" || in == "Yes")
		d = new DataBase("TextFiles/Products.txt", "TextFiles/Clients.txt","TextFiles/Pharmacies.txt", "TextFiles/Staff.txt", "TextFiles/Sales.txt", "TextFiles/Prescriptions.txt");
	else
		d = new DataBase();
	mainMenu(*d);

	/*
	StaffMember *m = new StaffMember();
	StaffMember *m2 = new StaffMember();

	Pharmacy p("pi", "me", "mr");
	p.addStaff(m);
	p.addStaff(m2);
	cout << p;
	*/
	/*DataBase *d = new DataBase();
	d->openClientsFile();
	d->openStaffFile();
	d->openPharmaciesFile();
	d->openProductsFile();
	//d->removeStaffMember();
	d->showAllPharmacies();
	d->showAllPharmacies();
	d->showAllProducts();
	//d->showAllClientsA();
	d->lessProductsThan();*/

	return 0;
}


