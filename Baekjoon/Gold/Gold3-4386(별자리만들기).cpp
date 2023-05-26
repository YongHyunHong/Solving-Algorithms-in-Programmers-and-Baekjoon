#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <math.h>

int n;
bool check[101];
double result = 0;

vector<pair<double, double>> v;

void MST()
{
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		int x = q.top().second;
		double cost = q.top().first;
		q.pop();

		if (check[x])
			continue;
		check[x] = true;
		result += cost;

		for (int i = 0; i < v.size(); i++)
		{
			if (i != x)
			{
				double nextCost = pow((v[x].first - v[i].first), 2) + pow((v[x].second - v[i].second), 2);
				q.push(make_pair(sqrt(nextCost), i));
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	MST();

	cout.precision(2);
	cout << fixed;
	cout << result;

	return 0;
}
