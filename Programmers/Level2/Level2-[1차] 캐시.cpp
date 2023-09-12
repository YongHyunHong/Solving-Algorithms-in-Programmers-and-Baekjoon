#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>

using namespace std;

queue<string> q;
vector<string> v;
set<string> s;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    for(int i=0; i<cities.size(); i++)
    {
        string city = "";
        for(int j=0; j<cities[i].size(); j++)
        {
            if(isupper(cities[i][j]))
                city += tolower(cities[i][j]);
            else
                city += cities[i][j];
        }
        
        if(s.size() < cacheSize)
        {
            if(s.find(city) == s.end())
            {
                s.insert(city);
                v.push_back(city);
                answer += 5;
            }
            else
            {
                answer += 1;
                v.erase(find(v.begin(), v.end(), city));
                v.push_back(city);
            }
        }
        else
        {
            if(cacheSize == 0)
                answer += 5;
            else
            {
                if(s.find(city) == s.end())
                {
                    s.erase(v[0]);
                    v.erase(v.begin());

                    s.insert(city);
                    v.push_back(city);
                    answer += 5;
                }
                else
                {
                    answer += 1;
                    v.erase(find(v.begin(), v.end(), city));
                    v.push_back(city);
                }
            }
        }
    }
    
    return answer;
}