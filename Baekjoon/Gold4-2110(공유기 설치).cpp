#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int n, c;
vector<long long int >v;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;


	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());

	long long int start = 0;
	long long int end = v[v.size() - 1];

	while (start <= end)
	{
		long long int mid = (start + end) / 2;
		int count = 1;

		long long int begin = v[0];

		for (int i = 1; i < v.size(); i++)
		{
			if (v[i] - begin >= mid)
			{
				count++;
				begin = v[i];
			}
		}

		if (count < c)
			end = mid - 1;
		else
			start = mid + 1;
	}

	cout << start - 1;

	return 0;
}
