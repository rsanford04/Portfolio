// Temperature.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Ryan Sanford

#include <iostream>
#include <fstream>		//File IO class
#include <string>		//String class
#include <regex>		//Regex class used to isolate numeric/non numeric characters in a string
using namespace std;

int main()
{
	string text;	//Variable to hold current line of file being read

	ifstream fahrenheitFile("FahrenheitTemperature.txt");	//Variable points to file being read
	ofstream celsiusFile("CelsiusTemperature.txt");		//Variable points to file being written to

	while (getline (fahrenheitFile, text))		//Loops through file being read line by line and writes current line to text
	{
		string temp = regex_replace(text, regex(R"([^0-9])"), "");		//Removes non-numeric characters from current line
		int celsius = (stoi(temp) - 32) * 5 / 9;						//Converts string temp to int while also converting into celsius
		celsiusFile << regex_replace(text, regex(R"([0-9])"), "");		//Writes only the non-numeric characters to the file
		celsiusFile << celsius << endl;									//Writes newly converted celsius temperature to file
	}

	celsiusFile.close();	//Closes file being written to
	fahrenheitFile.close();		//Closes file being read to
	

	return 0;
}

