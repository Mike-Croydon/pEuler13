// This program solves Project Euler problem 13: Large Sum
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//function to read the file stream and extract the numbers as a vector of strings
vector<string> getNumbers(fstream & stream)
{
	string temp;
	vector<string> numbers;
	while (stream >> temp)
	{
		numbers.push_back(temp);
	}
	return numbers;
}

//Performs additions on two strings which must be equal length
string addTwoEqualStrings(string strA, string strB)
{
	string sumS;
	int carry = 0, sumI = 0;
	for (int i = strA.length()-1; i >= 0; i--)
	{
		int digitA = (int)strA[i]-48;
		int digitB = (int)strB[i]-48;
		sumI = digitA + digitB + carry;
		if (sumI > 9)
		{
			carry = sumI / 10;
			sumI = sumI % 10;
		}
		else { carry = 0; }	//I don't think this is strictly necessary, could just get rid of if statement, but it makes things more clear;
		sumS.push_back(sumI+48);
	}
	if (carry != 0)
	{
		sumS.push_back(carry % 10);
		sumS.push_back(carry / 10);
	}
	return sumS;
}

int main()
{
	fstream numFile;
	numFile.open("numbers.txt", ios::in);
	vector<string> nums = getNumbers(numFile);
	string sum = addTwoEqualStrings(nums[0], nums[1]);
}
