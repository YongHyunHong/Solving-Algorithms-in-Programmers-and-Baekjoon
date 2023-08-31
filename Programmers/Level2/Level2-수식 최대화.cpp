#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> nList;
vector<char> opList;

string opSeq = "*+-";
string op = "";
long long answer = 0;

bool check[3] = {false};

long long cal(long long a, long long b, char op)
{
    if(op == '+')
        return a + b;
    else if(op == '*')
        return a * b;
    else if(op == '-')
        return a - b;
}

void dfs(string s)
{
    if(s.size() == 3)
    {
        vector<long long> n1 = nList;
        vector<char> op1 = opList;
        
        while(true)
        {
            if(n1.size() == 1)
            {
                answer = max(abs(n1[0]), answer);
                break;
            }
            
            for(int i=0; i<s.size(); i++)
            {
                for(int j=0; j<op1.size(); j++)
                {
                    if(s[i] == op1[j])
                    {
                        long long num = cal(n1[j], n1[j+1], op1[j]);
                        n1[j] = num;
                        n1.erase(n1.begin() + j + 1);
                        op1.erase(op1.begin() + j);
                        j--;
                    }
                }
            }
        }
        
        return;
    }
    
    for(int i=0; i<3; i++)
    {
        if(!check[i])
        {
            check[i] = true;
            dfs(s + opSeq[i]);
            check[i] = false;
        }
    }
}

long long solution(string expression) {
    
    string num = "";
    for(int i=0; i<expression.size(); i++)
    {
        if(isdigit(expression[i]))
            num += expression[i];
        else
        {
            nList.push_back(stoll(num));
            num = "";
            opList.push_back(expression[i]);
        }
    }
    nList.push_back(stoll(num));
    
    dfs("");
    
    return answer;
}