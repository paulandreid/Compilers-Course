// lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;
int main()
{
	string inputFilename;
	int nrTokens = 0;
	int nrKeywords = 0;
	list <string> keywords;
	cout << "Enter Filename:";
	cin >> inputFilename;
	char ch;
	fstream fin(inputFilename, fstream::in);
	string token= "";
	while (fin >> noskipws >> ch) {
		if (ch == '/') {

		}
		if (ch == ' ' || ch=='(' || ch==')' || ch==';'|| ch == '\n' || ch == '\t') {
			nrTokens++;
			if (token == "if" || token== "while" || token =="else" || token == "break"|| token == "for" || token == "int" || token == "double" || token == "bool" || token == "return" || token == "std::string" || token == "true" || token == "false" || token == "new" || token == "std::cin" || token == "std::cout" || token == "else") {
				nrKeywords++;
				keywords.push_back(token);
			}
			token.clear();
		}
		else
			token.push_back(ch);
		
	}
	int i = 0;
	for (string keyword : keywords) {
		cout << ++i << ". " << keyword << endl;
	}
	cin >> inputFilename;
	return 0;
}

