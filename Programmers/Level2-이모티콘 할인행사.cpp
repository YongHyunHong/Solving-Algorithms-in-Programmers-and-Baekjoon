#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;
int e[8];
int price[8];
int eSize;
vector<pair<int ,int>> user;
vector<int> answer;
map<int, int> m;
int maxNum = 0;

void dfs(int c)
{
    if(c == eSize)
    {   
        int sum = 0;
        int plusUser = 0;
        
        for(int i=0; i<user.size(); i++)
        {
            int userPersent = user[i].first;
            int userMoney = user[i].second;
            
            int buy = 0;
            
            for(int j=0; j<eSize; j++)
            {
                if(userPersent <= e[j])
                    buy += price[j] * (100 - e[j]) / 100;
            }
            
            if(buy >= userMoney)
                plusUser++;
            else
                sum += buy;
        }
        
        maxNum = max(maxNum, plusUser);
        
        if(m[plusUser] == 0)
            m[plusUser] = sum;
        else
            m[plusUser] = max(m[plusUser], sum);
        
        return;
    }


    for(int i=1; i<=4; i++)
    {
        e[c] = 10 * i;
        
        /*
        e[0] = 10;
            10
                10
                20
                30
                40
            20
            30
            40
        */
        dfs(c + 1);
    }
    
    
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    
    eSize = emoticons.size();
    
    for(int i=0; i<users.size(); i++)
        user.push_back(make_pair(users[i][0], users[i][1]));
    
    for(int i=0; i<emoticons.size(); i++)
        price[i] = emoticons[i];
    
    dfs(0);

    answer.push_back(maxNum);
    answer.push_back(m[maxNum]);
    
    return answer;
}
