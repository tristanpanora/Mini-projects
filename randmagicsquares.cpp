#include <iostream>
#include <vector>
#include <random>
#include <cmath>
using namespace std;

/* 
Uses a random method to solve a 3x3 magic square
All rows, columns, and the two diagonals must add up to the magic const (15)
*/

bool isMagic(vector<int> &square, int maxNum) //modifying the acutal vector
{

	int n = sqrt(maxNum);
	int array[n][n];
	//READ VECTOR INTO 2D ARRAY
	int ele = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			while (ele < maxNum)
			{
				array[i][j] = square[ele];
				ele++;
				break;
			}
			
		}
	}
	//END READING


	//sums of diagonals
	int sum = 0, sum2 = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += array[i][i];
	}
	for (int i = 0; i < n; ++i)
	{
		sum2 += array[i][n-1-i];
	}
	if (sum != sum2)
	{
		return false;
	}
	//end sums of diagonals

	//SUMS OF ROWS
	for (int i = 0; i < n; ++i)
	{
		int rowSum = 0;

		for (int j = 0; j < n; ++j)
		{
			rowSum += array[i][j];
		}

		if (rowSum != sum)
		{
			return false;
		}
	}
	//END SUMS OF ROWS

	//SUMS OF COLS
	for (int i = 0; i < n; ++i)
	{
		int colSum = 0;
		for (int j = 0; j < n; ++j)
		{
			colSum += array[j][i];
		}

		if (sum != colSum)
		{
			return false;
		}
	}
	//END SUMS OF COLS

	//keep this true for now so it runs once for debugging, print out the vector of vectors here
	return true;
}

bool findMagic(int n)
{
	//first, lets get row 1 to equal 15

	int maxNum = n*n; //max number is n^2, so 9
	int sum = 0;
	
	int magic_const = n*((pow(n,2)+1)/2);

	random_device dev;
	mt19937 rng(dev());
	 //this will reduce the range as the vector of allowed guesses decreases
	
	//int randomNum = distmax(rng); //pick a random number

	//2D array
	vector<int> square(n*n);
	//square.reserve(n*n);
	
	

	//have a vector of numbers 1-9 (CHECK)
	//randomly select an element in that vector
	//make square[i] equal to that element
	//delete that element from the vector of allowed guesses
		//INITIALIZE VECTOR EVERY CYCLE
		vector<int> guessed;
		guessed.reserve(maxNum);
		for (int i = 1; i <= maxNum; ++i)
		{
			guessed.push_back(i); //vector with numbers 1 to 9.
		}

		shuffle(guessed.begin(), guessed.end(), rng); //put in random order

		//maybe sort before its even put into square?

		int pick = 0;
		int rowSum = 0;
		
		for (int i = 0; i < guessed.size(); ++i)
		{
			int count = 0;
			rowSum += guessed[i];

			if (i % n == n-2) //1,4,7... 2,6,10,14
			{
				pick = magic_const - rowSum;

				for (int k = i+1; k < guessed.size(); ++k)
				{
					if (guessed[k] == pick)
					{
						count++;
						guessed[k] = guessed[i+1];
						guessed[i+1] = pick;
						// cout << "ROW SUM: " << rowSum << endl;
						// cout << "PICK: " << pick << " " << count << endl;
						pick = 0;
						i++;
						rowSum = 0;
					}

					else if (count == 0)
					{
						return false;
					}
					
				} //1,2,3,4,5,6,7,8,9
			
			//std::count(guessed.begin()+i,guessed.end(), pick)


			}

		}

		//END INITIALIZATION

		//0,1,2      
		//3,4,5      
		//6,7,8		
		
		//METHOD: RANDOM
		rowSum = 0;
		int colSum = 0;
		int diagSum = 0;
		
		
	

		for (int i = 0; i < maxNum; ++i) //num of squares in the magic square
		{
			
			square[i] = guessed[i]; //set square[i] equal to that random number from the allowed guess vector
			rowSum += square[i];
		}


		//END improved RANDOM METHOD

			cout << "\n";
			for (int i = 0; i < maxNum; ++i)
			{
				cout << square[i] << " ";

				if (i % n == (n-1))
				{
					cout << "\n";
				}
				
			}
		
			if (isMagic(square, maxNum))
			{
				return true;
			}
		
	
	return false;
}

int main()
{
	//Main will take in a value (n) that represents the number of squares on each side of the magic square

	int n = 3;
	int count = 0;

	cout << "Enter the number of sides on the square: ";
	cin >> n;

	cout << "Total possible permutations of a " << n << "x" << n << " square is: " << pow(2,(n*n)) << ".";


	if (n == 2)
	{
		cout << "2x2 magic square is impossible with natural numbers.\n";
		return 0;
	}

	
	while (!(findMagic(n)))
	{
		// count++;
		// printf("\nCount: %d\n", count);
	}

	return 0;
}