#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
#include <iostream>

set<string> s;
map<string, int> m;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    for(int i=0; i<gems.size(); i++)
        s.insert(gems[i]);
    
    int start = 0;
    int end = 0;
    int len = 100000;
    
    while(true)
    {
        if(end >=gems.size())
            break;
        
        for(int i = end; i < gems.size(); i++)
        {
            m[gems[i]]++;
            if(m.size() == s.size())
            {
                end = i;
                break;
            }
        }
        
        for(int i = start; i < gems.size(); i++)
        {
            if(m[gems[i]] == 1)
            {
                start = i;
                break;
            }
            
            m[gems[i]]--;
        }
        
        if(end - start < len)
        {
            answer.clear();
            len = end - start;
            answer.push_back(start + 1);
            answer.push_back(end + 1);
        }
        
        //cout<<start + 1<<" "<<end + 1<<"\n";
        
        end++;
    }
    
    return answer;
}