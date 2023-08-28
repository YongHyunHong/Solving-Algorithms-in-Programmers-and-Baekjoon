#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

// cpp, java, python 중 선택
// backend frontend 중 선택
// junior senior 중 선택
// chicken pizza 중 선택

map<string, vector<int>> m;

vector<string> result(string s)
{
    stringstream ss(s);
    vector<string> v;
    string tmp = "";
    
    while(getline(ss, tmp, ' '))
    {
        v.push_back(tmp);
    }
    
    return v;
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(int i=0; i<info.size(); i++)
    {
        vector<string> v = result(info[i]);
        
        string l = v[0];
        string j = v[1];
        string c = v[2];
        string f = v[3];
        int score = stoi(v[4]);
        
        m[l+j+c+f].push_back(score);
        m[l+j+c+"-"].push_back(score);
        m[l+j+"-"+f].push_back(score);
        m[l+j+"-"+"-"].push_back(score);
        m[l+"-"+c+f].push_back(score);
        m[l+"-"+c+"-"].push_back(score);
        m[l+"--"+f].push_back(score);
        m[l+"---"].push_back(score);
        m["-"+j+c+f].push_back(score);
        m["-"+j+c+"-"].push_back(score);
        m["-"+j+"-"+f].push_back(score);
        m["-"+j+"--"].push_back(score);
        m["--"+c+f].push_back(score);
        m["--"+c+"-"].push_back(score);
        m["---"+f].push_back(score);
        m["----"].push_back(score);
    }
    
    for(auto it = m.begin(); it!=m.end(); it++)
    {
        sort(it->second.begin(), it->second.end());
    }

    for(int i=0; i<query.size(); i++)
    {
        vector<string> v = result(query[i]);
        
        string s = v[0] + v[2] + v[4] + v[6];
        int score = stoi(v[7]);
        
        vector<int> r = m[s];
        
        
        auto it = lower_bound(r.begin(), r.end(), score) - r.begin();
        answer.push_back(r.size() - it);
    }
    
    return answer;
}