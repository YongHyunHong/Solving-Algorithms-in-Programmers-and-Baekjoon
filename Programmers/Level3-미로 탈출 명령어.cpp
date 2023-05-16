#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
char arr[51][51];
bool check[51][51][2501];
string answer = "";
vector<string> v;
bool checking = false;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};

void bfs(int x, int y, int n, int m, int k)
{
    queue<tuple<int, int, string>> q;
    string start = "";
    q.push(make_tuple(x, y, start));
    check[x][y][0] = true;
    
    while(!q.empty())
    {
        int cx = get<0>(q.front());
        int cy = get<1>(q.front());
        string st = get<2>(q.front());
        q.pop();
        
        
        if(arr[cx][cy] == 'E' && st.size() == k)
        {
            checking = true;
            answer = st;
            return;
        }
        if(st.size() > k)
            return;
        
        for(int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int size = st.size();
            string nSt = st;
            
            if(nx > n || ny > m || nx <=0 || ny <= 0)
                continue;
            if(check[nx][ny][size + 1])
                continue;
            
            if(i == 0)
                nSt += 'd';
            else if(i == 1)
                nSt += 'l';
            else if(i == 2)
                nSt += 'r';
            else
                nSt += 'u';
            
            check[nx][ny][nSt.size()] = true;
            q.push(make_tuple(nx, ny, nSt));
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(i == x && j == y)
                arr[i][j] = 'S';
            if(i == r && j == c)
                arr[i][j] = 'E';
        }
    }
    
    bfs(x, y, n, m, k);
  
    if(!checking)
        answer = "impossible";

    
    return answer;
}
