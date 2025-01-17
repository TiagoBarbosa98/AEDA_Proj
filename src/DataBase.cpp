#include "DataBase.h"
#include "PrintsNSorts.h"

typedef BSTItrIn<Client> cItr;

DataBase::DataBase(): clientsA(Client()){
	productsFile = "TextFiles/Products.txt";
	clientsFile = "TextFiles/Clients.txt";
	pharmaciesFile = "TextFiles/Pharmacies.txt";
	staffFile = "TextFiles/Staff.txt";
	salesFile = "TextFiles/Sales.txt";
	prescFile = "TextFiles/Prescriptions.txt";
	files.insert("TextFiles/Products.txt");
	files.insert("TextFiles/Clients.txt");
	files.insert("TextFiles/Pharmacies.txt");
	files.insert("TextFiles/Staff.txt");
	files.insert("TextFiles/Sales.txt");
	files.insert("TextFiles/Prescriptions.txt");

}

DataBase::DataBase(string productsFile, string clientsFile, string pharmaciesFile, string staffFile, string salesFile, string prescFile): clientsA(Client()){
	this->productsFile = productsFile;
	this->clientsFile = clientsFile;
	this->pharmaciesFile = pharmaciesFile;
	this->staffFile = staffFile;
	this->salesFile = salesFile;
	this->prescFile = prescFile;
	files.insert("TextFiles/Products.txt");
	files.insert("TextFiles/Clients.txt");
	files.insert("TextFiles/Pharmacies.txt");
	files.insert("TextFiles/Staff.txt");
	files.insert("TextFiles/Sales.txt");
	files.insert("TextFiles/Prescriptions.txt");
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
	priority_queue <Product> temporary;
	while (!products.empty()) {
		cout << products.top() << endl << endl;
		temporary.push(products.top());
		products.pop();
	}

	while (!temporary.empty()) {
		products.push(temporary.top());
		temporary.pop();
	}
}

Product DataBase::getProductByName(string name){
	priority_queue <Product> temporary, temporary2;
	while (!products.empty()) {
		temporary.push(products.top());
		temporary2.push(products.top());
		products.pop();
	}

	while (!temporary2.empty()) {
		products.push(temporary2.top());
		temporary2.pop();
	}

	while (!temporary.empty()) {
		if (temporary.top().getName() == name) {
			return temporary.top();
			break;
		}

		temporary.pop();
	}
	throw ItemDoesNotExist(name);
}

void DataBase::addProduct(){
	Product p1;
	string name, description, medicine, prescription;
	int code,quantity;
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
	cout << "Quantity: " << endl;
	quantity = checkForType<int>();
	cout << "IVA: " << endl;
	iva = checkForType<float>();
	cout << "Medicine (y/n): " << endl;
	cin.ignore();
	getline(cin, medicine);
	if(medicine == "n") 
		products.push(Product(name, description, price, quantity, iva, code, false));
	else if (medicine == "y"){
		cout << "Discount: " << endl;
		disc = checkForType<float>();
		cout << "Prescription Required (y/n): " << endl;
		cin.ignore();
		getline(cin, prescription);
		if(prescription == "y") Medicine p1(name, description, price, quantity, iva, code, disc, true);
		products.push(Medicine(name, description, price, quantity,  iva, code, disc, false));
	}
}

void DataBase::removeProduct(){
	priority_queue <Product> temporary;
	cout << "Enter Product Name: " << endl;
	cin.ignore();
	string name;
	getline(cin, name);
	bool found = false;

	Product p = products.top();

	while (!products.empty()) {

		if (products.top().getName() == name) {
			p = products.top();
			products.pop();
			found = true;
		}
		else {
			temporary.push(products.top());
			products.pop();
		}
	}

	while (!temporary.empty()) {
		products.push(temporary.top());
		temporary.pop();
	}

	if (!found)
		throw ItemDoesNotExist (name);
}

