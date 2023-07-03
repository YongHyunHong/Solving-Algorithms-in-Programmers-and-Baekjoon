#include <string>
#include <vector>
#include <iostream>

using namespace std;
int arr[101][101];
int arr2[101][101];
int n, m;
vector<int> answer;

void rotate(int x1, int y1, int x2, int y2)
{
    int minNum = n*m;
    
    for(int i=x1; i<=x2; i++)
    {
        for(int j=y1; j<=y2; j++)
        {
            if(i == x1 || i == x2 || j == y1 || j == y2)
            {
                minNum = min(minNum, arr[i][j]);
            }
        }
    }
    answer.push_back(minNum);
    
    
    for(int i=y1; i<y2; i++)
    {
        arr[x1][i+1] = arr2[x1][i];
    }
    for(int i=y2; i>y1; i--)
    {
        arr[x2][i-1] = arr2[x2][i];
    }
    for(int i=x1; i<x2; i++)
    {
        arr[i + 1][y2] = arr2[i][y2];
    }
    for(int i=x2; i>x1; i--)
    {
        arr[i-1][y1] = arr2[i][y1];
    }
    
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<= m; j++)
        {
            arr2[i][j] = arr[i][j];
        }
    }
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    
    n = rows;
    m = columns;
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<= m; j++)
        {
            arr[i][j] = (i-1) * m + j;
            arr2[i][j] = arr[i][j];
        }
    }
    
    for(int i=0; i<queries.size(); i++)
    {
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        
        rotate(x1, y1, x2, y2);
    }
    

    
    
    return answer;
}