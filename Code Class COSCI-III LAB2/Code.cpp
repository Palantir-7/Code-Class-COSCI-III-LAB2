//Elizabeth Fanton COSCI 1437 3/28/2026
#include "Code.h"
//using namespace std;
void Code::setmessage()
{
	//char inputString[1000];
	cout << "Enter the message you want encoded (with no spaces): ";
	cin >> message;//how do i get this to accept a string with spaces in it?

	//cout << "Number of characters in string: " << message.length() << endl;

	//cin >> inputString;
	//char inputChar;
	//int i = 0;
	//do
	//{
	//	inputChar = getchar();
	//	if (inputChar != ' ')
	//	{
	//		inputString[i] = inputChar;
	//		i++;
	//	}
	//} while (inputChar != '.');//char(10) is "enter"

	//inputString[i] = '\0';//string terminator
	//message = string(inputString);

}

void Code::setshiftNum()
{
	cout << "Enter the key shift: ";
	cin >> shiftNum;

}

void Code::setkeyWord()
{
	cout << "Enter key word: ";
	cin >> keyWord;
}

//void Code::setkeyLetter()
//{
//	cout << "Enter key letter: ";
//	cin >> keyLetter;
//}

int Code::getshiftNum()
{
	return shiftNum;
}

string Code::getkeyWord()
{
	return keyWord;
}

//string Code::getkeyLetter()
//{
//	return keyLetter;
//}

void Code::chosenCipher(int chosenCipher)
{
	if (chosenCipher == 1)
	{
		//call str2num function
		setmessage();
		str2num();
	}
	else if (chosenCipher == 2)
	{
		//call Ceasar Cipher function
		setmessage();
		setshiftNum();
		ceasarCipher();
	}
	else if (chosenCipher == 3)
	{
		//call Vingere Cipher
		setmessage();
		setkeyWord();
		//setkeyLetter();
		VinegretteCipher();
	}
	else
	{
		cout << "ERROR! Please restart." << endl;
	}
}

string Code::getmessage()
{

	return message;
}

void Code::str2num()
{
	int alphabetArray[1000];
	string passedString = getmessage();

	for (int i = 0; i < passedString.length(); i++)
	{
		cout << passedString[i];//outputs string...
		//takes each char and converts to uppercase

		passedString[i] = static_cast<char>(toupper(passedString[i]));//converts to upper case.
		alphabetArray[i] = int(passedString[i]) - 65;

		//cout<< "-> " << passedString[i];
		//cout << "-> " << alphabetArray[i];
		//cout << passedString[i];
		//cout << char(((int(passedString[i]) - 65 + 2) % 26)+65);
		//cout << endl;
		//cout << "-> " << passedString[i];

		cout << alphabetArray[i];//something wrong with ouput...
	}

}

void Code::ceasarCipher()
{
	int myCipher;
	string passedString = getmessage();
	string cipherText = passedString;
	myCipher = getshiftNum();

	for (int i = 0; i < passedString.length(); i++)
	{
		cout << passedString[i];//outputs string...


		passedString[i] = static_cast<char>(toupper(passedString[i]));//converts to upper case.
		//cout << "-> " << passedString[i];
		//cout << "-> ";

		//cout << char(((int(passedString[i]) - 65 + myCipher) % 26) + 65) << endl;
		//int test1 = (int(passedString[i] - 65 + myCipher) % 26);
		//cout << char(test1 + 65);
		cipherText[i] = char(((int(passedString[i]) - 65 + myCipher) % 26) + 65);//does conversion from plaintext to ciphertext

	}
	cout << endl << cipherText;
	cout << endl;

	//choose if you want to continue on to frequency analysis
	int toAnalyizeOrNotToAnalyize = 0;
	cout << "If you would like to continue on to do a frequency analysis on the encrypted message, enter 1, otherwise press any key to stop: ";
	cin >> toAnalyizeOrNotToAnalyize;

	if (toAnalyizeOrNotToAnalyize == 1)//what's wrong here?
	{
		//call frequency analysis function
		frequencyAnalysis(cipherText);
	}
	else if (toAnalyizeOrNotToAnalyize != 1)
	{
		exit(-1);
	}

}

