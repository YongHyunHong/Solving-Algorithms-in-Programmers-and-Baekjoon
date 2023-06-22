#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for(int i=1; i<=s.size(); i++)
    {
        string sub = "";
        vector<string> v;
        for(int j=0; j<s.size(); j++)
        {
            sub += s[j];
            
            if(sub.size() == i)
            {
                v.push_back(sub);
                sub = "";
            }
        }
        
        if(sub != "")
            v.push_back(sub);
        
        int counts = 0;
        string prev = "";
        string result = "";
        
        for(int j=0; j<v.size(); j++)
        {
            if(prev == v[j])
                counts++;
            else
            {
                if(counts != 0)
                {
                    result += prev;
                    result += to_string(counts + 1);
                }
                else
                    result += prev;
                
                counts = 0;
                prev = v[j];
            }
        }
        
        if(counts != 0)
        {
            result += prev;
            result += to_string(counts + 1);
        }
        else
            result += prev;
        
        int resultSize = result.size();
        answer = min(answer, resultSize);
    }
    
    return answer;
}