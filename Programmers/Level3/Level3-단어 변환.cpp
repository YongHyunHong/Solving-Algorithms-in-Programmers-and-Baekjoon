#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
string result;
int answer = 0;
vector<string> word;
bool check[51] = {false};

void dfs(string begin)
{
    queue<pair<string, int>> q;
    q.push(make_pair(begin, 0));
    
    while(!q.empty())
    {
        string curr = q.front().first;
        int c = q.front().second;
        q.pop();
        
        if(curr == result)
        {
            answer = c;
            return;
        }
        
        for(int i=0; i<word.size(); i++)
        {
            if(check[i])
                continue;
            int count = 0;
            for(int j=0; j<word[i].size(); j++)
            {
                if(curr[j] != word[i][j])
                    count++;
            }
            
            if(count != 1)
                continue;
            q.push(make_pair(word[i], c + 1));
            check[i] = true;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    result = target;
    word = words;
        
    dfs(begin);
    
    return answer;
}