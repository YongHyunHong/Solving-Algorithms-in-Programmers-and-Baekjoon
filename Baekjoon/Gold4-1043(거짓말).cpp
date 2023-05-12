#include <iostream>
using namespace std;
#include <vector>

int n, m;
int parent[51];
vector<int> p[51];

void reset()
{
	for (int i = 1; i <= n; i++)
		parent[i] = i;
}

int find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	
	if (x != y)
		parent[x] = y;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int know;
	cin >> know;
	reset();

	int answer = 0;

	vector<int> v;
	for (int i = 0; i < know; i++)
	{
		int knowPeople;
		cin >> knowPeople;
		v.push_back(knowPeople);
	}
	if (v.size() >= 2)
	{
		for (int i = 0; i < v.size() - 1; i++)
			Union(v[i], v[i + 1]);
	}


	for (int i = 0; i < m; i++)
	{
		int partyPeople;
		cin >> partyPeople;

		vector<int> v2;

		for (int j = 0; j < partyPeople; j++)
		{
			int a;
			cin >> a;
			v2.push_back(a);
			p[i].push_back(a);
		}
		if (v2.size() >= 2)
		{
			for (int i = 0; i < v2.size() - 1; i++)
				Union(v2[i], v2[i + 1]);
		}
	}

	if (v.size() == 0)
	{
		cout << m;
		return 0;
	}

	for (int i = 0; i < m; i++)
	{
		bool check = true;
		for (int j = 0; j < p[i].size(); j++)
		{
			if (find(parent[v[0]]) == find(parent[p[i][j]]))
				check = false;
		}
		if (check)
			answer++;
	}

	cout << answer;

	return 0;
}
