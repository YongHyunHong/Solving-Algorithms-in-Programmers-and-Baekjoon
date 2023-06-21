#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
vector<string> answer;
map<string, int> m;
vector<int> c;
int counts[11];

void dfs(int index, string add, string s)
{   
    if(find(c.begin(), c.end(), add.size()) != c.end())
        m[add]++;
    
    if(add.size() == s.size())
        return;
    
    for(int i=index; i<s.size(); i++)
    {
        add += s[i];
        dfs(i + 1, add, s);
        add.erase(--add.end());
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    c = course;
    
    for(int i=0; i<orders.size(); i++)
    {
        string s = orders[i];
        sort(s.begin(), s.end());
        
        dfs(0, "", s);
    }
    
    // for(auto it = m.begin(); it!=m.end(); it++)
    // {
    //     if(it->second >1)
    //         cout<<it->first<<" "<<it->second<<"\n";
    // }
    
    
    for(auto it = m.begin(); it!=m.end(); it++)
    {
        string s = it->first;
        counts[s.size()] = max(counts[s.size()], it->second);
    }
    
    for(auto it = m.begin(); it!=m.end(); it++)
    {
        string s = it->first;
        if(counts[s.size()] == it->second && counts[s.size()] > 1)
        {
            answer.push_back(it->first);
        }
    }
    
    
    return answer;
}