#include <queue>
#include <iostream>
using namespace std;
#include <vector>

int n, m;
long long int d[501];
vector<pair<int, int>> v[501];
bool check = false;

void reset()
{
	for (int i = 2; i <= n; i++)
		d[i] = 9876543210;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	reset();

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(to, cost));
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < v[j].size(); k++)
			{
				int next = v[j][k].first;
				int nextCost = v[j][k].second;

				if (d[j] != 9876543210 && d[next] > d[j] + nextCost)
				{
					d[next] = d[j] + nextCost;

					if (i == n)
						check = true;
				}
			}
		}
	}


	if (check)
		cout << -1;
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (d[i] >= 9876543210)
				cout << -1 << "\n";
			else
				cout << d[i] << "\n";
		}
	}

	return 0;
}
