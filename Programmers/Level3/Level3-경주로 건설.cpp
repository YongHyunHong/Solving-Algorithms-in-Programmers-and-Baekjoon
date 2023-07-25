#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int arr[26][26];
int dx[] = {-1, 0, 1, 0}; // 상, 우, 하, 좌
int dy[] = {0, 1, 0, -1};

int d[26][26];
int answer = 987654321;
int n;

void reset()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            d[i][j] = 987654321;
        }
    }
}

void da(int dic)
{
    //queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, greater<tuple<int,int,int,int>>> q;
    queue<tuple<int,int,int,int>> q;
    q.push(make_tuple(0, 0, 0, dic));
    
    while(!q.empty())
    {
        int cost = get<0>(q.front());
        int cx = get<1>(q.front());
        int cy = get<2>(q.front());
        int dic = get<3>(q.front());
        q.pop();
        
        if(d[cx][cy] < cost)
            continue;
        d[cx][cy] = cost;
        
        if(cx == n-1 && cy == n-1)
        {
            answer = min(answer, cost);
        }
        
        for(int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int ncost;
            
            if(nx < 0 || nx >= n || ny < 0 || ny >=n)
                continue;
            if(arr[nx][ny] == 1)
                continue;
            
            if(dic%2 == i%2)
                ncost = cost + 100;
            else
                ncost = cost + 600;
            
            if(d[nx][ny] >= ncost)
            {
                d[nx][ny] = ncost;
                q.push(make_tuple(ncost, nx, ny, i));
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    n = board.size();
    
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            arr[i][j] = board[i][j];
        }
    }
    
    reset();
    da(1);
    
    reset();
    da(2);
    
    

    
    return answer;
}