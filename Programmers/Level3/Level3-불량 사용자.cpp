#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> user;
vector<string> ban;
int answer = 0;
bool correct[9] = {false};

set<string> s;

void dfs(int index, vector<string> v)
{
    //cout<<v.size()<<"\n";
    if(v.size() == ban.size())
    {
        //cout<<v.size()<<"\n";
        string result = "";
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++)
            result += v[i];

        s.insert(result);
        
        return;
    }
    
    if(index == user.size())
        return;
    
    for(int i=0; i<user.size(); i++)
    {
        
        if(ban[index].size() != user[i].size())
            continue;
        
        bool check = true;
        for(int j=0; j<ban[index].size(); j++)
        {
            if(ban[index][j] == '*')
                continue;
            
            if(ban[index][j] != user[i][j])
            {
                check = false;
                break;
            }
        }
        
        if(check && !correct[i])
        {
            correct[i] = true;
            v.push_back(user[i]);
            
            dfs(index + 1, v);
            
            v.erase(--v.end());
            correct[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    user = user_id;
    ban = banned_id;

    vector<string> v;
    dfs(0, v);
    
    answer = s.size();
        
    
    return answer;
}
