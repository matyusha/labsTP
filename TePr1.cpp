﻿#include <iostream>
#include <string>
#include "Dll1.h"

const char EOLN = '\n';
const char YES_CHAR = 'Y';
const char NO_CHAR = 'N';
const int LEFT_BOUND = -1000000000;
const int RIGHT_BOUND = +1000000000;
const std::string ABOUT_MESSAGE = "Counting the number of different numbers in a given set  integers";
const std::string CONTINUE_MESSAGE =
"Continue? (Y/N)>";
const std::string INCORRECT_MESSAGE =
"Input is incorrect. Try again>";
const std::string INPUT_MESSAGE = "Input an integer>";
const std::string OUT_OF_BOUNDS_MESSAGE =
"This number is out of bounds";
const std::string OUTPUT_MESSAGE = "Result: ";
const std::string SKIP_CHARACTERS = " ";

void ClearInputStream(std::istream& in) {
	in.clear();
	while (in.peek() != EOLN && in.peek() != EOF)
	{
		in.get();
	}
}

int Seek(std::istream& in)
{
	while (in.peek() != EOLN &&
		SKIP_CHARACTERS.find((char)in.peek()) !=
		std::string::npos)
	{
		in.get();
	}
	return in.peek();
}

bool CheckBounds(int n)
{
	bool ok = (LEFT_BOUND <= n && n <= RIGHT_BOUND);
	if (!ok)
	{
		std::cout << OUT_OF_BOUNDS_MESSAGE << " ["
			<< LEFT_BOUND << ", " << RIGHT_BOUND << "]" <<
			std::endl;
	}
	return ok;
}

int ReadInt(std::istream& in)
{
	std::cout << INPUT_MESSAGE;
	int ans;
	in >> ans;
	while (!in || Seek(in) != EOLN ||
		!CheckBounds(ans))
	{
		ClearInputStream(in);
		std::cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans;
}

int ReadPositiveInt(std::istream& in)
{
	std::cout << INPUT_MESSAGE;
	int ans;
	in >> ans;
	while (!in || Seek(in) != EOLN ||
		!CheckBounds(ans) || ans < 1)
	{
		ClearInputStream(in);
		std::cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans;
}

bool NeedContinue(std::istream& in)
{
	std::cout << CONTINUE_MESSAGE;
	char ans;
	in >> ans;
	while (!in || Seek(in) != EOLN || ans != YES_CHAR
		&& ans != NO_CHAR)
	{
		ClearInputStream(in);
		std::cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans == YES_CHAR;
}

int main()
{
	std::cout << ABOUT_MESSAGE << std::endl;
	bool cont = true;
	while (cont)
	{
		std::cout << "Enter the number of elements in set\n";
		int n = ReadPositiveInt(std::cin);
		int* a = new int[n];
		std::cout << "Enter elements a set of numbers\n";
		for (int i = 0; i < n; i++) {
			a[i] = ReadInt(std::cin);
		}
		std::cout << OUTPUT_MESSAGE << CountOfDiffNumbres(a, n)	<< std::endl;
		delete[] a;
		cont = NeedContinue(std::cin);
	}
	return 0;
}

