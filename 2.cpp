#include <iostream>

int main()
{
	int previ_2 = 1; 
	int sum = 0; 

	int currentVal = 2;
	
	while(currentVal < 4000000)
	{
		// first is even
		sum += currentVal;

		// it 1 : compute n+1 which is odd
		// it 2 : compute n+2 which is also odd
		// it 3 : compute n+3 which will be even (add to the sum next iteration)
		for (int i = 0; i < 3; ++i)
		{
			currentVal += previ_2;
			previ_2 = currentVal - previ_2;
		}
	}

	std::cout << sum; 

	return 0; 
}