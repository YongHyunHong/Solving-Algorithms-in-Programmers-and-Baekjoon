#include <iostream>
using namespace std;
#include <queue>
#include <tuple>

int arr[501][501];
bool check[501][501] = { false };

int h, w;
int answer = 0;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool c(int x, int y)
{
	bool left = false;
	bool right = false;

	for (int i = 0; i < y; i++)
	{
		if (arr[x][i] == 1)
			left = true;
	}

	for (int i = y + 1; i < w; i++)
	{
		if (arr[x][i] == 1)
			right = true;
	}

	if (left && right)
		return true;
	else
		return false;
}

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty())
	{
		int cx = get<0>(q.front());
		int cy = get<1>(q.front());
		q.pop();
		answer++;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (check[nx][ny])
				continue;
			if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				continue;
			if (!c(nx, ny))
				continue;
			if (arr[nx][ny] == 1)
				continue;

			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> h >> w;

	for (int i = 0; i < w; i++)
	{
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)
			arr[j][i] = 1;
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j] == 0 && !check[i][j] && c(i, j))
				bfs(i, j);
		}
	}

	cout << answer;

	return 0;
}
