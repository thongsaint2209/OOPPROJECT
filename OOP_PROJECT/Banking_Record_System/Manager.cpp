#include"Manager.h"

#include"Customer.h"
ManagerMenu::ManagerMenu(Account acc)
{
	fstream f;

	f.open("ManagerRequestList.txt", ios::in);

	if (!f.is_open())
		cout << "Cannot open ManagerRequestsList.txt\n";

	string buffer1 = "";
	string buffer2 = "";

	while (!f.eof())
	{
		getline(f, buffer1, '\n');
		getline(f, buffer2, '\n');
		f.ignore(1, '\n');

		int status = stoi(buffer2);

		Request temp(buffer1, status);
		this->_requestList.push_back(temp);
	}

	f.close();

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
		cout << "4. View list of accepting requests from director.\n";
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
	for (int i = 0; i < this->_requestList.size(); i++)
	{
		cout << "Request #" << i + 1 << endl;
		cout << this->_requestList[i].viewRequest() << endl;
		if (this->_requestList[i].approvalStatus() == -1)
			cout << "Denied\n";
		if (this->_requestList[i].approvalStatus() == 0)
			cout << "Pending\n";
		if (this->_requestList[i].approvalStatus() == 1)
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

			if (index > -1 && index < this->_requestList.size())
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
				this->_requestList[index].denyRequest();
				break;
			}

			if (temp == 1)
			{
				this->_requestList[index].approveRequest();
				break;
			}

			cout << "Wrong mode.\n";
		}
	}

	fstream f;

	f.open("ManagerRequestsList.txt", ios::out);

	if (!f.is_open())
		cout << "Cannot open DirectorRequestsList.txt\n";

	for (int i = 0; i < this->_requestList.size(); i++)
	{
		f << this->_requestList[i].viewRequest() << endl;
		f << this->_requestList[i].approvalStatus() << endl;
		if (i != this->_requestList.size() - 1)
			f << endl;
	}

	f.close();

	cout << "Saved successfully\n";
}



void ManagerMenu::viewlistReDirector()
{
	ifstream f1;

	f1.open("DirectorRequestsList.txt", ios::in);

	string id;
	string	name;
	string	address;
	int	withdraw;
	int	balance;

	if (!f1.is_open())
		cout << "Cannot open DirectorRequestsList.txt\n";

	string buffer1 = "";
	string buffer2 = "";

	while (!f1.eof())
	{
		getline(f1, buffer1, '\n');
		getline(f1, buffer2, '\n');
		f1.ignore(1, '\n');

		int status = stoi(buffer2);

		Request temp(buffer1, status);

		this->_requestList.push_back(temp);
	}

	f1.close();

	ifstream f2;
	f2.open("Viewlistacceptedfromdirector.txt", ios::in);

	int i = 0;

	if (!f2.is_open())
	{
		cout << "Can not open file" << endl;
	}
	else
	{
		while (!f2.eof())
		{
			
			getline(f2, id, '\n');

			getline(f2, name, '\n');

			getline(f2, address);


			f2 >> withdraw;
			
			f2 >> balance;

			f2 >> status;
			f2.ignore(1, '\n');
			f2.ignore(1, '\n');


		
			

			if (this->_requestList[i].approvalStatus() == 1&& this->_requestList[i].approvalStatus()==status)
			{
				cout << "Request #" << i + 1 << endl;
				cout << "id :" << id << endl;
				cout << "name :" << name << endl;
				cout << "address :" << address << endl;
				cout << "withdraw :" << withdraw << endl;
				cout << "balance :" << balance << endl;

				cout << endl;
			}
			i++;
		}

		f2.close();

	}

}

void ManagerMenu::viewcustomer()
{
	

	string id;
	string	name;
	string	address;
	int	withdraw;
	int	balance;

	
	ifstream f2;
	f2.open("Viewlistacceptedfromdirector.txt", ios::in);

	int i = 0;

	if (!f2.is_open())
	{
		cout << "Can not open file" << endl;
	}
	else
	{
		while (!f2.eof())
		{
			
			getline(f2, id, '\n');
		
			getline(f2, name, '\n');
			
			getline(f2, address);
			
			
			f2 >> withdraw;
			;
			f2 >> balance;
		
			f2 >> status;
			f2.ignore(1, '\n');
			f2.ignore(1, '\n');

			    cout << "Request #" << i + 1 << endl;
				cout << "id :" << id<<endl;
				cout << "name :" << name << endl;;
				cout << "address :" << address << endl;;
				cout << "withdraw :" << withdraw << endl;;
				cout << "balance :" << balance;

				cout << endl;
				i++;
		}

		
		
	}
	f2.close();
}