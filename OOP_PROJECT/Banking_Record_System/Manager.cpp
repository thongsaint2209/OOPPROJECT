#include"Manager.h"

void ManagerMenu::showMenu()
{
	while (true)
	{
		system("cls");
		cout << "\n==========MANAGER-MENU==========\n";
		cout << "1. View requests list.\n";

		cout << "2. Edit requests list.\n";

		cout << "3. View list of accepting requests from director\n";

		cout << "4. View trade history ( not VIP).\n";
		
		cout << "5. Fire employee.\n";
		
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
			break;
		case 4:
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