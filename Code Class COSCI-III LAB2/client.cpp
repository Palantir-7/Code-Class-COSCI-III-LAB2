//Elizabeth Fanton COSCI 1437 3/28/2026
#include "Code.h"

int main()
{
	Code myNumber;

	int choosenNum;
	cout << "Please enter 1 to convert letters to numbers." << endl;
	cout << "Please enter 2 to encode using a Ceasar Cipher." << endl;
	cout << "Please enter 3 to encode using a Vingere Cipher." << endl;
	cout << "Enter your selection here: ";
	cin >> choosenNum;
	cout << endl;

	myNumber.chosenCipher(choosenNum);
	//myNumber.stringProcessor();
	return 0;
};