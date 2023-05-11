#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
vector<pair<int,int>> v;
//queue<pair<int,int>> q;

bool compare(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    for(int i=0; i<book_time.size(); i++)
    {
        string start = book_time[i][0];
        string end = book_time[i][1];
        
        int startTime = stoi(start.substr(0,2)) * 60 + stoi(start.substr(3 ,2));
        int endTime = stoi(end.substr(0,2)) * 60 + stoi(end.substr(3 ,2)) + 10;
        
        v.push_back(make_pair(startTime, endTime));
    }
    sort(v.begin(), v.end(), compare);
    
    for(int i=0; i<v.size(); i++)
    {
        if(q.empty())
            q.push(make_pair(v[i].second, v[i].first));
        else
        {
            if(q.top().first <= v[i].first)
            {
                q.pop();
                q.push(make_pair(v[i].second, v[i].first));
            }
            else
                q.push(make_pair(v[i].second, v[i].first));
        }
        
        int size = q.size();
        answer = max(size, answer);
    }
    
    return answer;
}
