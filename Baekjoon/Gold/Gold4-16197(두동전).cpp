#include <iostream>
using namespace std;
#include <queue>
#include <tuple>

int n, m;
char arr[21][21];
bool check[21][21][21][21] = { false };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int counts = 11;

int a = -1;
int b = -1;
int c = -1;
int d = -1;

bool checking(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m)
		return true;
	return false;
}

void bfs(int x1, int y1, int x2, int y2, int count)
{
	queue<tuple<int, int, int, int, int>>q;
	q.push(make_tuple(x1, y1, x2, y2, count));
	check[x1][y1][x2][y2] = true;

	while (!q.empty())
	{
		int cx1 = get<0>(q.front());
		int cy1 = get<1>(q.front());
		int cx2 = get<2>(q.front());
		int cy2 = get<3>(q.front());
		int ccount = get<4>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx1 = cx1 + dx[i];
			int ny1 = cy1 + dy[i];
			int nx2 = cx2 + dx[i];
			int ny2 = cy2 + dy[i];

			if (arr[nx1][ny1] == '#')
			{
				nx1 = cx1;
				ny1 = cy1;
			}
			if (arr[nx2][ny2] == '#')
			{
				nx2 = cx2;
				ny2 = cy2;
			}

			if (!checking(nx1, ny1) && checking(nx2, ny2))
			{
				counts = min(counts, ccount + 1);
				return;
			}
			if (checking(nx1, ny1) && !checking(nx2, ny2))
			{
				counts = min(counts, ccount + 1);
				return;
			}
			if (checking(nx1, ny1) && checking(nx2, ny2))
				continue;

			if (!check[nx1][ny1][nx2][ny2])
			{
				check[nx1][ny1][nx2][ny2] = true;
				q.push(make_tuple(nx1, ny1, nx2, ny2, ccount + 1));
			}
		}

	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++)
		{
			arr[i][j] = s[j];
			if (arr[i][j] == 'o')
			{
				if (a == -1)
				{
					a = i;
					b = j;
				}
				else
				{
					c = i;
					d = j;
				}
			}
		}
	}

	bfs(a, b, c, d, 0);

	if (counts == 11)
		cout << -1;
	else
		cout << counts;

	return 0;
}
