#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
#include "Product.h"
#include "Medicine.h"
#include "DataBase.h"
#include "main.h"
#include <fstream>

using namespace std;

int main(){
	DataBase d("products.txt", "clients.txt","pharmacies.txt", "staff.txt");
	mainMenu(d);
	return 0;
}

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
			//pharmacy menu
			break;

		case 2:
			//staff menu
			break;

		case 3:
			clientMenu(d);
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
		cout << "|     1) Show clients                              |" << endl;
		cout << "|     2) Show client information                   |" << endl;
		cout << "|     3) Add Client                                |" << endl;
		cout << "|     4) Exit                                      |" << endl;
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
			d.closeClientsFile();
			cout << endl;
			break;
		}
	}
}


void PharmacyMenu(DataBase d){
	int choice;

	while (choice != 4) {
		cout << "____________________________________________________" << endl;
		cout << "|                PHARMACY MENU                     |" << endl;
		cout << "|                                                  |" << endl;
		cout << "|        Type your option:                         |" << endl;
		cout << "|     1) Show Pharmacies                           |" << endl;
		cout << "|     2) Show Pharmacy information                 |" << endl;
		cout << "|     3) Add Pharmacy                              |" << endl;
		cout << "|     4) Exit                                      |" << endl;
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
			d.addFarmacy();
			break;

		case 4:
			d.closePharmaciesFile();
			cout << endl;
			break;
		}
	}
}
