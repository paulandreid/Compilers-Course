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
	int nrConstants = 0;
	list <string> keywords;
	list<string> constants;
	std::cout << "Enter Filename:";
	cin >> inputFilename;
	char ch;
	fstream fin(inputFilename, fstream::in);
	string token= "";
	while (fin >> noskipws >> ch) {
		//comment
		if (ch == '/') {
			fin >> noskipws >> ch;
			if (ch == '/')
				while (fin >> noskipws >> ch)
					if (ch == '\n')
						break;
		}
		//token
		if (ch == ' ' || ch=='(' || ch==')' || ch==';'|| ch == '\n' || ch == '\t'||ch=='<'||ch=='>' ||ch=='#' ||ch== '\"') {
			nrTokens++;
			

			//keyword
			if (token == "if" || token== "while" || token =="else" || token == "break"|| token == "for" || token == "int" || token == "double" || token == "bool" || token == "return" || token == "std::string" || token == "true" || token == "false" || token == "new" || token == "std::cin" || token == "std::cout" || token == "else" || token == "include") {
				nrKeywords++;
				keywords.push_back(token);
			}
			//constant
			if (ch == '\"') {
				nrConstants++;
				while (fin >> noskipws >> ch)
					if (ch == '\"') {
						constants.push_back(token);
						break;
					}
					else
						token.push_back(ch);

			}
			//identifier
			token.clear();
		}
		else
			token.push_back(ch);
		
	}
	int i = 0;
	std::cout << nrConstants;
	for (string keyword : constants) {
		std::cout << ++i << ". " << keyword << endl;
	}
	cin >> inputFilename;
	return 0;
}

