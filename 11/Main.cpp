#include <fstream>
#include <vector>
#include <iostream>

using std::ifstream;
using std::vector;
using std::cout;

struct SequenceInfo
{
	int first;
	int multipliedNextThree; 
};


int main(int argc, char* argv[])
{
	const int size = 20; 

	ifstream file(argv[1]); 

	vector<vector <int> > grid(size, vector<int>(size, 0));

	for (int y = 0; y < size; ++y)
		for (int x = 0; x < size; ++x)
		{
			int num = 0;
			file >> num;

			grid[x][y] = num;
		}

	// Horizontal + Vertical

	//SequenceInfo lastSeqH;
	//SequenceInfo lastSeqV;
	int maxMultiplication = 0; 

	for (int i = 0; i < size; ++i)
	{
		//lastSeqH = { 1, grid[i][0] * grid[i][1] * grid[i][2] };
		//lastSeqV = { 1, grid[0][i] * grid[1][i] * grid[2][i] };

		for (int j = 0; j < size - 3; ++j)
		{
			/* 
			Note : Very confusing because of zeros
			// Horizontal
			int nextFirstH = grid[i][j]; 
			int nextMultH = lastSeqH.multipliedNextThree / lastSeqH.first * grid[i][j + 3];

			// Vertical
			int nextFirstV = grid[i][j];
			int nextMultV = lastSeqV.multipliedNextThree / lastSeqV.first * grid[j + 3][i];
			
			// Mult H
			int multiplication = lastSeqH.first * lastSeqH.multipliedNextThree;
			if (multiplication > maxMultiplication)
				maxMultiplication = multiplication;

			// Mult V
			 multiplication = lastSeqV.first * lastSeqV.multipliedNextThree;
			if (multiplication > maxMultiplication)
				maxMultiplication = multiplication;

			lastSeqH = { nextFirstH, nextMultH };
			lastSeqV = { nextFirstV, nextMultV };
			*/

			// Horizontal
			int multiplication = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
			if (multiplication > maxMultiplication)
				maxMultiplication = multiplication;

			// Vertical
			multiplication = grid[j][i] * grid[j + 1][i] * grid[j + 2][i] * grid[j + 3][i];
			if (multiplication > maxMultiplication)
				maxMultiplication = multiplication;
			
			// Diagonal right
			if (i < size -3)
			{
				multiplication = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
				if (multiplication > maxMultiplication)
					maxMultiplication = multiplication;

				// Diagonal left
					multiplication = grid[i][j+3] * grid[i + 1][j +2] * grid[i + 2][j +1] * grid[i + 3][j];
					if (multiplication > maxMultiplication)
						maxMultiplication = multiplication;
			}
		}
	}

	std::cout << maxMultiplication; 
	return 0; 
}