#include <iostream>
using namespace std;
#include <queue>
#include <tuple>

char arr[51][51];
char arr2[51][51];
int r, c;
bool check[51][51] = { false };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

queue<tuple<int, int, int>> q;

int desX;
int desY;

void water(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c)
			continue;

		if (arr2[nx][ny] == '.' || arr2[nx][ny] == 'S')
			arr2[nx][ny] = '*';
	}
}

void move(int x, int y, int cost)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= r || ny >= c)
			continue;
		if (check[nx][ny])
			continue;

		if (arr[nx][ny] == '.' || arr[nx][ny] == 'D')
		{
			q.push(make_tuple(nx, ny, cost + 1));
			check[nx][ny] = true;
		}
	}
}

void reset()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			check[i][j] = false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;

	for (int i = 0; i < r; i++ )
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			arr[i][j] = s[j];
			arr2[i][j] = arr[i][j];

			if (arr[i][j] == 'S')
			{
				q.push(make_tuple(i, j, 0));
				check[i][j] = true;
			}

			if (arr[i][j] == 'D')
			{
				desX = i;
				desY = j;
			}
		}
	}


	while (true)
	{
		if (q.empty())
			break;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] == '*')
					water(i, j);
			}
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				arr[i][j] = arr2[i][j];
			}
		}

		int size = q.size();
		int count = 0;

		while (true)
		{
			if (size == count)
				break;
			count++;

			int cx = get<0>(q.front());
			int cy = get<1>(q.front());
			int ccost = get<2>(q.front());

			q.pop();

			if (cx == desX && cy == desY)
			{
				cout << ccost;
				return 0;
			}

			move(cx, cy, ccost);
		}
	}

	cout << "KAKTUS";

	return 0;
}
