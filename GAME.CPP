#include <iostream.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	randomize();
	int secretNumber = random(100) + 1;
	int userGuess;
	int attempts = 0;

	cout << "Guess the number (between 1 and 100): " << endl;

	do
	{
		cin >> userGuess;
		attempts ++;

		if(userGuess > secretNumber)
		{
			cout << "Too high! Try again: " << endl;
		}
		else if(userGuess < secretNumber)
		{
			cout << "Too low! Try again: "<< endl;
		}
		else
		{
			cout << "Correct! You guessed it in " << attempts << "attempts." << endl;
		}
	}
	while (userGuess != secretNumber);
	return 0;
}