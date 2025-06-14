#include <iostream.h>
#include <conio.h>

int main ()
{
	clrscr();
	float num1, num2, result;
	char op;

	cout << "Enter first number: ";
	cin >> num1;

	cout << "Select the operator (+, -, *, /): ";
	cin >> op;


	cout << "Enter second number: ";
	cin >> num2;

	switch (op)
	{
		case '+':
			result = num1 + num2;
			cout << "Result = "<<  result;
			break;
		case '-':
			result = num1 - num2;
			cout << "Result = "<< result;
			break;
		case '*':
			result = num1 * num2;
			cout << "Result = "<< result;
			break;
		case '/':
			if(num2 != 0)
				result = num1 / num2;
			else
			{
				cout << "Error: Division by zero!";
				return 1;
			}

			cout << "Result = "<< result;
			break;
		default:
			cout << "Invalid operator!";
	}
	getch();d
	return 0;
}