#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, int>> v[50001];
bool check[50001] = {false};

int minSummits = 50000;
int minIntensity = 10000000;

void bfs(int x, vector<int> summits)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, x));
    
    int maxResult = 0;
    
    while(!q.empty())
    {
        int cx = q.top().second;
        int ccost = q.top().first;
        q.pop();
        
        if(check[cx])
            continue;
        check[cx] = true;
        
        maxResult = max(maxResult, ccost);
        
        if(find(summits.begin(), summits.end(), cx) != summits.end())
        {
            if(maxResult < minIntensity)
            {
                minIntensity = maxResult;
                minSummits = cx;
            }
            else if(maxResult == minIntensity)
                minSummits = min(minSummits, cx);
            
            return;
        }
        
        for(int i = 0; i < v[cx].size(); i++)
        {
            int nx = v[cx][i].first;
            int ncost = v[cx][i].second;
            q.push(make_pair(ncost, nx));
        }
        
    }
}

void reset(int start, vector<int> gates, int n)
{
    for(int i = 1; i <= n; i++)
    {
        check[i] = false;
    }
    
    for(int i = 0; i <gates.size(); i++)
    {
        if(start != i)
            check[gates[i]] = true;
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    for(int i = 0; i < paths.size(); i++)
    {
        int from = paths[i][0];
        int to = paths[i][1];
        int cost = paths[i][2];
        
        v[from].push_back(make_pair(to, cost));
        v[to].push_back(make_pair(from, cost));
    }
    
    for(int i = 0; i < gates.size(); i++)
    {
        reset(i, gates, n);
        bfs(gates[i], summits);
    }
    
    answer.push_back(minSummits);
    answer.push_back(minIntensity);
    
    return answer;
}
