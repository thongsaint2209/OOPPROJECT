#include"Manager.h"

#include"Customer.h"
ManagerMenu::ManagerMenu(Account acc)
{
	fstream f1;

	f1.open("ManagerRequestList.txt", ios::in);

	if (!f1.is_open())
		cout << "Cannot open ManagerRequestsList.txt\n";
	string id ;
	string type ;
	int money;
	int status;
	while (f1.good())
	{
		f1 >> id;

		f1 >> type;

		f1 >> money;

		f1 >> status;

		if (f1.eof())
			break;
		Request temp(id, type, money, status);
		this->_requestList1.push_back(temp);

		
	}

	f1.close();

	this->_account = acc;
	this->_option = -1;
}

void ManagerMenu::showMenu()
{
	
	while (true)
	{
		system("cls");
		cout << "\n==========MANAGER-MENU==========\n";
		cout << "1. View requests list.\n";

		cout << "2. Edit requests list.\n";

		cout << "3. View list of accepting requests from director\n";
		cout << "4. View list of customer.\n";
		cout << "5. View trade history ( not VIP).\n";
		
		cout << "6. Fire employee.\n";
		
		cout << "0. Exit.\n";
		cout << "=================================\n";
		cout << "-> Select option: ";
		cin >> this->_option;

		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please only enter number!" << endl;
				cout << "Enter again: ";
				cin >> this->_option;
			}
			if (!cin.fail())
				break;
		}
		
		if (this->_option == 0)
			break;

		switch (this->_option)
		{
		case 1:
			this->viewRequest();
			break;
		case 2:
			this->editRequest();
			break;
		case 3:
			this->viewlistReDirector();
			break;
		case 4:
			this->viewcustomer();
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
		{
			cout << "Please only enter number from 0 to 7!\n";
			break;
		}
		}
		system("pause");
	}
}

void ManagerMenu::viewRequest()
{
	cout << "\n==========REQUESTS-LIST==========\n";
	for (int i = 0; i < this->_requestList1.size(); i++)
	{
		cout << "Request #" << i + 1 << endl;
		cout << this->_requestList1[i].getId() << endl;
		cout << this->_requestList1[i].getType() << endl;
		cout << this->_requestList1[i].getMoney() << endl;
		if (this->_requestList1[i].approvalStatus() == -1)
			cout << "Denied\n";
		if (this->_requestList1[i].approvalStatus() == 0)
			cout << "Pending\n";
		if (this->_requestList1[i].approvalStatus() == 1)
			cout << "Approved\n";
		cout << endl;
	}
	cout << "=================================\n";
}

void ManagerMenu::editRequest()
{
	while (true)
	{
		system("cls");
		this->viewRequest();

		int index = 0;
		cout << endl;

		while (true)
		{
			cout << "-> Select request to edit (Enter -1 to exit and save change): ";
			cin >> index;

			if (index == -1)
				break;

			index--;

			if (index > -1 && index < this->_requestList1.size())
				break;

			cout << "Cannot find request #" << index + 1 << endl;
		}

		if (index == -1)
			break;

		while (true)
		{
			int temp = -1;
			cout << "-> 0: Denied.\n";
			cout << "-> 1: Approve.\n";
			cout << "-> Which action do you want?: ";
			cin >> temp;

			if (temp == 0)
			{
				this->_requestList1[index].denyRequest();
				break;
			}

			if (temp == 1)
			{
				this->_requestList1[index].approveRequest();
				break;
			}

			cout << "Wrong mode.\n";
		}
	}

	fstream f;

	f.open("ManagerRequestList.txt", ios::out);

	if (!f.is_open())
		cout << "Cannot open DirectorRequestsList.txt\n";

	for (int i = 0; i < this->_requestList1.size(); i++)
	{
		
		f << this->_requestList1[i].getId() << endl;
		f << this->_requestList1[i].getType() << endl;
		f << this->_requestList1[i].getMoney() << endl;
		f << this->_requestList1[i].approvalStatus() << endl;
		if (i != this->_requestList1.size() - 1)
			f << endl;
	}

	f.close();

	cout << "Saved successfully\n";
}



void ManagerMenu::viewlistReDirector()
{
	ifstream f1;

	string id;
	string type;
	int money;
	int status;
	f1.open("DirectorRequestsList.txt", ios::in);

	
	if (!f1.is_open())
		cout << "Cannot open DirectorRequestsList.txt\n";

	int i = 0;
	while (f1.good())
	{
		f1 >> id;

		f1 >> type;

		f1 >> money;

		f1 >> status;

		if (f1.eof())
			break;
		Request temp(id, type, money, status);

		this->_requestList2.push_back(temp);

		if (this->_requestList2[i].approvalStatus() == 1 && this->_requestList2[i].approvalStatus() == status)
		{
			cout << "Request #" << i + 1 << endl;
			cout << this->_requestList2[i].getId() << endl;
			cout << this->_requestList2[i].getType() << endl;
			cout << this->_requestList2[i].getMoney() << endl;
			cout << endl;
		}
		i++;
	}

	f1.close();


}

void ManagerMenu::viewcustomer()
{
	
	ifstream f1;

	string id;
	string	name;
	string	address;
	int	balance;
	f1.open("Customer.txt", ios::in);


	if (!f1.is_open())
		cout << "Cannot open Customer.txt\n";

	int i = 0;
	int count = 0;
	while (f1.good())
	{
		f1 >> id;
		getline(f1, name);
		getline(f1, name);
		getline(f1, address);
		f1 >> balance;

		if (f1.eof())
			break;
		Customer temp(id, name, address, balance);
		this->a.push_back(temp);
		f1.ignore(1, '\n');
		count++;
	}

	for (int i = 0; i < count; i++)
	{
		cout << "Request #" << i + 1 << endl;
		cout << "id :" << a[i]._id << endl;
		cout << "name :" << a[i]._name << endl;
		cout << "address :" << a[i]._address << endl;
		cout << "balance :" << a[i]._balance << endl;
		cout << endl;
	}
	f1.close();
}