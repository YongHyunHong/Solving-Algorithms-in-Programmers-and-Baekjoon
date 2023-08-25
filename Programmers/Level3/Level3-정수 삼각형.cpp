#include <string>
#include <vector>
#include <iostream>

using namespace std;
int arr[501][501];
int dp[501][501];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int len = triangle.size();
    
    for(int i=0; i<triangle.size(); i++)
    {
        for(int j=0; j<triangle[i].size(); j++)
            arr[i][j] = triangle[i][j];
    }
    
    dp[0][0] = arr[0][0];
    for(int i=1; i<len; i++)
    {
        dp[i][0] = dp[i-1][0] + arr[i][0];
    }
    
    for(int i=1; i<len; i++)
    {
        for(int j=0; j<len; j++)
        {
            if(j == 0)
                dp[i][0] = dp[i-1][0] + arr[i][0];
            else if(i == j)
                dp[i][i] = dp[i-1][i-1] + arr[i][i];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - 1]) + arr[i][j];
        }
    }
    
    for(int i=0; i<len; i++)
    {
        answer = max(answer, dp[len-1][i]);
    }
    
    return answer;
}