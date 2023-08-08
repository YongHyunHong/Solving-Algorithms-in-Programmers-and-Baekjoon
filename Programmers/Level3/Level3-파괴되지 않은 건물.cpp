#include <string>
#include <vector>
#include <iostream>

using namespace std;
int arr[1002][1002];

int n, m;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    
    int answer = 0;
    
    n = (int)board.size();
    m = (int)board[0].size();
    
    for(int i=0; i<skill.size(); i++)
    {
        int type = skill[i][0];
        
        int x1 = skill[i][1];
        int y1 = skill[i][2];
        int x2 = skill[i][3];
        int y2 = skill[i][4];
        
        int degree = skill[i][5];
    
    
        if(type == 1)
        {
            arr[x1][y1] -= degree;
            arr[x2 + 1][y2 + 1] -= degree;
            arr[x1][y2 + 1] += degree;
            arr[x2 + 1][y1] += degree;
        }
        else
        {
            arr[x1][y1] += degree;
            arr[x2 + 1][y2 + 1] += degree;
            arr[x1][y2 + 1] -= degree;
            arr[x2 + 1][y1] -= degree;
        }
    }
    
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            arr[i][j] += arr[i - 1][j];
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            arr[i][j] += arr[i][j - 1];
        }
    }
    
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
            arr[i][j] += board[i][j];
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j] > 0)
                answer++;
        }
    }
    
    return answer;
}