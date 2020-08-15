#include "Director.h"

DirectorMenu::DirectorMenu(Account acc)
{
	fstream f;

	f.open("DirectorRequestsList.txt", ios::in);

	if (!f.is_open())
		cout << "Cannot open DirectorRequestsList.txt\n";

	string buffer1 = "";
	string buffer2 = "";
	bool buffer3 = false;

	while (!f.eof())
	{
		getline(f, buffer1, '\n');
		getline(f, buffer2, '\n');
		f.ignore(1, '\n');

		if (buffer2 == "0")
			buffer3 = false;
		else buffer3 = true;

		Request temp(buffer1, buffer3);
		this->_requestList.push_back(temp);
	}

	f.close();

	this->_account = acc;
}

void DirectorMenu::viewRequest()
{
	cout << "\n==========REQUESTS-LIST==========\n";
	for (int i = 0; i < this->_requestList.size(); i++)
	{
		cout << "Request #" << i + 1 << endl;
		cout << this->_requestList[i].viewRequest() << endl;
		if (this->_requestList[i].approvalStatus())
			cout << "Approved\n";
		else cout << "Denied\n";
		cout << endl;
	}
}
