#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map<string, int> m;
map<string, int> cost;

vector<string> split(string s)
{
    stringstream ss(s);
    string tmp;
    vector<string> result;
    
    while(getline(ss, tmp, ' '))
        result.push_back(tmp);
    
    return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    for(int i=0; i<records.size(); i++)
    {
        vector<string> v = split(records[i]);
        
        string time = v[0];
        string car = v[1];
        int timeMin = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
        
        if(m.find(car) == m.end())
            m[car] = timeMin;
        else
        {
            int use = timeMin - m[car];
            m.erase(car);
            
            if(cost.find(car) == cost.end())
                cost[car] = use;
            else
                cost[car] += use;
        }
    }
    // 334분 이용
    // (334 - 180) / 10 + 5000
    
    for(auto it=m.begin(); it!=m.end(); it++)
    {
        string car = it->first;
        int use = 1439 - it->second;
        
        if(cost.find(car) == cost.end())
            cost[car] = use;
        else
            cost[car] += use;
    }
    
    
    for(auto it = cost.begin(); it != cost.end(); it++)
    {
        int c = it->second;
        int r;
        
        cout<<it->first<<" "<<c<<"\n";
        
        if(c - fees[0] >= 0)
        {
            if((c - fees[0]) % fees[2] == 0)
                r = (c - fees[0]) / fees[2] * fees[3] + fees[1];
            else
                r = ((c - fees[0]) / fees[2] + 1) * fees[3] + fees[1];
        }
        else
            r = fees[1];
        
        answer.push_back(r);
    }
    
    return answer;
}