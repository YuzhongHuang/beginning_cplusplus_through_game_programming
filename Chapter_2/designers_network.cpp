// Designers Network
// Demonstrates logical operators

#include <iostream>

using namespace std;

int main()
{
	string username;
	string password;
	bool success;

	cout << "\tGame Designer's Network\n";

	do
	{
		cout << "\nUsername: ";
		cin >> username;

		cout << "Password: ";
		cin >> password;

		if (username == "anderballer" && password == "1a2b3c4d")
		{
			cout << "\nHey, Ander." << endl;
			success = true;
		}

		else if (username == "S.Meier" && password == "civilization")
		{
			cout << "\nHey, Sid." << endl;
			success = true;
		}

		else if (username == "S.Miyamoto" && password == "mariobros")
		{
			cout << "\nWhat’s up, Shigeru?" << endl;
			success = true;
		}

		else if (username == "W.Wright" && password == "thesims")
		{
			cout << "\nHow goes it, Will?" << endl;
			success = true;
		}

		else
		{
			cout << "\nYour login failed.";
			success = false;
		}
	} while (!success);

	return 0;
}