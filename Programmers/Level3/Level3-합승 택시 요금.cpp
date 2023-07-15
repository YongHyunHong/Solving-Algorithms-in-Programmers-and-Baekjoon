#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int answer = 987654321;

int d[201][201];

void reset()
{
    for(int i=1; i<=200; i++)
    {
        for(int j=1; j<=200; j++)
        {
            if(i != j)
                d[i][j] = 987654321;
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    
    reset();
    
    for(int i=0; i<fares.size(); i++)
    {
        int from = fares[i][0];
        int to = fares[i][1];
        int cost = fares[i][2];
        
        d[from][to] = cost;
        d[to][from] = cost;
    }
    
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    
    
    for(int i=1; i<=n; i++)
    {
        if(d[s][i] != 987654321 && d[i][a] != 987654321 && d[i][b] != 987654321)
            answer = min(answer, d[s][i] + d[i][a] + d[i][b]);
    }
    
    return answer;
}