#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<int, long long> m;
map<int, long long> m2;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    for(int i=0; i<weights.size(); i++)
    {
        int a = weights[i] * 2;
        int b = weights[i] * 3;
        int c = weights[i] * 4;
        
        if(m[a] == 0)
            m[a] = 1;
        else
            m[a]++;
        
        if(m[b] == 0)
            m[b] = 1;
        else
            m[b]++;
        
        if(m[c] == 0)
            m[c] = 1;
        else
            m[c]++;
        
        if(m2[weights[i]] == 0)
            m2[weights[i]] = 1;
        else
            m2[weights[i]]++;
    }
    
    for(auto it = m.begin(); it != m.end(); it++)
    {
        long long count = it->second;
        
        
        answer += count * (count-1) / 2;
    }
    
    for(auto it = m2.begin(); it != m2.end(); it++)
    {
        long long count = it->second;
        
        if(count >= 2)
            answer -= (count - 1) * count;
    }
    
    return answer;
}