#include <iostream>
using namespace std;
#include <vector>
#include <queue>

int n, m;
vector<pair<int, int>> v[10001];
bool check[10001] = { false };
int low = 1;
int high = 0;
int start, finish;
int result = 0;

void reset()
{
	for (int i = 1; i <= n; i++)
		check[i] = false;
}

bool bfs(int cost)
{
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		
		if (x == finish)
			return true;

		for (int i = 0; i < v[x].size(); i++)
		{
			int nx = v[x][i].first;
			int ncost = v[x][i].second;

			if (check[nx])
				continue;
			if (cost > ncost)
				continue;

			check[nx] = true;
			q.push(nx);
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		int weight;
		cin >> from >> to >> weight;
		high = max(high, weight);
		v[from].push_back(make_pair(to, weight));
		v[to].push_back(make_pair(from, weight));
	}

	cin >> start >> finish;

	while (low <= high)
	{
		reset();
		int mid = (low + high) / 2;

		if (bfs(mid))
			low = mid + 1;
		else
			high = mid - 1;
	}

	cout << low - 1;

	return 0;
}