void DataBase::addClient(){
	string n;
	string addr;
	string dis;
	unsigned int  contribNo;
	cout  << "Name: ";
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
	cout << "Enter client's ID: ";
	unsigned int id;
	cin >> id;
	while(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "That is not a valid number. Please try again.\n\n";
		cin >> id;
	}

	Client c = clientExists(id);
	Client notFound(0);
	if(c == notFound){
		cout << "No client found with that ID.";
		return;
	}
	clientsA.remove(c);

	cout << "Successful removal!\n\n";

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void DataBase::addSale(){
	bool sale = false;
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
			if (!removeQuantity(pname, q))
				continue;
			else
				s->addProdPriceQtt(p, q);
			sale = true;
			
		}
		catch(ItemDoesNotExist & e){
			e.printMsg();
			continue;
		}
	}
	if(sale)
		sales.push_back(*s);
}

bool DataBase::removeQuantity(string name, int quantity) {
	priority_queue <Product> temporary2;
	priority_queue <Product> temporary;

	while (!products.empty()) {
		temporary.push(products.top());
		products.pop();
	}

	while (!temporary.empty()) {

		if (temporary.top().getName() == name) {
			if(temporary.top().getQuantity() >= quantity){
				int n = temporary.top().getQuantity() - quantity;
				string name = temporary.top().getName();
				int c = temporary.top().getCode();
				string desc = temporary.top().getDescription();
				float i = temporary.top().getIva();
				bool m = temporary.top().getMedicine();
				float p = temporary.top().getPrice();
				float tp = temporary.top().getTotalPrice();
				Product productNew(name, desc, p, n, i, c, m);
				temporary.pop();
				temporary.push(productNew);
			}
			else {
				cout << "Not enough" << endl;
				return false;
			}
		}
		temporary2.push(temporary.top());
		temporary.pop();
	}
	while (!temporary2.empty()) {
		products.push(temporary2.top());
		temporary2.pop();
	}
	return true;
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
	showPharmaciesNames();
	cout << "Pharmacy to remove: " << endl;
	string name;
	getline(cin, name);
	cout << endl;
	for(vector<Pharmacy>::iterator it = pharmacies.begin(); it != pharmacies.end(); it++){
		if(it->getName() == name){
			it->setStaffPhToNone();
			vector<StaffMember> staffm = it->getStaff();
			pharmacies.erase(it);

			cout << "Successful deletion. Would you like to relocate the staff from this pharmacy (y/n)?\n";
			string in;
			cin >> in;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			if(in == "Y" || in == "y" || in == "yes" || in == "Yes"){
				assignStaff(staffm);
			}
			return;
		}
		else{
			cout << "No pharmacies with that name are available.\n";
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
	cout  << "Name: ";
	getline(cin, n);
	cout << "Address: ";
	getline(cin, addr);
	cout << "Identification Number: ";
	cN = checkForType<unsigned int>();
	cout << "salary: ";
	sal = checkForType<unsigned int>();
	cin.ignore();
	cout  << "Pharmacy: ";
	checkPhName();
	cout << "Position: ";
	getline(cin,pos);
	StaffMember f(n, addr, cN,sal,ph, pos);
	staff.push_back(f);

	for(unsigned int i = 0; i < pharmacies.size(); i++){
		if(pharmacies[i].getName() == ph){
			pharmacies[i].addStaff(f);
		}
	}
}

void DataBase::removeStaffMember(){
	showAllStaff();
	cout << "Staff to be removed (type None to cancel): " << endl;
	string name;
	getline(cin, name);

	if(name == "None")
		return;

	//TODO test
	for(unsigned int i = 0; i < pharmacies.size(); i++){
		if(pharmacies[i].removeStaff(name)){
			cout << "name found\n\n";
			break;
		}
	}
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

	string final = in.substr(pos + 2,in.size() - pos);

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
	hour = 2;
	mins = 2;

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
	unordered_set<string>::iterator it = files.find(clientsFile);
	string name, addr, cn, garbage, dis = "ejwio sw ";

	infich.open(*it);
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

StaffMember* DataBase::getStaffM(string name){
	//possivel excecao aqui
	for(unsigned int i = 0; i < staff.size(); i++){
		if(staff[i].getName() == name){
			StaffMember *p = &staff[i];
			return p;
		}
	}
	return new StaffMember();
}

void DataBase::openPharmaciesFile(){
	ifstream infich;
	unordered_set<string>::iterator it = files.find(pharmaciesFile);
		infich.open(*it);
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
					StaffMember *sm = getStaffM(staffName);
					tmp.push_back(*sm);

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
	unordered_set<string>::iterator it;
	it = files.find(productsFile);

	infich.open(*it);
	if (!infich.fail()) {
		string name, desc, c, disc, p, m, presc, garbage;
		string q;
		int code, quantity;
		float discount, price;
		bool medicine;
		bool prescr;

		while(getline(infich, name)){

			getline(infich, c);
			getline(infich, p);
			getline(infich, q);
			getline(infich, desc);
			getline(infich, m);

			name = parse(name);
			c = parse(c);
			p = parse(p);
			q = parse(q);
			desc = parse(desc);
			m = parse(m);

			string newName;
			code =  stoi(c);
			quantity = stoi(q);
			price = stof(p);
			
			if (m == "1") {
				medicine = true;
			}
			else {
				medicine = false;
			}
				//checking if prod is medicine and getting rest of info if it is
				getline(infich, disc);
				
				if (disc.size() > 1 & !infich.eof()) {
					getline(infich, presc);

					disc = parse(disc);
					presc = parse(presc);

					discount = stof(disc);
					if (presc == "1")
						prescr = true;
					else
						prescr = false;

					getline(infich, garbage);

					Medicine prod(name, desc, price, quantity, 0, code, discount, prescr);
					products.push(prod);
				}
			else{
				
				Product prod(name, desc, price, quantity, 0, code, medicine);
				products.push(prod);
			}
		}

	}else {
		throw ErrorOpeningFile(productsFile);
	}
}

void DataBase::openStaffFile(){
	ifstream infich;

	unordered_set<string>::iterator it = files.find(staffFile);

	infich.open(*it);
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
	unordered_set<string>::iterator it = files.find(prescFile);
	infich.open(*it);
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

void DataBase::showClientsByDistrict(){
	string dis;
	BSTItrIn<Client> itr(clientsA);

	cout << "District name: ";
	getline(cin, dis);
	cout << "Clients from district " << dis << ":\n\n";

	while(!itr.isAtEnd()){
		if(itr.retrieve().getDistrict() == dis){
			cout << itr.retrieve() << endl;
		}
		itr.advance();
	}
}

void DataBase::getClientInfo() {
	unsigned int nc;
	cout << "Client ID: ";
	nc = checkForType<unsigned int>();
	cout << endl;
	vector<unsigned int> l;
	Client toFind("", "", "", nc, l);
	Client notFound(0);

	//This isnt working for some reason TODO
	Client res = clientsA.find(toFind);

	if(clientExists(nc) == notFound){
		cout << "No client with such identification number.\n\n";
	}
	else
		cout << clientExists(nc);
}

Client DataBase::clientExists(unsigned int nc){
	BSTItrIn<Client> it(clientsA);
	Client c(nc);
	while(!it.isAtEnd()){
		if(it.retrieve() == nc)
			return it.retrieve();

		it.advance();
	}

	return Client(0);
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

	cout << endl << endl;

}

void DataBase::showStaffWithoutPh(){
	cout << "Staff with no current pharmacy:\n";
	for(unsigned int i = 0; i < staff.size(); i++){
		if(staff[i].getPharmacy() == "None")
			cout << "  -" << staff[i].getName() << endl;
	}
	cout << endl;
}

string DataBase::checkPhName(){
	if(pharmacies.empty()){
		cout << "There are no pharmacies available yet. Please create one first.\n\n";
		return "None";
	}

	string in;
	getline(cin, in);
	for(unsigned int i = 0; i < pharmacies.size(); i++){
		if(in == pharmacies[i].getName() || in == "None"){
			return in;
		}
	}

	while(true){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, in);
		for(unsigned int i = 0; i < pharmacies.size(); i++){
			if(in == pharmacies[i].getName() || in == "None"){
				return in;
			}
		}
		cout << "No pharmacies with that name are available. Try again.\n";
	}
}

void DataBase::assignStaff(vector<StaffMember> members){
	for(unsigned int i = 0; i < members.size(); i++){
		StaffMember *currentStaff = getStaffM(members[i].getName());

		cout << currentStaff->getName() << " goes to Pharmacy (type None to not assign):\n";

		string in = checkPhName();
		currentStaff->setPharmacy(in);
		cout << endl << endl;

		for(unsigned int j = 0; j < pharmacies.size(); j++){
			if(pharmacies[j].getName() == in){
				pharmacies[j].addStaff(*currentStaff);
				break;
			}
		}

	}
	cout << "\nAllocation complete!\n\n";
}

void DataBase::showPharmaciesNames(){
	cout << "Available pharmacies:\n";
		for(unsigned int i = 0; i < pharmacies.size(); i++){
				cout << pharmacies[i].getName() << "\n";
			}
		cout << endl << endl;
}

void DataBase::assignStaffWithNoPh(){
	vector<StaffMember> members;

	for(unsigned int i = 0; i < staff.size(); i++){
		if(staff[i].getPharmacy() == "None"){
			members.push_back(staff[i]);
		}
	}
	if(members.size() < 1){
		cout << "All staff members belong to a pharmacy already!\n\n";
		return;
	}

	showStaffWithoutPh();
	showPharmaciesNames();

	assignStaff(members);
}

void DataBase::changePharmacyInfo(){
	cout << "All pharmacies:\n";
	showAllPharmacies();

	string in;
	cout << "Which pharmacy would you like to modify?\nName(type None to cancel): ";
	getline(cin, in);
	cout << endl;

	if(in == "None")
		return;

	string ans;
	for(unsigned int i = 0; i < pharmacies.size(); i++){
		if(in == pharmacies[i].getName()){
			cout << "Change Name(type No to remain unaltered): ";
			getline(cin, ans);

			if(ans != "No" && ans != "no")
				pharmacies[i].setName(ans);


			cout << "\n\nChange Manager from current staff.\n";
			cout << "Staff from this pharmacy:\n";

			pharmacies[i].showStaffsName();

			cout << "New Manager (type No to remain unaltered):";
			getline(cin, ans);
			if(ans != "No" && ans != "no"){
				if(getStaffM(ans)->getName() != "error"){
					pharmacies[i].setManager(ans);
					getStaffM(ans)->setPosition("Manager");
				}
				else if(getStaffM(ans)->getName() == "error")
					cout << "No Staff Member with that name exists.";
			}


			cout << "\n\nAdd Staff Member.\n\n";
			cout << "Staff Members:\n\n";
			showAllStaff();
			cout << "New Staff Member (type No to remain unaltered):";
			getline(cin, ans);
			if(ans != "No" && ans != "no"){
				StaffMember *s = getStaffM(ans);
				if(s->getName() != "error"){
					pharmacies[i].addStaff(*s);
					removeStaffM(s->getName());
					s->setPharmacy(pharmacies[i].getName());
				}
				else if(getStaffM(ans)->getName() == "error")
					cout << "No Staff Member with that name exists.";
			}
			return;
		}
	}
	throw(ItemDoesNotExist(in));
}

void DataBase::removeStaffM(string name){
	for(unsigned int i = 0; i < pharmacies.size(); i++){
		if(pharmacies[i].containsStaff(name)){
			pharmacies[i].removeStaff(name);
			staffPhToNone(name);
			return;
		}
	}
}

void DataBase::staffPhToNone(string name){
	for(unsigned int i = 0; i < staff.size(); i++){
		if(staff[i].getName() == name){
			staff[i].setPharmacy("None");
			return;
		}
	}
}


void DataBase::lessProductsThan() {
	
	cout << "N: " << endl;
	int n;
	cin >> n;

	priority_queue <Product> temporary, temporary2;

	while (!products.empty()) {
		temporary.push(products.top());
		temporary2.push(products.top());
		products.pop();
	}

	while (!temporary2.empty()) {
		products.push(temporary2.top());
		temporary2.pop();
	}
	bool found = false;
	while (!temporary.empty()) {

		if (temporary.top().getQuantity() < n) {
			cout << temporary.top() << endl;
			found = true;
		}
		temporary.pop();
	}

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (!found)
		cout << "No product with stock lower than " << n << "." << endl;
}
