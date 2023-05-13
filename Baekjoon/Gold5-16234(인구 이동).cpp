#include <iostream>
using namespace std;
#include <queue>
#include <tuple>
#include <math.h>

int n, l, r;
int arr[51][51];
int arr2[51][51];
bool check[51][51] = { false };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void move(int x, int y)
{
	vector<pair<int, int>> v;
	
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		v.push_back(make_pair(cx, cy));

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (check[nx][ny])
				continue;
			if (abs(arr[nx][ny] - arr[cx][cy]) < l || abs(arr[nx][ny] - arr[cx][cy]) > r)
				continue;

			check[nx][ny] = true;
			q.push(make_pair(nx, ny));
		}
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
		sum += arr[v[i].first][v[i].second];

	for (int i = 0; i < v.size(); i++)
		arr2[v[i].first][v[i].second] = sum / v.size();
}

void reset()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			check[i][j] = false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			arr2[i][j] = arr[i][j];
		}
	}

	int result = 0;

	while (true)
	{
		reset();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!check[i][j])
					move(i, j);
			}
		}

		bool checking = false;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] != arr2[i][j])
					checking = true;
			}
		}

		if (!checking)
			break;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = arr2[i][j];
			}
		}

		result++;
	}

	cout << result;

	return 0;
}
