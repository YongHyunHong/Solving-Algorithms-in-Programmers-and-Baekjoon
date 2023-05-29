#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;

string cmp = "";

string change(long long int num)
{
    string result = "";
    while(true)
    {
        if(num == 1 || num == 0)
        {
            result += to_string(num);
            break;
        }
        
        result += to_string(num%2);
        num/=2;
    }
    
    
    int n = 1;
        
    while(true)
    {
        if(pow(2, n) - 1 >= result.size())
            break;
        n++;
    }
        
    while(true)
    {
        if(result.size() == pow(2, n) -1)
            break;
        result += "0";
    }
    
    string result2 = "";
    
    for(int i=result.size()-1; i>=0; i--)
        result2 +=result[i];
    
    return result2;
}

void dfs(string num, int len, int start)
{
    if(len == 1)
    {
        cmp += num[start];
        //cout<<"길이 1일때 추가"<<num[start]<<"\n";
        return;
    }
    
    if(num[start + len/2] == '1')
    {
        dfs(num, len/2, start);
        cmp += "1";
        dfs(num, len/2, start + len/2 + 1);
    }
    else
    {
        for(int i=0; i<len; i++)
            cmp += "0";
        return;
    }
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i=0; i<numbers.size(); i++)
    {
        cmp = "";
        string num = change(numbers[i]);
            
        dfs(num, num.size(), 0);
        //cout<<num<<" "<<cmp<<"\n";
        
        if(cmp == num)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    return answer;
}