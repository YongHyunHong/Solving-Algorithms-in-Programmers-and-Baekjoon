#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<char, int> m;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    for(int i=0; i<keymap.size(); i++)
    {
        for(int j=0; j<keymap[i].size(); j++)
        {
            char c = keymap[i][j];
            if(m.find(c) == m.end())
                m[c] = j + 1;
            else
                m[c] = min(m[c], j + 1);
        }
    }
    
    for(int i=0; i<targets.size(); i++)
    {
        int sum = 0;
        bool check = true;
        for(int j=0; j<targets[i].size(); j++)
        {
            char c = targets[i][j];
            if(m.find(c) == m.end())
                check = false;
            else
                sum+=m[c];
        }
        
        if(check)
            answer.push_back(sum);
        else
            answer.push_back(-1);
    }
    

    return answer;
}
