#include "DataBase.h"
#include "PrintsNSorts.h"


DataBase::DataBase(): clientsA(Client()){
	productsFile = "TextFiles/Products.txt";
	clientsFile = "TextFiles/Clients.txt";
	pharmaciesFile = "TextFiles/Pharmacies.txt";
	staffFile = "TextFiles/Staff.txt";
	salesFile = "TextFiles/Sales.txt";
	prescFile = "TextFiles/Prescriptions.txt";

}

DataBase::DataBase(string productsFile, string clientsFile, string pharmaciesFile, string staffFile, string salesFile, string prescFile): clientsA(Client()){
	this->productsFile = productsFile;
	this->clientsFile = clientsFile;
	this->pharmaciesFile = pharmaciesFile;
	this->staffFile = staffFile;
	this->salesFile = salesFile;
	this->prescFile = prescFile;

	try {
		openProductsFile();
		openStaffFile();
		openSalesFile();
		openClientsFile();
		openPharmaciesFile();
		openPrescriptionFile();
	} catch (ErrorOpeningFile &name) {
		cout << "Error opening the file " << name.getFileName() << endl
				<< "No data was imported.\n";

	}
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

void DataBase::showAllSales(){
	printVector(sales);
}

void DataBase::addPrescription(){
	cout << "Number: " << endl;
	int n = checkForType<unsigned int>();
	cout << "Physician: " << endl;
	string dr;
	cin.ignore();
	getline(cin, dr);
	cout << "Pacient: " << endl;
	string c;
	getline(cin, c);
	string p;
	cout << "For: " << endl;
	getline(cin, p);
	Prescription p1(n, c, dr, p);
	prescriptions.push_back(p1);

}

void DataBase::showAllProducts(){
	for(unsigned int i = 0; i < products.size(); i++){
		cout << products[i]->display() << endl;
	}
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
	code = checkForType<unsigned int>();
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
	string dis;
	unsigned int  contribNo;
	cout  << "Name: ";
	cin.ignore();
	getline(cin, n);
	cout << "District: ";
	getline(cin, dis);
	cout << "Address: ";
	getline(cin, addr);
	cout << "Identification Number: ";
	contribNo = checkForType<unsigned int>();
	vector<unsigned int> h;
	Client * cli = new Client(n, dis, addr, contribNo, h);
	clients.push_back(*cli);
	clientsA.insert(*cli);
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


void DataBase::addSale(){
	Sale *s = new Sale();
	int op = 0;
	while(op != 2){
		cout << "1) Add Product " << endl;
		cout << "2) Finish " << endl;
		op = checkForType<unsigned int>();
		if(op != 1) continue;
		string pname;
		cout << "Product Name: " << endl;
		cin.ignore();
		getline(cin, pname);
		try{
			Product p = getProductByName(pname);
			cout << "Quantity: " << endl;
			int q = checkForType<unsigned int>();
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
	int c = checkForType<unsigned int>();
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
	cN = checkForType<unsigned int>();
	cout << "salary: ";
	sal = checkForType<unsigned int>();
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



/*   OPEN FILES  */

string DataBase::parse(string in){

	int pos = in.find_first_of(':', 0);

	string final = in.substr(pos + 2, in.size() - pos);

	return final;

}

Sale DataBase::getSale(unsigned int code){
	//possivel excecao aqui
	for(unsigned int i = 0; i < sales.size(); i++){
		if(sales[i].getCode() == code){
			return sales[i];
		}
	}
	return Sale();
}

tm DataBase::parseDate(string in) {
	tm date;
	string d, m, y, h, min, garb;

	unsigned int day = 1, month = 1, year = 1, hour = 1, mins = 1;

	istringstream iss(in);
	getline(iss, d, '/');
	getline(iss, m, '/');
	getline(iss, y, ' ');
	getline(iss, h, ':');
	getline(iss, min);
	day = stoi(d);
	month = stoi(m);
	year = stoi(y);
	hour = stoi(h);
	mins = stoi(min);

	date.tm_mday = day;
	date.tm_mon = month - 1;
	date.tm_year = year - 1900;
	date.tm_hour = hour;
	date.tm_min = mins;

	return date;
}


//TODO
void DataBase::openSalesFile(){
	ifstream infich;
	string salen, date, prod, garbage, sprice;
	string prodName, prodQtt, prodPrice;
	int number, qtt;
	float price, totalprice;

		infich.open(salesFile);
		if (!infich.fail()) {
			while(!infich.eof()){
			getline(infich, salen);
			getline(infich, date);
			getline(infich, sprice);
			getline(infich, garbage);
			getline(infich, prod);

			salen = parse(salen);
			date = parse(date);
			sprice = parse(sprice);

			number = stoi(salen);
			totalprice = stof(sprice);

			vector<tuple<string, unsigned int, float>> tmp;
			//while(!infich.eof() && prod.size() > 1);{
			while(true){
				istringstream iss(prod);
				getline(iss, garbage, ' ');
				getline(iss, prodName, ',');
				getline(iss, garbage, ':');
				getline(iss, garbage, ' ');
				getline(iss, prodQtt, ',');
				getline(iss, garbage, ':');
				getline(iss, garbage, ' ');
				getline(iss, prodPrice);

				price = stof(prodPrice);
				qtt = stoi(prodQtt);

				tuple<string, unsigned int, float>t(prodName, qtt, price);
				tmp.push_back(t);
				getline(infich, prod);
				if(infich.eof() || prod.size() < 1)
					break;
			}
			tm date2 = parseDate(date);
			tm *time = &date2;

			Sale s(time, tmp, totalprice);
			sales.push_back(s);
			}
		}else {
			throw ErrorOpeningFile(salesFile);
		}
}

void DataBase::openClientsFile(){
	ifstream infich;
	string name, addr, cn, garbage, dis = "ejwio sw ";

	infich.open(clientsFile);
	if (!infich.fail()) {
		while(!infich.eof()){
			string n, addr, cn, sale;
			unsigned int saleI, cnI;

			getline(infich, name);
			getline(infich, addr);
			getline(infich, cn);
			getline(infich, dis);
			getline(infich, garbage);
			getline(infich, sale);

			name = parse(name);
			addr = parse(addr);
			cn = parse(cn);
			cnI = stoi(cn);
			dis = parse(dis);

			vector<unsigned int > tmp;
			while(sale.size() > 1 & !infich.eof()){
				sale = parseStaff(sale);
				saleI = stoi(sale);

				tmp.push_back(saleI);

				getline(infich, sale);
			}
			Client c(name, dis, addr, cnI, tmp);
			clients.push_back(c);
			clientsA.insert(c);
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
				while(staffName.size() > 1 & !infich.eof()){
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
			if(disc.size() > 1 & !infich.eof()){
				getline(infich, presc);

				disc = parse(disc);
				presc = parse(presc);

				discount = stof(disc);
				if(presc == "1")
					prescr = true;
				else
					prescr = false;

				getline(infich, garbage);

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


void DataBase::openPrescriptionFile() {
	ifstream infich;
	string number, doctor, client, garbage, prod;
		//TODO change file
	infich.open(prescFile);
	if (!infich.fail()) {
		while(!infich.eof()){
			getline(infich, number);
			getline(infich, doctor);
			getline(infich, client);
			getline(infich, prod);
			getline(infich, garbage);

			number = parse(number);
			doctor = parse(doctor);
			client = parse(client);
			prod = parse(prod);

			int num = stoi(number);

			Prescription p(num, client, doctor, prod);
			prescriptions.push_back(p);
		}
	}
	else
		throw ErrorOpeningFile(prescFile);
}

void DataBase::writeToProductsFile() {
	writeToProductsFile2(productsFile);
}
void DataBase::writeToPharmaciesFile() {
	writeToFileW(pharmaciesFile, pharmacies);
}

void DataBase::writeToClientsFile() {
	writeToFileW(clientsFile, clients);
}

void DataBase::writeToStaffFile() {
	writeToFileW(staffFile, staff);
}

void DataBase::writeToSalesFile(){
	writeToSales(salesFile);
	//writeToFileW(salesFile, sales);
}

void DataBase::writeToPrescriptionFile() {
	writeToFileW(prescFile, prescriptions);
}

void DataBase::showAllClientsA(){
	BSTItrIn<Client> itr(clientsA);
	while(!itr.isAtEnd()){
		cout << itr.retrieve() << endl;
		itr.advance();
	}
}

void DataBase::searchClientsByDistrict(string dis){
	BSTItrIn<Client> itr(clientsA);
	cout << "District " << dis << " clients:\n\n";
	while(!itr.isAtEnd()){
		if(itr.retrieve().getDistrict() == dis){
			cout << "  " << itr.retrieve() << endl;
		}
		itr.advance();
	}
}

void DataBase::getClientInfo(unsigned int nc) {
	vector<unsigned int> l;
	Client toFind("", "", "", nc, l);
	Client notFound("", "", "", 0, l);

	//This isnt working for some reason TODO
	Client res = clientsA.find(toFind);

	if(res == notFound){
		cout << "No client with such identification number.\n";
	}
	else
		cout << res;
}

void DataBase::showClientsWithMostPurchases() {
	Client c1, c2, c3;
	BST<Client> clTemp = clientsA;
	BSTItrIn<Client> clItr(clTemp);
	BSTItrIn<Client> clItr2(clTemp);
	BSTItrIn<Client> clItr3(clTemp);

	c1 = clItr.retrieve();
	clItr.advance();

	while(!clItr.isAtEnd()){
		if(clItr.retrieve().getHistory().size() > c1.getHistory().size()){
			c1 = clItr.retrieve();
		}
		clItr.advance();
	}

	cout << "Top 3 clients with most purchases made.\n\n";
	cout << "1. " << c1 << "\n2. ";
	clTemp.remove(c1);
	///////////////////////////////

	c2 = clItr2.retrieve();
	clItr2.advance();

	while(!clItr2.isAtEnd()){
		if(clItr2.retrieve().getHistory().size() > c2.getHistory().size()){
			c2 = clItr2.retrieve();
		}
		clItr2.advance();
	}
	cout << c2 << "\n3. ";
	clTemp.remove(c2);
	///////////////////////////

	c3 = clItr3.retrieve();
	clItr3.advance();

	while(!clItr3.isAtEnd()){
		if(clItr3.retrieve().getHistory().size() > c3.getHistory().size()){
			c3 = clItr3.retrieve();
		}
		clItr3.advance();
	}
	cout << c3 << endl;

}


