#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<pair<int,int>> v;

bool compare(pair<int,int> a, pair<int,int> b)
{
    if(a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    for(int i=0; i<targets.size(); i++)
    {
        int f = targets[i][0];
        int b = targets[i][1];
        v.push_back(make_pair(f , b));
    }

    sort(v.begin(), v.end(), compare);
    
    int end = -1;
    
    for(int i=0; i<v.size(); i++)
    {
        if(end > v[i].first)
            continue;
        else
        {
            answer++;
            end = v[i].second;
        }
    }
    
    
    return answer;
}
