#include "DataBase.h"
#include "Medicine.h"
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
	printVector(pharmacies);
}

void DataBase::showAllStaff(){
	printVector(staff);
}

void DataBase::showAllPrescriptions(){
	printVector(prescriptions);
}

void DataBase::addPrescription(){
	cout << "Number: " << endl;
	int n = checkForType<int>();
	cout << "Physician: " << endl;
	string dr;
	cin.ignore();
	getline(cin, dr);
	cout << "Pacient: " << endl;
	string c;
	cin.ignore();
	getline(cin, c);
	string p;
	cout << "For: " << endl;
	cin.ignore();
	getline(cin, p);
	Prescription p1(n, c, dr, p);
	prescriptions.push_back(p1);

}

void DataBase::showAllProducts(){
	printVector(products);
}

Product DataBase::getProductByName(string name) const{
	for(vector<Product*>::const_iterator it = products.begin(); it != products.end(); it++)
		if((*it)->getName() == name) return (*(*it));
	throw ItemDoesNotExist(name);
}

void DataBase::addProduct(){
	Product * p1;
	string name, description, medicine, prescription;
	int code;
	float price, iva, disc;
	medicine = 5;
	cout << "Name: " << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Description: " << endl;
	getline(cin, description);
	cout << "Code: " << endl;
	code = checkForType<int>();
	cout << "Price: " << endl;
	price = checkForType<float>();
	cout << "IVA: " << endl;
	iva = checkForType<float>();
	cout << "Medicine (y/n): " << endl;
	cin.ignore();
	getline(cin, medicine);
	if(medicine != "y") p1 = new Product(name, description, price, iva, code, false);
	else{
		cout << "Discount: " << endl;
		disc = checkForType<float>();
		cout << "Prescription Required (y/n): " << endl;
		cin.ignore();
		getline(cin, prescription);
		if(prescription == "y") p1 = new Medicine(name, description, price, iva, code, disc, true);
		else p1 = new Medicine(name, description, price, iva, code, disc, false);
	}
	products.push_back(p1);
}

void DataBase::removeProduct(){
	cout << "Enter Product Name: " << endl;
	cin.ignore();
	string name;
	getline(cin, name);
	for(vector<Product *>::iterator it = products.begin(); it != products.end(); it++)
		if ((*it)->getName() == name){
			products.erase(it);
			return;
		}
	throw ItemDoesNotExist (name);
}

void DataBase::addClient(){
	string n;
	string addr;
	unsigned int  contribNo;
	cout  << "Name: ";
	cin.ignore();
	getline(cin, n);
	cout << "Address: ";
	getline(cin, addr);
	cout << "Identification Number: ";
	contribNo = checkForType<int>();
	Client * cli = new Client(n, addr, contribNo);
	clients.push_back(*cli);
}

void DataBase::removeClient(){
	cout << "Enter client name: " << endl;
	cin.ignore();
	string name;
	getline(cin, name);
	for(vector<Client>::iterator it = clients.begin(); it != clients.end(); it++)
		if(it->getName() == name){
			clients.erase(it);
			return;
		}
	throw ItemDoesNotExist(name);
}

void DataBase::showAllSales(){
	printVector(sales);

}

void DataBase::addSale(){
	Sale *s = new Sale();
	int op = 0;
	while(op != 2){
		cout << "1) Add Product " << endl;
		cout << "2) Finish " << endl;
		op = checkForType<int>();
		if(op != 1) continue;
		string pname;
		cout << "Product Name: " << endl;
		cin.ignore();
		getline(cin, pname);
		try{
			Product p = getProductByName(pname);
			cout << "Quantity: " << endl;
			int q = checkForType<int>();
			s->addProdPriceQtt(p, q);

		}
		catch(ItemDoesNotExist & e){
			e.printMsg();
			continue;
		}
	}

	sales.push_back(*s);
}

void DataBase::removeSale(){
	cout << "Enter Sale code: " << endl;
	int c = checkForType<int>();
	for(vector<Sale>::iterator it = sales.begin(); it != sales.end(); it++){
		if((it)->getCode() == c) {
			sales.erase(it);
			return;
		}
	}
	throw ItemDoesNotExist("Sale");
}

void DataBase::addPharmacy(){
	string n;
	string addr;
	string m;
	cout  << "Name: ";
	cin.ignore();
	getline(cin, n);
	cout << "Address: ";
	getline(cin, addr);
	cout << "Manager: ";
	getline(cin, m);
	Pharmacy f(n, addr, m);
	pharmacies.push_back(f);
}

void DataBase::removePharmacy(){
	cout << "Name: " << endl;
	cin.ignore();
	string name;
	getline(cin, name);
	for(vector<Pharmacy>::iterator it = pharmacies.begin(); it != pharmacies.end(); it++){
		if(it->getName() == name){
			pharmacies.erase(it);
			return;
		}
	}
	throw ItemDoesNotExist (name);
}