void Code::VinegretteCipher()
{
	string myKeyWord;

	//string mykeyLetter;
	string passedString = getmessage();
	string cipherText = passedString;
	myKeyWord = getkeyWord();
	//mykeyLetter = getkeyLetter();

	int j = 0;
	int shift = 0;
	for (int i = 0; i < passedString.length(); i++)
	{
		//cout << passedString[i];//outputs string...

		passedString[i] = static_cast<char>(toupper(passedString[i]));//converts to upper case.
		//cout << "-> " << passedString[i];
		//cout << "-> ";

		//cout <<"testing "<<(mykeyLetter + 32);
		shift = static_cast<char>(toupper(myKeyWord[j])) - 65;
		j = (j + 1) % myKeyWord.length();


		//myKeyWord = static_cast<char>(toupper(myKeyWord[i]));
		//cout << char(((int(passedString[i]) - 65 + shift) % 26) + 65);

		cipherText[i] = char(((int(passedString[i]) - 65 + shift) % 26) + 65);


	}

	cout << endl << cipherText;
	cout << endl;
	//choose if you want to continue on to frequency analysis
	int toAnalyizeOrNotToAnalyize = 0;
	cout << "If you would like to continue on to do a frequency analysis on the encrypted message, enter 1, otherwise press any key to stop: ";
	cin >> toAnalyizeOrNotToAnalyize;
	
	if (toAnalyizeOrNotToAnalyize == 1)//what's wrong here?
	{
		//call frequency analysis function
		frequencyAnalysis(cipherText);
	}
	else if (toAnalyizeOrNotToAnalyize != 1)
	{
		exit(-1);
	}
	
}

