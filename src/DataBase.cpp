#include "DataBase.h"

DataBase::DataBase() {
	// TODO Auto-generated constructor stub

}
DataBase::DataBase(string productsFile, string clientsFile, string pharmaciesFile, string staffFile, string salesFile){
	this->productsFile = productsFile;
	this->clientsFile = clientsFile;
	this->pharmaciesFile = pharmaciesFile;
	this->staffFile = staffFile;
	this->salesFile = salesFile;
/*
	try {
		//  openproductsFile();
		openClientsFile();
		openpharmaciesFile();
		openstaffFile();
	} catch (ErrorOpeningFile &name) {
		cout << "Error opening the file " << name.getFileName() << endl
				<< "No data was imported\n";

	}*/
}

DataBase::~DataBase() {
	// TODO Auto-generated destructor stub
}

vector<Client> DataBase::getClients() const {
	return clients;
}

vector<Pharmacy> DataBase::getPharmacies() const {
	return pharmacies;
}

const vector<Product*>& DataBase::getProducts() const {
	return products;
}

vector<Prescription> DataBase::getPrescriptions() const {
	return prescriptions;
}

vector<StaffMember> DataBase::getStaff() const {
	return staff;
}

void DataBase::showAllClients(){
	printVector(clients);
}

void DataBase::showAllPharmacies(){
	for(unsigned int i = 0; i < pharmacies.size();i++)
		cout << pharmacies.at(i).getInfo()<< endl;
}

void DataBase::showAllStaff(){
	for(unsigned int i = 0; i < staff.size();i++)
		cout << staff.at(i).getInfo()<< endl;
}

void DataBase::addClient(){
	string n;
	string addr;
	unsigned int  contribNo;
	cout  << "Name: ";
	getline(cin, n);
	cout << "Address: ";
	getline(cin, addr);
	cout << "Identification Number: ";
	contribNo = checkForInt();
	Client * cli = new Client(n, addr, contribNo);
	clients.push_back(*cli);
}

void DataBase::addFarmacy(){
	string n;
	string addr;
	string m;
	cout  << "Name: ";
	getline(cin, n);
	cout << "address: ";
	getline(cin, addr);
	cout << "manager: ";
	getline(cin, m);
	Pharmacy f(n, addr, m);
	pharmacies.push_back(f);
}

void DataBase::addStaffMember(){
	string n;
	string addr;
	unsigned int cN, sal;
	string ph;
	string pos;
	cout  << "name: ";
	getline(cin, n);
	cout << "adress: ";
	getline(cin, addr);
	cout << "contrib number: ";
	cN = checkForInt();
	cout << "salary: ";
	sal = checkForInt();
	cin.ignore();
	cout  << "pharmacy: ";
	getline(cin, ph);
	cout << "position: ";
	getline(cin,pos);
	StaffMember f(n, addr, cN,sal,ph, pos);
	staff.push_back(f);
}

void DataBase::readProductsFile(){
	ofstream myfile;
	myfile.open(productsFile);
	string name, description;
	bool medicine;
	int price;
	while(!myfile.eof()){

	}
}

/*   OPEN FILES  */
void DataBase::openClientsFile(){
	ifstream infich;
	char aux;
	string textLine,adress, name;
	unsigned int contribNo;

	infich.open(clientsFile);
	if (!infich.fail()) {

		while (getline(infich, textLine)) {

			istringstream cardStream (textLine);


				name = readComplexString(cardStream, ';');

			adress = readComplexString(cardStream, ';');

			cardStream >> contribNo >> aux;

			clients.push_back(Client(name,adress,contribNo));
		}
	}else {
		throw ErrorOpeningFile(clientsFile);
	}

	/*ifstream myReadFile;
	myReadFile.open("t.txt");
	string output;

	while(getline(myReadFile, output)){
		cout << output << endl;

		int pos = output.find_first_of(" ", 0);

		string final = output.substr(pos + 1, output.size() - pos);
		cout << final << endl;
	}*/
}

void DataBase::openPharmaciesFile(){
	ifstream infich;
	string textLine,adress, name, manager="joao";

	infich.open(clientsFile);
	if (!infich.fail()) {

		while (getline(infich, textLine)) {

			istringstream cardStream (textLine);

			name = readComplexString(cardStream, ';');

			adress = readComplexString(cardStream, ';');

			//   manager = readComplexString(cardStream, ' ');

			pharmacies.push_back(Pharmacy(name,adress,manager));
		}
	}else {
		throw ErrorOpeningFile(pharmaciesFile);
	}
}

void DataBase::openStaffFile(){
	ifstream infich;
	string textLine,adress, name,ph,pos;
	unsigned int contribNo,sal;
	char aux;

	infich.open(clientsFile);
	if (!infich.fail()) {

		while (getline(infich, textLine)) {

			istringstream cardStream (textLine);

			name = readComplexString(cardStream, ';');

			adress = readComplexString(cardStream, ';');

			cardStream >> contribNo >> aux;

			cardStream >> sal >> aux;

			ph = readComplexString(cardStream, ';');

			pos = readComplexString(cardStream, ';');

			staff.push_back(StaffMember(name,adress,contribNo,sal,ph,pos));
		}
	}else {
		throw ErrorOpeningFile(pharmaciesFile);
	}
}

/*
this->productsFile = productsFile;
	this->clientsFile = clientsFile;
	this->pharmaciesFile = pharmaciesFile;
	this->staffFile = staffFile;
	this->salesFile = salesFile;
	*/
void DataBase::writeToProductsFile() {
	writeToFile(productsFile, products);
}
void DataBase::writeToPharmaciesFile() {
	writeToFile(pharmaciesFile, pharmacies);
}

void DataBase::writeToClientsFile() {
	writeToFile(clientsFile, clients);
}

void DataBase::writeToStaffFile() {
	writeToFile(staffFile, staff);
}

void DataBase::writeToSalesFile(){
	writeToFile(salesFile, sales);
}

string DataBase::readComplexString (istringstream &ss, char separate) {
	string final, auxString;
	char aux;

	do {
		ss >> auxString;
		final += auxString;
		ss.get(aux);
		ss.get(aux);

		if (aux != separate) {
			final += " ";
			ss.unget();
		}
	} while (aux != separate);

	return final;
}
