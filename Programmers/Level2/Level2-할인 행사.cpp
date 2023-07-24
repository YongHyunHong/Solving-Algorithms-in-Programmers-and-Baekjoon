#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<string, int> m;
map<string, int> m1;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i=0; i<want.size(); i++)
    {
        m[want[i]] = number[i];
    }

    for(int i=0; i<discount.size(); i++)
    {
        m1 = m;
        
        for(int j=i; j<i+10; j++)
        {
            if(j < discount.size() && m1[discount[j]] != 0)
                m1[discount[j]]--;
        }
        
        
        for(auto it = m1.begin(); it!=m1.end(); it++)
        {
            if(m1[it->first] <= 0)
                m1.erase(it);
        }
        
        
        if(m1.size() == 0)
        {
            answer++;
        }
    }
    
    
    return answer;
}