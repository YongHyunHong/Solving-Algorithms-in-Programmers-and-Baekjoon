#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int k, n;
vector<long long int > v;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k >> n;

	for (int i = 0; i < k; i++)
	{
		long long int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	long long int low = 1;
	long long int high = v[v.size() - 1];

	while (low <= high)
	{
		long long int mid = (low + high) / 2;
		int sum = 0;

		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i] / mid;
		}

		if (sum >= n)
			low = mid + 1;
		else
			high = mid - 1;
	}

	cout << low - 1;

	return 0;
}
