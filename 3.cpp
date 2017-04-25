#include <algorithm>
#include <vector>
#include <iostream>
#include <inttypes.h>

using std::sqrt;
using std::vector;

uint64_t sieveEratosthene(const uint64_t maxNumber)
{
	// Would be cleaner using a class than static
	static uint64_t sqrtNumber = ceil(sqrt(maxNumber));
	
	static std::vector<bool> numbers(sqrtNumber + 1, true);
	static uint64_t i = 2;

	for (; i <= sqrtNumber; ++i)
	{
		if (numbers[i])
		{
			for (uint64_t j = i*i; j <= sqrtNumber; j+=i)
				numbers[j] = false; 

			return i++;
		}
	}

	return maxNumber; 
}


int main()
{
	uint64_t number = 600851475143;

	int prime = sieveEratosthene(number); 
	while ( number > 1)
	{
		_lldiv_t division = std::lldiv(number, prime);
		if (division.rem == 0)
		{
			number = division.quot;
		}
		else
		{
			prime =	sieveEratosthene(number); 
		}
	}

	std::cout << prime; 

	return 0; 
}