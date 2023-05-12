#include <iostream>
using namespace std;
#include <vector>

int n, m, k;
int arr[16][16];
int result = 0;
int dp[16][16][2];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	int c = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = c;
			c++;
		}
	}

	if (k == 0)
		dp[1][1][1] = 1;
	else
		dp[1][1][0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (!(i == 1 && j == 1))
			{
				dp[i][j][1] = dp[i - 1][j][1] + dp[i][j - 1][1];
				dp[i][j][0] = dp[i - 1][j][0] + dp[i][j - 1][0];

				if (arr[i][j] == k)
					dp[i][j][1] += dp[i][j][0];
			}
		}
	}

	cout << dp[n][m][1];

	return 0;
}
