// Chapter 1 - Exercise 3
//Program that gets 3 game scores from the user and displays the average

#include <iostream>
using namespace std;

int main()
{
	cout << "Introduce la puntuación obtenida\n\n";

	int scoreOne, scoreTwo, scoreThree;

	cout << "Puntuación 1: ";
	cin >> scoreOne;

	cout << "Puntuación 2: ";
	cin >> scoreTwo;

	cout << "Puntuación 3: ";
	cin >> scoreThree;

	int averageScore = (scoreOne + scoreTwo + scoreThree) / 3;

	cout << "La puntuación media es " << averageScore << "." << endl;

	return 0;
}