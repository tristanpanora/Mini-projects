#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> foo(double decimal)
{
	vector<int> vex;

	decimal = decimal * 2; // 1.625

	while (decimal != 0)
	{
		
		if (decimal >= 1) // 1.625
		{
		
			decimal = decimal - 1; // .625

			for (int i = 0; i < 1 ; ++i)
			{
				vex.push_back(1); // 1
			}

			decimal = decimal * 2;
		}

		if (decimal < 1) // .625
		{
			for (int i = 0; i < 1 ; ++i)
			{
				vex.push_back(0); // 0
			}

			decimal = decimal * 2;
		}
		
	}
	return vex;

}

vector<int> nums(int number)
{
	vector<int> leftside;

	while(number > 0)
	{

		if (number % 2 == 0) //even, first digit
		{
			for (int i = 0; i < 1; ++i)
			{
				leftside.push_back(0);
			}
			
		}

		if (number % 2 != 0) //odd, first digit
		{
			for (int i = 0; i < 1; ++i)
			{
				leftside.push_back(1);
			}
		}

		number = (number / 2);

	}

	return leftside;
}


int main()
{
	string fullnum;
	string point;
	double decimal;
	int number;
	
	cout << "Enter number to the left of decimal, then space, and then the decimal part. " << endl;
	cout << "Example: 10 .8125 == 10.8125: ";
	cin >> number >> decimal;
		
	if (number > 0)
	{
		for (int i = nums(number).size() -1; i >= 0; --i)
		{
			cout << nums(number)[i];
		}
	}

	if (decimal > 0)
	{
		cout << ".";
	
		for (int i = 0; i < foo(decimal).size() - 1; ++i)
		{
			cout << foo(decimal)[i] ;
		}

	}

	cout << endl;

	return 0;

}