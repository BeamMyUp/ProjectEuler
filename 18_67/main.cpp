#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using std::ifstream; 
using std::vector; 
using std::max; 
using std::cout;
using std::endl;

int main(int argc, char** argv)
{
	ifstream file(argv[1]);
	if (!file.is_open())
		return 1; 

	int nbLines;
	file >> nbLines;

	vector<int> numbers;
	numbers.reserve(nbLines * (nbLines + 1) / 2);

	int i = 0;
	while (!file.eof())
	{
		file >> i;
		numbers.emplace_back(i); 
	}

	
	auto it = numbers.rbegin(); 
	auto itParent = numbers.rbegin() + nbLines; 

	for (int cLine = nbLines; cLine > 1; --cLine)
	{
		for (int i = 0; i < cLine - 1; ++i, ++it, ++itParent)
			*itParent = *itParent + max(*it, *(it + 1));

		++it; 
	}

	cout << numbers[0] << endl;

	return 0; 
}