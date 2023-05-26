#include <iostream>
using namespace std;
#include <queue>
int n;

int node[10001];
vector<int> v[10001];
int second[10001];
int dp[10001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> second[i];

		int count;
		cin >> count;

		node[i] += count;

		for (int j = 0; j < count; j++)
		{
			int a;
			cin >> a;
			v[a].push_back(i);
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (node[i] == 0)
		{
			q.push(i);
			dp[i] = second[i];
		}
	}

	while (!q.empty())
	{
		int cx = q.front();
		q.pop();

		for (int i = 0; i < v[cx].size(); i++)
		{
			int nx = v[cx][i];
			node[nx]--;

			dp[nx] = max(dp[nx], dp[cx] + second[nx]);

			if (node[nx] == 0)
				q.push(nx);
		}
	}

	
	int result = 0;
	for (int i = 1; i <= n; i++)
		result = max(result, dp[i]);

	cout << result;

	return 0;
}
