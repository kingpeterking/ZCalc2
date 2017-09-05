// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LongNumber.h"
#include "LongNumberDivision.h"
#include "iostream"
using namespace std;


int main(int argc, char * argv[])
{

	// check got three arguments (four includes programme name)
	if (argc != 4)
	{
		cout << "Error insufficient arguments";
		return 0;
	}

	// Store command line values
	char * Op = argv[2];
	char * NoA = argv[1];
	char * NoB = argv[3];

	cout << "Performing Operation " << Op << " on Arguments " << NoA << " and " << NoB << "\n";

	// Create arguments as Long Numbers
	LongNumber ArgA(NoA);
	LongNumber ArgB(NoB);


	if (Op[0] == '+')
	{
		LongNumber Result = ArgA + ArgB; 
		PrintLongNumberLR(Result);
	}
	else if (Op[0] == '*')
	{
		LongNumber Result = ArgA * ArgB;
		// TrimLongNumber(Result);
		PrintLongNumberLR(Result);
	}
	else if (Op[0] == '-')
	{
		LongNumber Result = ArgA - ArgB;
		PrintLongNumberLR(Result);
	}

	else if (Op[0] == '/')
	{
		LongNumberDivision Divide = LongNumberDivide(ArgA, ArgB);
		PrintLongNumberDivision(Divide);
		cout << endl;
	}
	else if (Op[0] == 'M')
	{
		ArgA = RetunPart(ArgA, 2, 3);
		PrintLongNumberLR(ArgA); 
		ArgB = RetunPart(ArgB, 3, 2);
		PrintLongNumberLR(ArgB);
		cout << endl;
	}
	else if (Op[0] == 'C')
	{
		bool Compare = ArgA <= ArgB;
		cout << Compare << endl;
	}
	else if (Op[0] == 'X')
	{
		LongNumber Result = Concatenate(ArgA, ArgB);
		PrintLongNumberLR(Result);
	}
	else if (Op[0] == 'T')
	{
		LongNumber Result = TrimLongNumber(ArgA);
		PrintLongNumberLR(Result);
	}
	else if (Op[0] == 'B')
	{
		LongNumber Result = ConvertDectoBin(ArgA);
		PrintLongNumberLR(Result);
	}
	else if (Op[0] == 'U')
	{
		LongNumber Result = TwosComplement(ArgA, ArgA.GetLongNumberLength() + 6);
		PrintLongNumberLR(Result);
	}
	else if (Op[0] == 'V')
	{
		LongNumber Result = ConvertBases(ArgA, 2);
		PrintLongNumberLR(Result);
	}
	else if (Op[0] == 'Y')
	{
		ArgA.SetLongNumberBase(8); 
		ArgB.SetLongNumberBase(8);
		LongNumber Result = LongNumberMultiplyBase(ArgA, ArgB);
		PrintLongNumberLR(Result);
	}
	else if (Op[0] == 'Z')
	{
		ArgA.SetLongNumberBase(10);
		ArgB.SetLongNumberBase(10);
		LongNumber Result = LongNumberSubtractTwosC(ArgA, ArgB);
		PrintLongNumberLR(Result);
	}
	else if (Op[0] == 'D')
	{
		ArgA.SetLongNumberBase(8);
		ArgB.SetLongNumberBase(8);
		LongNumber Result = LongNumberSubtractBase(ArgA, ArgB);
		PrintLongNumberLR(Result);
	}
	else if (Op[0] == 'E')
	{
		ArgA.SetLongNumberBase(8);
		ArgB.SetLongNumberBase(8);
		LongNumberDivision Result = LongNumberDivideBase(ArgA, ArgB);
		PrintLongNumberDivision(Result);
	}
    return 0;
}

