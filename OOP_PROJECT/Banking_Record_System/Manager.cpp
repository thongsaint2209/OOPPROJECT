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
		cout << "7. Search information customer\n";
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
			this->searchcustomer();
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
	
	string	name;
	string	address;
	int	balance;
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
	
	
	cout << "Choose id you want to Edit  ";
	while (getchar() != '\n');
	getline(cin, id);

	int flag = 0;
	
			int option;
			cout << "Do you want to edit this customer?  " << endl;
			cout << "0: Out" << endl;
			cout << "1: Edit" << endl;
			cin >> option;
			switch (option)
			{
			case 0:
			{
				return;
			}
			case 1:
			{
				int j = 0;

				//tao vector temp 

				while (f1.good())
				{

					if (this->_requestList2[j].getId() == id)
					{
						if (this->_requestList2[j].getType() == "Deposit")
						{
							this->_requestList2[j].getMoney();//goi ham thuc thi



							this->_requestList2.erase(_requestList2.begin() + j);

						}
						else
						{
							this->_requestList2[j].getMoney();

							this->_requestList2.erase(_requestList2.begin() + j);
						}
					}
				}

				ifstream f2;
				f2.open("Customer.txt", ios::in);


				if (!f2.is_open())
					cout << "Cannot open Customer.txt\n";


				int count = 0;
				while (f2.good())
				{
					f2 >> id;
					getline(f2, name);
					getline(f2, name);
					getline(f2, address);
					f2 >> balance;

					if (f1.eof())
						break;
					Customer temp(id, name, address, balance);
					this->a.push_back(temp);
					f1.ignore(1, '\n');
					count++;
				}
				f2.close();

				fstream f3;
				f3.open("Customer.txt", ios::out);
				if (!f3.is_open())
					cout << "Cannot open Customer.txt\n";

				for (int i = 0; i < count; i++)
				{

					f3 << a[i].getId();

					f3 << a[i].getname();

					f3 << a[i].getaddress();
					f3 << a[i].getBalance() << endl;

				}
				f3.close();
			}
			default:
			{
				cout << "Please choose number from 0-2" << endl;
				break;
			}
			}
			
	
	

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
		cout << "id :" << a[i].getId() << endl;
		cout << "name :" << a[i].getname() << endl;
		cout << "address :" << a[i].getname() << endl;
		cout << "balance :" << a[i].getBalance() << endl;
		cout << endl;
	}
	f1.close();
}

void ManagerMenu::searchcustomer()
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
			cout << "address :" << a[i].getaddress() << endl;
			cout << "balance :" << a[i].getBalance() << endl;
			cout << endl;
		}
	}
	f1.close();
}