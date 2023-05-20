#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, int>> v;
vector<int> result;

bool compare(pair<int ,int> a, pair<int, int> b)
{
    if(a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

bool compare2(int a, int b)
{
    return a > b;
}

int solution(vector<vector<int>> scores) {
    int answer = 0;
    bool check = true;
    
    int personA = scores[0][0];
    int personB = scores[0][1];
    
    for(int i=0; i<scores.size(); i++)
        v.push_back(make_pair(scores[i][0], scores[i][1]));
    
    sort(v.begin(), v.end(), compare);   
    
    for(int i=0; i < v.size(); i++)
    {
        bool checking = true;
        for(int j=0; j < i; j++)
        {
            if(v[i].first < v[j].first && v[i].second < v[j].second)
            {
                if(v[i].first == personA && v[i].second == personB)
                    check = false;
                
                checking = false;
                break;
            }
        }
            
        if(checking)
            result.push_back(v[i].first + v[i].second);
    }
    
    sort(result.begin(), result.end(), compare2);
    
    if(!check)
        answer = -1;
    else
    {
        for(int i=0; i<result.size(); i++)
        {
            if(result[i] == personA + personB)
            {
                answer = i + 1;
                break;
            }
        }
    }

    
    return answer;
}
