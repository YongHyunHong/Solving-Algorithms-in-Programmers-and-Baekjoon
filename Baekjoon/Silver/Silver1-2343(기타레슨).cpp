#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int n, m;
vector<int> v;
long long int low = 0;
long long int high = 1000000000;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		long long int a;
		cin >> a;
		low = max(low, a);
		v.push_back(a);
	}


	while (low <= high)
	{
		long long int mid = (low + high) / 2;
		long long int counts = 0;
		long long int sum = 0;

		for (int i = 0; i < v.size(); i++)
		{
			if (sum + v[i] <= mid)
				sum += v[i];
			else
			{
				counts++;
				sum = v[i];
			}
		}

		if (sum > 0)
			counts++;

		if (counts <= m)
			high = mid - 1;
		else
			low = mid + 1;
	}

	cout << high + 1;

	return 0;
}
