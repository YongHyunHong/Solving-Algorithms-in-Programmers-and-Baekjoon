#include <string>
#include <vector>
#include <iostream>

using namespace std;
long long int dp[500001][2];

long long solution(vector<int> sequence) {
    long long answer = 0;
    
    for(int i=0; i<sequence.size(); i++)
    {
        dp[i][0] = sequence[i];
        dp[i][1] = -sequence[i];
    }
    
    for(int i=1; i<sequence.size(); i++)
    {
        dp[i][0] = max(dp[i][0], dp[i - 1][1] + sequence[i]);
        dp[i][1] = max(dp[i][1], dp[i - 1][0] - sequence[i]);
    }
    
    for(int i=0; i<sequence.size(); i++)
    {
        answer = max(answer, max(dp[i][0], dp[i][1]));
    }
    
    return answer;
}
