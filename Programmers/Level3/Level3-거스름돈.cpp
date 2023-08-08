#include <string>
#include <vector>
#include <iostream>

using namespace std;
int dp[100001];

int solution(int n, vector<int> money) {
    int answer = 0;
    
    dp[0] = 1;
    
    
    
    for(int j=0; j< money.size(); j++)
    {
        for(int i=0; i<=n; i++)
        {
            if(i - money[j] >= 0)
                dp[i] += dp[i - money[j]];
        }
    }
    
    answer = dp[n];
    
    return answer;
}