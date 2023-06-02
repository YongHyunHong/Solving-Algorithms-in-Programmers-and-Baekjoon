#include <string>
#include <vector>
#include <iostream>

using namespace std;
// 어피치가 우승해야함, 최종점수 같으면 어피치 우승
// 어피치는 다쐈고 라이언이 쏠차례
// 두명이 같은 개수를 맞추면 어피치가 점수 가져감
// 라이언이 어피치를 이기고 싶음

vector<int> answer;
int lion[11];
int maxNum = 0;

vector<int> app;
int len = 0;

bool complete = false;

void check()
{
    int l = 0;
    int a = 0;
    
    for(int i=0; i<=10; i++)
    {
        if(app[i] == 0 && lion[i] == 0)
            continue;
        
        if(app[i] >= lion[i])
            a += 10 - i;
        else
            l += 10 - i;
    }
    
    if(l - a > maxNum)
    {
        complete = true;
        
        maxNum = l - a;
        answer.clear();
        for(int i=0; i<=10; i++)
            answer.push_back(lion[i]);
    }
    else if(l - a == maxNum && !answer.empty())
    {
        bool checks = true;
        
        for(int i=10; i>=0; i--)
        {
            if(answer[i] == lion[i])
                continue;
            else if(answer[i] > lion[i])
                break;
            else
            {
                checks = false;
                break;
            }
        }
        
        if(!checks)
        {
            answer.clear();
            for(int i=0; i<=10; i++)
            answer.push_back(lion[i]);
        }
    }
}

void dfs(int count, int index)
{
    if(count == len)
    {
        check();
        return;
    }
    
    for(int i=index; i<=10; i++)
    {
        lion[i]++;
        dfs(count + 1, i);
        lion[i]--;
    }
}

vector<int> solution(int n, vector<int> info) {
    
    for(int i=0; i<info.size(); i++)
        app.push_back(info[i]);
    len = n;
    
    dfs(0, 0);
    
    if(!complete)
        answer.push_back(-1);
    
    return answer;
}