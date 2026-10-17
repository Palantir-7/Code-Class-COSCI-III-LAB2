//Elizabeth Fanton COSCI 1437 3/28/2026
//the general purpose of this code is to take a string of letters and convert them into ciphers.

//modifying for lab 2, COSCI  2436 COSCI-III 9/21/26

#pragma once
#include <iostream>
#include<string>
#include<stdio.h>
#include<vector>
#include<fstream>
#include<algorithm>


using namespace std;

class Code
{
private:
	string message = "";
	int shiftNum;
	string keyWord = "";
	//string keyLetter;

public:
	//setters
	void setmessage();
	void setshiftNum();
	void setkeyWord();
	//void setkeyLetter();

	//getters
	string getmessage();
	int getshiftNum();
	string getkeyWord();
	//string getkeyLetter();

	//functions
	void chosenCipher(int);
	void str2num();
	void ceasarCipher();
	void VinegretteCipher();//Vingere Cipher
	//string stringProcessor();
	void frequencyAnalysis(string);
};

//can i use a function from <algorithm> to find and count the number of times
// a letter accurs in a ciphet text?
// maybe use the includes function?

//need to store plaintext and cipher text in a vector?