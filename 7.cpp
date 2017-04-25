#include <vector>
#include <iostream>

using std::vector;
using std::cout;

int main()
{
	const int limit = 10001;
	int size = limit * log(limit) * 1.5f;

	vector<bool> sieveGrid(size, true); 

	int count = 0;
	int i = 2;

	for (; i*i <= size; ++i)
	{
		if (sieveGrid[i])
		{
			++count;

			for (int j = i*i; j < size; j+=i)
			{
				sieveGrid[j] = false;
			}
	}
	}

	int result = 0; 
	for (; count < limit; ++i)
	{
		if (sieveGrid[i])
		{
			++count;
			result = i; 
		}
	}

	std::cout << result; 
}