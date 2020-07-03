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
string addTwoEqualStrings(string strA, string strB)
{
	string sumS;
	int carry = 0, sumI = 0;
	for (int i = strA.length()-1; i >= 0; i--)
	{
		int digitA, digitB;
		int sizeDif = strA.size() - strB.size();
		if (sizeDif == 0)	//Subscript error if I don't check for different lengths of strings
		{
			digitA = (int)strA[i]-48;
			digitB = (int)strB[i]-48;
		}
		else
		{
			//this block is meant to account for B being shorter than A.
			digitA = (int)strA[i] - 48;
			if (i - sizeDif > 0)
			{
				digitB = (int)strB[i - sizeDif] - 48;
			}
			else
			{
				digitB = 0;
			}
		}
		
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
		sum = addTwoEqualStrings(sum, nums[i]);
	}

	cout << "The sum of the 100 hundred 50-digit numbers provided is: " << sum;
}
