#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

int dp[100001];
int dp2[100001];
int dp3[100001];

int solution(vector<int> sticker)
{
    int answer = 0;
    
    if(sticker.size() == 1)
        return sticker[0];
    else if(sticker.size() == 2)
        return max(sticker[0], sticker[1]);
    else if(sticker.size() == 3)
        return max(sticker[2] + sticker[0], sticker[1]);
    
    
    
    dp[0] = sticker[0];
    dp[1] = 0;
    dp[2] = sticker[0] + sticker[2];
    
    for(int i=3; i<sticker.size() - 1; i++)
    {
        dp[i] = max(dp[i - 2], dp[i - 3]) + sticker[i];
        
        answer = max(answer, dp[i]);
    }
    
    dp2[0] = 0;
    dp2[1] = sticker[1];
    dp2[2] = 0;

    for(int i=3; i<sticker.size(); i++)
    {
        dp2[i] = max(dp2[i - 2], dp2[i - 3]) + sticker[i];
        
        answer = max(answer, dp2[i]);
    }

    dp3[0] = 0;
    dp3[1] = 0;
    dp3[2] = sticker[2];

    for(int i=3; i<sticker.size(); i++)
    {
        dp3[i] = max(dp3[i - 2], dp3[i - 3]) + sticker[i];
        
        answer = max(answer, dp3[i]);
    }
    
    return answer;
}