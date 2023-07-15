#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<int, int> m;
vector<int> v;

bool compare(int a, int b)
{
    return a > b;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    for(int i=0; i<tangerine.size(); i++)
    {
        int w = tangerine[i];
        
        if(m[w] == 0)
            m[w] = 1;
        else
            m[w]++;
    }
    
    for(auto it = m.begin(); it!= m.end(); it++)
    {
        v.push_back(it->second);
    }
    sort(v.begin(), v.end(), compare);
    
    
    int total = k;
    
    for(int i=0; i<v.size(); i++)
    {
        //cout<<v[i]<<"\n";
        if(total == 0)
            break;
        if(v[i] <= total)
        {
            total -= v[i];
            answer++;
        }
        else
        {
            if(total!=0)
            {   
                answer++;
                break;
            }
        }
    }
    
    return answer;
}