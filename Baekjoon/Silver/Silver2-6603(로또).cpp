#include <iostream>
using namespace std;
#include <vector>

int k;
vector<int> v;

void dfs(int index,vector<int> result)
{
	if (result.size() == 6)
	{
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = index + 1; i < v.size(); i++)
	{
		result.push_back(v[i]);
		dfs(i, result);
		result.erase(--result.end());
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	
	while (true)
	{
		cin >> k;
		v.clear();
		if (k == 0)
			break;

		for (int i = 0; i < k; i++)
		{
			int a;
			cin >> a;
			v.push_back(a);
		}

		for (int i = 0; i < v.size(); i++)
		{
			vector<int> t;
			t.push_back(v[i]);
			dfs(i, t);
		}
		cout << "\n";
	}


	return 0;
}
