#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;
vector<int> v[100001];
bool check[100001] = {false, };

map<int, int> result;

vector<int> answer;

void bfs(int start)
{
    queue<pair<int,int>> q;
    q.push(make_pair(start, 0));
    check[start] = true;
    
    while(!q.empty())
    {
        int cx = q.front().first;
        int ccost = q.front().second;
        q.pop();
        
        result[cx] = ccost;
        
        for(int i=0; i<v[cx].size(); i++)
        {
            int nx = v[cx][i];
            
            if(!check[nx])
            {
                check[nx] = true;
                q.push(make_pair(nx, ccost + 1));
            }
        }
    }
}

void reset()
{
    for(int i=0; i<=100000; i++)
    {
        check[i] = false;
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    
    reset();
    
    for(int i=0; i<roads.size(); i++)
    {
        int from = roads[i][0];
        int to = roads[i][1];
        
        v[from].push_back(to);
        v[to].push_back(from);
    }
    
    for(int i=0; i<sources.size(); i++) // 부대원 위치
    {
        result[sources[i]] = -1;
    }
    
    bfs(destination);
    
    for(int i=0; i<sources.size(); i++) // 부대원 위치
    {
        answer.push_back(result[sources[i]]);
    }
    
    return answer;
}