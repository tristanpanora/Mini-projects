#include <iostream>
#include <vector>
using namespace std;

//my unique solution to matrix rotation

int main()
{
	int size = 3;
	int num_rotations = 1;

	cout << "ENTER SIDE SIZE and NUM OF ROTATIONS: ";
	cin >> size >> num_rotations;
	
	int matrix[size][size];
	int fill_matrix = 1;

	//initialize matrix with numbers 1 to size*size
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] = fill_matrix;
			fill_matrix++;

		}
	}
	//end initialization

	//print out the matrix before rotation
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	//end initial print




	cout << "\nAFTER ROTATION: \n";

	int copyRow[size];
	int copyMat[size][size];
	
	int count_rotations = 0;

	while(count_rotations < num_rotations)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{	
				copyRow[j] = matrix[i][j]; //saves first row

				for (int col = size-1-i; col >= 0; col--) //fills columns, not by rows
				{
					for (int row = 0; row < size; ++row)
					{
						copyMat[row][col] = copyRow[row];
					}
					break; //fill one column then stop
				}
			}
			
		}

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				matrix[i][j] = copyMat[i][j]; //only need this if more than 1 rotation
			}
		}

		count_rotations++;

	}



	//print out the rotated matrix
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	//end print

	return 0;
}


//goal:
/* 
0   1 2 3      7 4 1  0
1   4 5 6  to  8 5 2  1
2   7 8 9	   9 6 3  2

//  0 1 2	   0 1 2
*/

//turn row 1 to column 3
//turn row 2 to column 2
//turn row 3 to column 1