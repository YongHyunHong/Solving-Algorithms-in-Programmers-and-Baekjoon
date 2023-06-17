#include <iostream>
using namespace std;

bool check[10001] = { false };

int add(int x)
{
	int sum = 0;

	while (true)
	{
		if (x == 0)
			break;
		
		sum += x % 10;
		x /= 10;
	}

	return sum;
}

int main(void)
{
	
	for (int i = 1; i <= 10000; i++)
	{
		if (!check[i])
		{
			int j = i;

			while (true)
			{
				if (j > 10000)
					break;

				j += add(j);
				check[j] = true;
			}
		}
	}


	for (int i = 1; i <= 10000; i++)
	{
		if (!check[i])
			cout << i << "\n";
	}

	return 0;
}