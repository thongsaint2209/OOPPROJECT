#include"Employee.h"

void Employee::ViewAndSolvingRequests() {
	ifstream f1;

	string id;
	string type;
	int money;
	int status;

	
	f1.open("EmployeeRequestsList.txt", ios::in);


	if (!f1.is_open())
		cout << "Cannot open EmployeeRequestsList.txt\n";
	vector<Request> requestList;
	int count1 = 0;
	while (f1.good())
	{
		f1 >> id;

		f1 >> type;

		f1 >> money;

		f1 >> status;

		if (f1.eof())
			break;
		Request temp(id, type, money, status);

		requestList.push_back(temp);

		
		count1++;
	}

	f1.close();

	ifstream f2;

	string id1;
	string	name;
	string date;
	string	address;

	string phone;
	string mail;
	string Acctype;

	int	balance;

	int	duration;
	int	period;
	f2.open("Customer.txt", ios::in);


	if (!f2.is_open())
		cout << "Cannot open Customer.txt\n";

	vector<Customer> a;
	int count = 0;
	while (f2.good())
	{
		f2>> id1;
		f2.ignore();
		getline(f2, name);

		getline(f2, date);


		getline(f2, address);

		getline(f2, phone);

		getline(f2, mail);

		getline(f2, Acctype);

		f2 >> balance;
		f2 >> duration;
		f2 >> period;

		if (f2.eof())
			break;
		Customer temp(id1, name, date, address, phone, mail, Acctype, balance, duration, period);
		a.push_back(temp);
		f2.ignore(1, '\n');
		count++;

	}
	f2.close();
	for (int i = 0;i < requestList.size(); i++) {
		for (int j = 0;j < a.size();j++) {
			if (requestList[i].getId() == a[j].getId()) {
				if (requestList[i].getType() == "Deposit") {
					a[j]._balance += a[j].ClacInrest() + money;
					a[i]._duration =0 ;
					tradeHistory("Deposit", a[j].getname(), requestList[i].getMoney());
				}
				if (requestList[i].getType() == "Withdraw") {
					a[j]._balance += a[j].ClacInrest();
					if (a[j]._balance > money) {
						a[j]._balance -= money;
						a[j]._duration = 0;
						tradeHistory("Withdraw", a[j].getname(), requestList[i].getMoney());
					}
					IncreaseMerit();

				}
				requestList.erase(requestList.begin() + i);
			}
		}
	}
		

		fstream f;

		f.open("EmployeeRequestList.txt", ios::out);

		if (!f.is_open())
			cout << "Cannot open EmployeeRequestsList.txt\n";

		for (int i = 0; i < requestList.size(); i++)
		{

			f << requestList[i].getId() << endl;
			f << requestList[i].getType() << endl;
			f << requestList[i].getMoney() << endl;
			f << requestList[i].approvalStatus() << endl;
			if (i != requestList.size() - 1)
				f << endl;
		}

		f.close();
		fstream f3;
		f3.open("Customer.txt", ios::out);
		if (!f3.is_open())
			cout << "Cannot open Customer.txt\n";

		for (int i = 0; i < count; i++)
		{
			f3 << a[i]._id << endl;
			f3 << a[i]._name << endl;
			f3 << a[i]._birth << endl;
			f3 << a[i]._address << endl;
			f3 << a[i]._phone << endl;
			f3 << a[i]._mail << endl;
			f3 << a[i]._acctype << endl;
			f3 << a[i]._balance << endl;
			f3 << a[i]._duration << endl;
			f3 << a[i]._period << endl;
			f3 << endl;

		}
		f3.close();

		cout << "Saved successfully\n";
	

}
	void Employee::searchCustomer() {
		ifstream f1;
		vector<Customer> a;
		string id;
		string	name;
		string date;
		string	address;

		string phone;
		string mail;
		string Acctype;

		int	balance;

		int	duration;
		int	period;
		f1.open("Customer.txt", ios::in);


		if (!f1.is_open())
			cout << "Cannot open Customer.txt\n";

		int i = 0;
		int count = 0;
		while (f1.good())
		{
			f1 >> id;
			f1.ignore();
			getline(f1, name);

			getline(f1, date);


			getline(f1, address);

			getline(f1, phone);

			getline(f1, mail);

			getline(f1, Acctype);

			f1 >> balance;
			f1 >> duration;
			f1 >> period;


			if (f1.eof())
				break;
			Customer temp(id, name, date, address, phone, mail, Acctype, balance, duration, period);
			a.push_back(temp);
			f1.ignore(1, '\n');
			count++;
		}
		for (int i = 0; i < count; i++)
		{
			cout << "id :" << a[i].getId() << endl;
			cout << endl;
		}
		cout << "Choose id you want to dind information about customer   ";
		while (getchar() != '\n');
		getline(cin, id);


		for (int i = 0; i < count; i++)
		{
			if (a[i].getId() == id)
			{
				cout << "Request #" << i + 1 << endl;
				cout << "id :" << a[i].getId() << endl;
				cout << "name :" << a[i].getname() << endl;
				cout << "birthday :" << a[i].getbirth() << endl;
				cout << "address :" << a[i].getaddress() << endl;
				cout << "phone :" << a[i].getphone() << endl;
				cout << "mail:" << a[i].getmail() << endl;
				cout << "Acc type :" << a[i].getacctype() << endl;
				cout << "balance :" << a[i].getBalance() << endl;
				cout << "duration :" << a[i].getDuration() << endl;
				cout << "period :" << a[i].getPeriod() << endl;
				cout << endl;
			}
		}
		f1.close();
	}
	void Employee::Resign() {
		string reason;
		cout << "Please describe the reasons for resignation \n ";
		cin >> reason;
		fstream f3;
		vector<string> result;
		f3.open("ResignList.txt", ios::in);
		if (!f3.is_open())
			cout << "Cannot open ResignList.txt\n";

		while (f3.good())
		{
			string s;
			getline(f3, s);
			result.push_back(s);
			if (f3.eof()) break;
			
		}
		result.push_back(_id);
		result.push_back(reason);
		fstream f4;
		f4.open("ResignList.txt", ios::out);
		if (!f4.is_open())
			cout << "Cannot open ResignList.txt\n";
		else {
			
			for (int i = 0;i < result.size();i += 2) {
				f4 << result[i] << endl << result[i + 1] << endl << endl;
			}

		}
		f4.close();
	}
	void Employee::reportManager() {
		string reason;
		string id;
		cout << "Please submit the id who wants to report \n ";
		cin >> id;
		cout << "Please describe the reasons for resignation \n ";
		cin >> reason;
		fstream f3;
		vector<string> result;
		f3.open("ReportList.txt", ios::in);
		if (!f3.is_open())
			cout << "Cannot open ReportList.txt\n";

		while (f3.good())
		{
			string s;
			getline(f3, s);
			result.push_back(s);
			if (f3.eof()) break;

		}
		result.push_back(id);
		result.push_back(reason);
		fstream f4;
		f4.open("ResignList.txt", ios::out);
		if (!f4.is_open())
			cout << "Cannot open ResignList.txt\n";
		else {

			for (int i = 0;i < result.size();i += 2) {
				f4 << result[i] << endl << result[i + 1] << endl << endl;
			}

		}
		f4.close();
	}
