#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//Entry any binary number and it will be converted into base 10.
//Tristan Panora 2020

int main()
{
	string binary = "";
	int decimal = 0;
	cout << "Enter binary number: ";
	cin >> binary;

	reverse(binary.begin(), binary.end());

	for (int i = 0; i < binary.length(); i++) //start at the end (right side)
	{
		if (binary[i] == '1')
		{
			decimal += pow(2,i);
			//cout << decimal;
		}
	}

	cout << "Decimal is: " << decimal << endl;

	return 0;
}