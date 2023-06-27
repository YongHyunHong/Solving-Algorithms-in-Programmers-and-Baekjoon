#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <iostream>
#include <map>

using namespace std;

set<string> s;
map<string, int> m; // 유저별 신고당한 횟수
multimap<string, string> m1; // 유저멸 신고한 유저
map<string, int> result; // 유저별 이메일 받은 횟수 

vector<string> split(string s)
{
    string tmp = "";
    stringstream ss(s);
    vector<string> result;
    
    while(getline(ss, tmp, ' '))
    {
        result.push_back(tmp);
    }
    
    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for(int i=0; i<report.size(); i++)
    {
        s.insert(report[i]);
    }
    
    for(auto it = s.begin(); it!=s.end(); it++)
    {
        vector<string> v = split(*it);
        
        string call = v[0];
        string called = v[1];
        
        m[v[1]]++;
        m1.insert(make_pair(v[1], v[0]));
    }
    
    for(auto it = m1.begin(); it!=m1.end(); it++)
    {
        string user = it->first;
        
        if(m[user] >= k)
        {
            result[it->second]++;
        }
    }
    
    for(int i=0; i<id_list.size(); i++)
    {
        string user = id_list[i];
        answer.push_back(result[user]);
    }
    
    return answer;
}