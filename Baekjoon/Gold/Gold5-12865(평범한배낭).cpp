#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int n, k;

int dp[101][100001]; // 배낭을 i 개 넣었을 때 최대 값 j
int weight[101];
int value[101];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> weight[i] >> value[i];
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j - weight[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];

	return 0;
}
