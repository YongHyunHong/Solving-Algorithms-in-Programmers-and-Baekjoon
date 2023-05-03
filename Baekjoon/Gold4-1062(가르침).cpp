#include <iostream>
using namespace std;
#include <string>
#include <vector>

int n, k;
bool check[26] = { false };

vector<string> v;
int result = 0;

void counting()
{
	int r = 0;
	for (int i = 0; i < v.size(); i++)
	{
		bool checking = true;

		for (int j = 0; j < v[i].size(); j++)
		{
			if (!check[v[i][j] - 'a'])
			{
				checking = false;
				break;
			}
		}

		if (checking)
			r++;
	}

	result = max(result, r);
}

void dfs(int index,int count)
{
	if (count == k)
	{
		counting();
		return;
	}
	
	for (int i = index + 1; i < 26; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			dfs(i, count + 1);
			check[i] = false;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	check['a' - 'a'] = true;
	check['n' - 'a'] = true;
	check['t' - 'a'] = true;
	check['i' - 'a'] = true;
	check['c' - 'a'] = true;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	if (k < 5)
	{
		cout << 0;
		return 0;
	}
	else if (k == 5)
	{
		counting();
	}
	else
	{
		for (int i = 0; i < 26; i++)
		{
			if (!check[i])
			{
				check[i] = true;
				dfs(i, 6);
				check[i] = false;
			}
		}
	}

	cout << result;

	return 0;
}
