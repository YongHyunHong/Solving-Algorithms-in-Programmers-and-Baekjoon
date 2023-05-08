#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <tuple>

using namespace std;
char arr[101][101];
bool check[101][101] = {false};
int answer = 987654321;
int n, m;
int endX, endY;

void bfs(int x, int y)
{
    queue<tuple<int, int ,int>> q;
    q.push(make_tuple(x ,y, 0));
    check[x][y] = true;
    
    while(!q.empty())
    {
        int cx = get<0>(q.front());
        int cy = get<1>(q.front());
        int ccost = get<2>(q.front());
        q.pop();
        
        if(cx == endX && cy == endY)
        {
            answer = min(answer, ccost);
            return;
        }
        
        for(int i=0; i<4; i++)
        {
            int nx = cx;
            int ny = cy;
            
            if(i == 0) // 왼
            {
                while(true)
                {
                    if(ny == 0 || arr[nx][ny - 1] == 'D')
                        break;
                    
                    ny--;
                }
            }
            else if(i == 1) // 위
            {
                while(true)
                {
                    if(nx == 0 || arr[nx - 1][ny] == 'D')
                        break;
                    nx--;
                }
            }
            else if(i == 2) // 오
            {
                while(true)
                {
                    if(ny == m - 1 || arr[nx][ny + 1] == 'D')
                        break;
                    ny++;
                }
            }
            else // 아
            {
                while(true)
                {
                    if(nx == n - 1 || arr[nx + 1][ny] == 'D')
                        break;
                    nx++;
                }
            }
            
            if(!check[nx][ny])
            {
                check[nx][ny] = true;
                q.push(make_tuple(nx, ny, ccost + 1));
            }
        }
    }
}

int solution(vector<string> board) {
    
    int startX = 0;
    int startY = 0;
    n = board.size();
    
    for(int i=0; i<board.size(); i++)
    {
        m = board[i].size();
        for(int j=0; j<board[i].size(); j++)
        {
            arr[i][j] = board[i][j];
            if(arr[i][j] == 'R')
            {
                startX = i;
                startY = j;
            }
            
            if(arr[i][j] == 'G')
            {
                endX = i;
                endY = j;
            }
        }
    }
        
    bfs(startX, startY);
    
    if(answer == 987654321)
        answer = -1;
    
    
    return answer;
}
