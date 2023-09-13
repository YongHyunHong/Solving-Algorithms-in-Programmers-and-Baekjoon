#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <tuple>

using namespace std;

bool check[100000001] = {false};
int answer = 0;

void bfs(int x)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, 0));
    check[x] = true;
    
    while(!q.empty())
    {
        int cx = get<0>(q.front());
        int ccost = get<1>(q.front());
        q.pop();
        
        cout<<cx<<" "<<ccost<<"\n";
        
        if(cx == 0)
        {
            answer = ccost;
            return;
        }
        
        int nx, ncost;
        
        if(cx % 10 < 5)
        {
            ncost = ccost + (cx % 10);
            nx = cx / 10;
        }
        else if(cx % 10 > 5)
        {
            ncost = ccost + 10 - (cx % 10);
            nx = cx / 10 + 1;
        }
        else
        {
            if(cx % 100 < 50)
            {
                ncost = ccost + (cx % 10);
                nx = cx / 10;
            }
            else
            {
                ncost = ccost + 10 - (cx % 10);
                nx = cx / 10 + 1;
            }
        }
        
        
        if(nx >=0 && nx <= 100000000 && !check[nx])
        {
            check[nx] = true;
            q.push(make_pair(nx, ncost));
        }
    }
}

int solution(int storey) {
    
    bfs(storey);
    
    return answer;
}