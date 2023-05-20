#include <iostream>
using namespace std;
#include <vector>
#include <stack>

long long int result = -9876543210;
int n;
bool check[20] = { false };
string s = "";

void cal()
{
	stack<long long int> num;
	
	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]))
		{
			if (check[i])
			{
				if (num.empty())
				{
					long long int front = s[i] - '0';
					long long int back = s[i + 2] - '0';

					if (s[i + 1] == '-')
						num.push(front - back);
					else if (s[i + 1] == '+')
						num.push(front + back);
					else
						num.push(front * back);

					i += 2;
				}
				else
				{
					long long int front = s[i] - '0';
					long long int back = s[i + 2] - '0';
					long long int r = 0;

					if (s[i + 1] == '-')
						r = front - back;
					else if (s[i + 1] == '+')
						r = front + back;
					else
						r = front * back;

					long long int x = num.top();
					num.pop();

					if (s[i - 1] == '-')
						num.push(x - r);
					else if (s[i - 1] == '+')
						num.push(x + r);
					else
						num.push(x * r);

					i += 2;
				}
			}
			else
			{
				if (num.empty())
					num.push(s[i] - '0');
				else
				{
					long long int front = num.top();
					num.pop();
					long long int back = s[i] - '0';

					if (s[i - 1] == '-')
						num.push(front - back);
					else if (s[i - 1] == '+')
						num.push(front + back);
					else
						num.push(front * back);
				}
			}
		}
	}

	result = max(result, num.top());
}

void dfs()
{
	cal();

	
	for (int i = 2; i < s.size(); i++)
	{
		if (i % 2 == 0)
		{
			if (!check[i - 2] && !check[i])
			{
				check[i - 2] = true;
				dfs();
				check[i - 2] = false;
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
		char c;
		cin >> c;
		s += c;
	}
	dfs();


	cout << result;


	return 0;
}
