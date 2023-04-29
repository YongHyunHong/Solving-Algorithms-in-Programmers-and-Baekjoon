#include <iostream>
using namespace std;

int n, m, b;
int arr[501][501];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	int count = 987654321;
	int height = 0;

	for (int z = 0; z <= 256; z++)
	{
		int c = 0;
		int block = b;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == z)
					continue;
				if (arr[i][j] > z)
				{
					int index = arr[i][j] - z;
					c = c + 2 * index;
					block += arr[i][j] - z;
				}
				else
				{
					int index = z - arr[i][j];
					c = c + index;
					block -= z - arr[i][j];
				}
			}
		}

		if (block >= 0)
		{
			if (count >= c)
			{
				height = z;
				count = c;
			}
		}
	}

	cout << count << " " << height;

	return 0;
}