void DataBase::addStaffMember(){
	string n;
	string addr;
	unsigned int cN, sal;
	string ph;
	string pos;
	cout  << "name: ";
	cin.ignore();
	getline(cin, n);
	cout << "adress: ";
	getline(cin, addr);
	cout << "contrib number: ";
	cN = checkForType<int>();
	cout << "salary: ";
	sal = checkForType<int>();
	cin.ignore();
	cout  << "pharmacy: ";
	getline(cin, ph);
	cout << "position: ";
	getline(cin,pos);
	StaffMember f(n, addr, cN,sal,ph, pos);
	staff.push_back(f);
}

void DataBase::removeStaffMember(){
	cout << "Enter name: " << endl;
	cin.ignore();
	string name;
	getline(cin, name);
	for(vector<StaffMember>::iterator it = staff.begin(); it != staff.end(); it++){
		if(it->getName() == name) {
			staff.erase(it);
			return;
		}
	}
	throw ItemDoesNotExist(name);
}


/*   OPEN FILES

string DataBase::parse(string in){

	int pos = in.find_first_of(':', 0);

	string final = in.substr(pos + 2, in.size() - pos);

	return final;

}

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

}

string DataBase::parseStaff(string in){
	int pos = in.find_first_of('-', 0);

	string final = in.substr(pos + 1, in.size() - pos);

	return final;
}


StaffMember DataBase::getStaffM(string name){
	//possivel excecao aqui
	for(unsigned int i = 0; i < staff.size(); i++){
		if(staff[i].getName() == name){
			return staff[i];
		}
	}
	return StaffMember();
}

void DataBase::openPharmaciesFile(){
	ifstream infich;

		infich.open(pharmaciesFile);
		if (!infich.fail()) {

			while(!infich.eof()){
				string name, address, manager, garbage, staffName;

				getline(infich, name);
				getline(infich, address);
				getline(infich, manager);
				getline(infich, garbage);
				getline(infich, staffName);

				name = parse(name);
				address = parse(address);
				manager = parse(manager);

				vector<StaffMember> tmp;
				while(staffName.size() > 1 && !infich.eof()){
					staffName = parseStaff(staffName);
					StaffMember s = getStaffM(staffName);
					tmp.push_back(s);
					getline(infich, staffName);
				}
				Pharmacy pharm(name, address, manager, tmp);
				pharmacies.push_back(pharm);
			}
		}
		else {
			throw ErrorOpeningFile(pharmaciesFile);
		}
}

void DataBase::openProductsFile(){
	ifstream infich;

	infich.open(productsFile);
	if (!infich.fail()) {

		while(!infich.eof()){

			string name, desc, c, disc, p, m, presc, garbage;
			int code;
			float discount, price;
			bool medicine;
			bool prescr;

			getline(infich, name);
			getline(infich, c);
			getline(infich, p);
			getline(infich, desc);
			getline(infich, m);


			name = parse(name);
			c = parse(c);
			p = parse(p);
			desc = parse(desc);
			m = parse(m);

			code = stoi(c);
			price = stof(p);

			if(m == "1")
				medicine = true;
			else
				medicine = false;

			//checking if prod is medicine and getting rest of info if it is
			getline(infich, disc);
			if(disc.size() > 1){
				getline(infich, presc);

				disc = parse(disc);
				presc = parse(presc);

				discount = stof(disc);
				if(presc == "1")
					prescr = true;
				else
					prescr = false;

				getline(infich, garbage);

				//Medicine::Medicine(string n, string desc, float p, float iva, int c, float disc, bool nr)
				Product *prod = new Medicine(name, desc, price, 0, code, discount, prescr);
				products.push_back(prod);
			}
			else{
				Product *prod = new Product(name, desc, price, 0, code, medicine);
				products.push_back(prod);
			}

		}

	}else {
		throw ErrorOpeningFile(productsFile);
	}
}

void DataBase::openStaffFile(){
	ifstream infich;

	infich.open(staffFile);
	if (!infich.fail()) {

		while(!infich.eof()){

			string name, address, salary, pharmacy, pos, id, garbage;

			getline(infich, name);
			getline(infich, address);
			getline(infich, id);
			getline(infich, salary);
			getline(infich, pharmacy);
			getline(infich, pos);

			name = parse(name);
			address = parse(address);
			salary = parse(salary);
			pharmacy = parse(pharmacy);
			pos = parse(pos);
			id = parse(id);

			int sal = stoi(salary);
			int nc = stoi(id);

			StaffMember s(name, address, nc, sal, pharmacy, pos);
			staff.push_back(s);

			getline(infich, garbage);
		}

	}else {
		throw ErrorOpeningFile(staffFile);
	}

}

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
}*/