void Employee::IncreaseMerit() {
	_merits += 10;
}
void Employee::Promote() {
	string id;
	string	name;
	string date;
	string	address;

	string phone;
	string mail;


	int	merits;
	fstream f2;
	f2.open("Employee.txt", ios::in);


	if (!f2.is_open())
		cout << "Cannot open Employee.txt\n";

	int i = 0;

	while (f2.good())
	{
		f2 >> id;
		f2.ignore();
		getline(f2, name);

		getline(f2, date);


		getline(f2, address);

		getline(f2, phone);

		getline(f2, mail);




		f2 >> merits;


		if (f2.eof())
			break;
		Employee temp(id, name, date, address, phone, mail, merits);
		this->e.push_back(temp);
		f2.ignore(1, '\n');

	}
	f2.close();
	fstream f1;

	f1.open("EmployeeAccounts.txt", ios::in);

	if (!f1.is_open())
		cout << "Cannot open EmployeeAccounts.txt\n";

	string username;
	string password;
	int count = 0;
	while (f1.good())
	{
		f1 >> username;

		f1 >> password;



		if (f1.eof())
			break;
		Account temp(username, password);
		this->account.push_back(temp);

		count++;
	}
	f1.close();

	
	
	f2.open("Manager.txt", ios::in);

	vector<Employee> m;
	if (!f2.is_open())
		cout << "Cannot open Manager.txt\n";

	

	while (f2.good())
	{
		f2 >> id;
		f2.ignore();
		getline(f2, name);

		getline(f2, date);


		getline(f2, address);

		getline(f2, phone);

		getline(f2, mail);




		f2 >> merits;


		if (f2.eof())
			break;
		Employee temp(id, name, date, address, phone, mail, merits);
		m.push_back(temp);
		f2.ignore(1, '\n');

	}
	

	f1.open("ManagerAccounts.txt", ios::in);

	if (!f1.is_open())
		cout << "Cannot open ManagerAccounts.txt\n";
	vector<Account> acc;
	
	int count1 = 0;
	while (f1.good())
	{
		f1 >> username;

		f1 >> password;



		if (f1.eof())
			break;
		Account temp(username, password);
		acc.push_back(temp);

		count1++;
	}
	f1.close();

	for (int i = 0; i < e.size(); i++) {
		if (e[i].getmerit() == 100){
			acc.push_back(account[i]);
			Employee temp(e[i].getId(), e[i].getname(), e[i].getbirth(), e[i].getaddress(), e[i].getphone(), e[i].getmail(), e[i].getmerit());
			
			m.push_back(temp);
			e.erase(e.begin() + i);
			account.erase(account.begin() + i);
		}
	}

	fstream f4;
	f4.open("Employee.txt", ios::out);
	if (!f4.is_open())
		cout << "Employee.txt\n";

	for (int l = 0; l < e.size(); l++)
	{

		f4 << e[l].getId() << endl;
		f4 << e[l].getname() << endl;
		f4 << e[l].getbirth() << endl;
		f4 << e[l].getaddress() << endl;
		f4 << e[l].getphone() << endl;

		f4 << e[l].getmail() << endl;

		f4 << e[l].getmerit() << endl;
		f4 << endl;

	}
	f4.close();
	
	f4.open("Manager.txt", ios::out);
	if (!f4.is_open())
		cout << "Manager.txt\n";

	for (int l = 0; l < e.size(); l++)
	{

		f4 << e[l].getId() << endl;
		f4 << e[l].getname() << endl;
		f4 << e[l].getbirth() << endl;
		f4 << e[l].getaddress() << endl;
		f4 << e[l].getphone() << endl;

		f4 << e[l].getmail() << endl;

		f4 << e[l].getmerit() << endl;
		f4 << endl;

	}
	f4.close();

	fstream f3;
	f3.open("EmployeeAccounts.txt", ios::out);
	if (!f3.is_open())
		cout << "EmployeeAccounts.txt\n";

	for (int j = 0; j < this->account.size(); j++)
	{

		f3 << this->account[j].username() << endl;

		f3 << this->account[j].password() << endl;


		f3 << endl;

	}
	f3.close();

	;
	f3.open("ManagerAccounts.txt", ios::out);
	if (!f3.is_open())
		cout << "ManagerAccounts.txt\n";

	for (int j = 0; j <acc.size(); j++)
	{

		f3 << acc[j].username() << endl;

		f3 << acc[j].password() << endl;


		f3 << endl;

	}
	f3.close();
}
void Employee::viewInfoAllCustomer() {
	ifstream f1;
	vector<Customer> a;
	string id;
	string	name;
	string date;
	string	address;

	string phone;
	string mail;
	string Acctype;

	int	balance;

	int	duration;
	int	period;
	f1.open("Customer.txt", ios::in);


	if (!f1.is_open())
		cout << "Cannot open Customer.txt\n";

	int i = 0;
	int count = 0;
	while (f1.good())
	{
		f1 >> id;
		f1.ignore();
		getline(f1, name);

		getline(f1, date);


		getline(f1, address);

		getline(f1, phone);

		getline(f1, mail);

		getline(f1, Acctype);

		f1 >> balance;
		f1 >> duration;
		f1 >> period;

		if (f1.eof())
			break;
		Customer temp(id, name, date, address, phone, mail, Acctype, balance, duration, period);
		a.push_back(temp);
		f1.ignore(1, '\n');
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		cout << "Request #" << i + 1 << endl;
		cout << "id :" << a[i].getId() << endl;
		cout << "name :" << a[i].getname() << endl;
		cout << "birthday :" << a[i].getbirth() << endl;
		cout << "address :" << a[i].getaddress() << endl;
		cout << "phone :" << a[i].getphone() << endl;
		cout << "mail:" << a[i].getmail() << endl;
		cout << "Acc type :" << a[i].getacctype() << endl;
		cout << "balance :" << a[i].getBalance() << endl;
		cout << "duration :" << a[i].getDuration() << endl;
		cout << "period :" << a[i].getPeriod() << endl;
		cout << endl;
	}
	f1.close();
}

void Employee::tradeHistory(string type,string name,float money){
	fstream f4;
	f4.open("TransactDate.txt", ios::out);
	if (!f4.is_open())
		cout << "Cannot open TransactDate.txt\n";
	else {
		Date d;
		f4 << d.toString() << endl <<name << endl << type << endl << money << endl;

	}
	f4.close();
}