void Code::frequencyAnalysis(string passedCipher)
{
	//needs to be able to run a frequencey analysis on the letter strings at least...
	//pass  cipherText from vinegrette function to here
	//pass cipherText from ceasarCipher function to here

	//use count function to count how many times a letter apppers in the encrypted message
	//output the letter that appears most in frequency analysis
	

	const int alpha_Array_Size = 26;
	
	int alphaArray[alpha_Array_Size];
	for (int i = 0; i < 26; i++)
	{
		//this counts how many times a letter appears in a ciphertext.

		alphaArray[i] = count(passedCipher.begin(), passedCipher.end(), char(i + 65));//counts how many times a letter apprears in a string

		cout << "The letter " << char(i + 65) << " appears " << alphaArray[i] << " times in the encrypted message." << endl;

	}
	//reconvert alphaArray[] to characters...?

	/*for (int j = 0; j < 26; j++)
	{
		alphaArray[j] = static_cast<char>(j+65);
		cout << "testing..." << alphaArray[j]<<" ";
	}*/


	//sort alpha array biggest to smallest elements.
	int size = sizeof(alphaArray) / sizeof(alphaArray[0]);

	//nested loops
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			//change '<' to '>' for ascending order
			if (alphaArray[j] < alphaArray[j + 1])
			{
				//swap
				int temp = alphaArray[j];
				alphaArray[j] = alphaArray[j + 1];
				alphaArray[j + 1] = temp;
			}
		}
	}//works!
	//print
	//cout << "sorted array" << endl;
	//for (int i = 0; i < size; i++)
	//{
	//	cout << alphaArray[i] << " ";
	//}//output sorted array

	cout << "The actual string numbers..." << endl;
	int sizeCipher = passedCipher.size();
	/*const int original_Cipher_Size = passedCipher.length();*/
	//int originalCipherText[original_Cipher_Size];
	for (int i = 0; i < sizeCipher; i++)
	{
		//this counts how many times a letter appears in a ciphertext.

		 int counter = count(passedCipher.begin(), passedCipher.end(), char(i + 65));//counts how many times a letter apprears in a string
		//vector<char> decryptedStr;
		//int theCount;
		/*for (int k = 0; k < sizeCipher; k++)
		{
			if (passedCipher[k] == passedCipher[k + 1])
			{
				theCount++;
				decryptedStr.push_back(theCount);
			}
			if (alphaArray[k] != alphaArray[k + 1])
			{
				theCount = 1;
				decryptedStr.push_back(theCount);
			}*/
		cout << endl << "The letter " << passedCipher[i] << " appears " << counter << " times in the encrypted message." << endl;

	}

	/*int count = 0;
	for(int k = 0;k < passedCipher.length();k++)
	{
		if (alphaArray[k] == alphaArray[k + 1])
		{
			count++;
			decryptedStr.push_back(count);
		}
		if (alphaArray[k] != alphaArray[k + 1])
		{
			count = 1;
			decryptedStr.push_back(count);
		}
	}*/
	//loop thru alphaArray again and use ascii to get char values of numbers.

	//put new char values into the places
	char myLetter;

	for (int j = 0; j < 26; j++)
	{
		for (int ctext = 0; ctext < passedCipher.length(); ctext++)
		{
			passedCipher = count(passedCipher.begin(), passedCipher.end(), char(ctext + 65));//counts number of time as letter appears in passedCipher
			cout << "The letter " << char(ctext + 65) << " appears " << passedCipher[ctext] << " times in the encrypted message." << endl;
		}
		cout << "Enter your substitution for the letters: ";
		cin >> myLetter;//<-plaintext letter to replace ciphertext letter
		//take original passedCipher, go thru element and count how many times they appear,
		//without going thru the whole alphabet, JUST the string.
		//take largest element and replace each corresponding letter with user input replacement.

		cout << "The letter " << char(j + 65) << " is replaced with '" << myLetter << "' in the encrypted message." << endl;

		//decryptedStr.push_back(myLetter);
	}//figure out a way to simply output the letters in the ciphertext...



}


//string Code::stringProcessor()
//{
//	string strWithoutSpaces = "";
//	//int parseBegin = 0;
//	//int parseEnd = 0;
//	string strToBeProcessed = getmessage();
//
//	for (int k : strToBeProcessed)
//	{ 
//		if (k != ' ')
//		{
//			strWithoutSpaces += k;
//		}
//		else if (k != '\t')
//			strWithoutSpaces += k;
//		else if (k != '\f')
//			strWithoutSpaces += k;
//		else if(k != '\r')
//			strWithoutSpaces += k;
//		else if(k != '\n')
//			strWithoutSpaces += k;
//
//	}
//	cout << "String without whitespaces: " << strWithoutSpaces << endl;
//	return strWithoutSpaces;
//
//	//while (!strToBeProcessed.length())
//	//{
//	//	int parseBegin = 0;
//	//	int parseEnd = 0;
//
//	//	parseEnd = strToBeProcessed.find(' ', parseBegin);//finds first space?
//	//	strWithoutSpaces.push_back(parseEnd);
//	//	parseBegin = parseEnd;
//	//	parseEnd = strToBeProcessed.find(' ', parseBegin + 1);//finds next space?
//	//}
//
//
//	//for (int k = 0; k < strToBeProcessed.length(); k++)
//	//{
//	//	// look for spaces...
//	//	parseBegin = strToBeProcessed.find(' ', parseBegin);
//	//	parseEnd = strToBeProcessed.find(' ', parseBegin+1)
//	//	string newStrWithoutSpaces = 
//	//}
//}
//next step:
//fix code so i can have spaces in strings.
//loop thru string look for spaces find and put in new string withput spaces
//paststr packedstr, for loop, check char, if not a space assign it new space in string otherwise skip it.
//main for loop just like other for loops anoher j you increment separately.
