#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 987654321;
int count[4]; // 1은 다이아, 2는 철, 3은 돌
int totalCount;
int selects[11];
vector<string> v;

void cal()
{
    int c = 0;
    int index = 0;
    int result = 0;
    int total = 0;
    
    for(int i=0; i<v.size(); i++)
    {
        int tool = selects[index];
        string mine = v[i];
        
        c++;
        total++;
        
        if(total > 50)
            break;
        
        if(tool == 1)
        {
            result+=1;
        }
        else if(tool == 2)
        {
            if(mine == "diamond")
                result+=5;
            else
                result+=1;
        }
        else if(tool == 3)
        {
            if(mine == "diamond")
                result+=25;
            else if(mine == "iron")
                result+=5;
            else
                result+=1;
        }
        
        if(c == 5)
        {
            index++;
            c=0;
        }
        
    }
    
    answer = min(answer, result);
}

void dfs(int index)
{
    if(index == totalCount || index == 10)
    {
        cal();
        
        return;
    }
    
    for(int i=1; i<=3; i++)
    {
        if(count[i] != 0)
        {
            count[i]--;
            selects[index] = i;
            dfs(index+1);
            count[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    
    v = minerals;
    
    for(int i=0; i<picks.size(); i++)
    {
        count[i + 1] = picks[i];
        totalCount+=picks[i];
    }
    
    dfs(0);
    
    return answer;
}