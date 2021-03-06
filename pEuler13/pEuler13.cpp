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

string reverseString(string str)
{
	string revStr;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		revStr.push_back(str[i]);
	}
	return revStr;
}

//Performs additions on two strings. A.size() must be >= B.size()
string addTwoStrings(string strA, string strB)
{
	string sumS;
	int carry = 0, sumI = 0;
	int sizeDif = strA.size() - strB.size();
	//This if statement checks if the two strings are equal length, and if they aren't then it will add zeros to the left side of the shorter string (strB)
	if (sizeDif != 0)
	{
		strB = reverseString(strB);
		while (sizeDif > 0)
		{
			strB.push_back(48);
			sizeDif--;
		}
		strB = reverseString(strB);
	}

	for (int i = strA.length()-1; i >= 0; i--)
	{
		int digitA, digitB;

		digitA = (int)strA[i]-48;
		digitB = (int)strB[i]-48;
		
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
		sumS.push_back((carry % 10)+48);
		if (carry / 10 > 0)
		{
			sumS.push_back((carry / 10)+48);
		}
	}
	//need to reverse string before returning it
	sumS = reverseString(sumS);
	cout << strA << endl;
	cout << strB << endl;
	cout << sumS << endl << endl;
	cout << "============================================================" << endl;
	return sumS;
}

int main()
{
	fstream numFile;
	numFile.open("numbers.txt", ios::in);
	vector<string> nums = getNumbers(numFile);
	string sum = nums[0];
	//string testsum = addTwoEqualStrings(nums[0], nums[1]);
	for (int i = 1; i < nums.size(); i++)
	{
		sum = addTwoStrings(sum, nums[i]);
	}

	cout << "The sum of the 100 hundred 50-digit numbers provided is: " << sum;
}
