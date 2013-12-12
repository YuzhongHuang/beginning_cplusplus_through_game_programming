// Guess my number
// The classic number guessing game

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	cout << "\tWelcome to Guess My Number\n\n";
	int secretNumber;
	int tries = 0;
	int guess;

	cout << "Numero a acertar: ";
	cin >> guess;

	srand(static_cast<unsigned int>(time(0))); //seed random number generator

	do
	{
		secretNumber = rand() % 100 + 1; //random number between 1 and 100
		cout << secretNumber << "\n";
		tries++;

	} while (guess != secretNumber);
	
	cout << "He acertado tu número " << secretNumber << " a la " << tries << " vez.\n\n";

	return 0;
}