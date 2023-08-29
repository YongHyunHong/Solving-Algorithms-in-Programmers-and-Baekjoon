#include <iostream>
using namespace std;
#include <stack>

string s;
int command;
stack<char> l;
stack<char> r;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s >> command;

	for (int i = 0; i < s.size(); i++)
		l.push(s[i]);

	for (int i = 0; i < command; i++)
	{
		char op, letter;
		cin >> op;

		if (op == 'L')
		{
			if (l.empty())
				continue;

			r.push(l.top());
			l.pop();
		}
		else if (op == 'D')
		{
			if (r.empty())
				continue;

			l.push(r.top());
			r.pop();
		}
		else if (op == 'B')
		{
			if (l.empty())
				continue;

			l.pop();
		}
		else
		{
			cin >> letter;
			l.push(letter);
		}
	}

	while (!l.empty())
	{
		r.push(l.top());
		l.pop();
	}

	while (!r.empty())
	{
		cout << r.top();
		r.pop();
	}

	return 0;
}