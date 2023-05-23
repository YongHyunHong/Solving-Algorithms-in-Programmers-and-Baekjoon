#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int n, d;
vector<pair<int, int>> v[10001];
int cost[100001];

void da()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, 0));
	cost[0] = 0;

	while (!q.empty())
	{
		int cx = q.top().second;
		int ccost = q.top().first;
		q.pop();

		if (cost[cx] < ccost)
			continue;
		if (cx == d)
		{
			cout << ccost;
			cout << "\n";
			return;
		}


		for (int i = 0; i < v[cx].size(); i++)
		{
			int nx = v[cx][i].first;
			int ncost = v[cx][i].second + ccost;

			if (ncost < cost[nx])
			{
				cost[nx] = ncost;
				q.push(make_pair(ncost, nx));
			}
		}

		int nx = cx + 1;
		int ncost = ccost + 1;

		if (ncost < cost[nx])
		{
			cost[nx] = ncost;
			q.push(make_pair(ncost, nx));
		}
	}
}

void reset()
{
	for (int i = 0; i <= d; i++)
		cost[i] = 987654321;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> d;
	reset();

	for (int i = 0; i < n; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		v[from].push_back(make_pair(to, cost));
	}

	da();

	return 0;
}
