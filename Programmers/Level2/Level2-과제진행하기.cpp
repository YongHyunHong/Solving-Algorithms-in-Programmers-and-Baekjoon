#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

vector<tuple<string, int, int>> v;

bool compare(tuple<string, int, int> a, tuple<string, int, int> b)
{
    return get<1>(a) < get<1>(b);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    for(int i=0; i<plans.size(); i++)
    {
        string name = plans[i][0];
        string startString = plans[i][1];
        int start = stoi(startString.substr(0 ,2)) * 60 + stoi(startString.substr(3));
        int time = stoi(plans[i][2]);
        
        v.push_back(make_tuple(name, start, time));
    }
    sort(v.begin(), v.end(), compare);
    
    
    stack<int> stack;
    int index = 0;
    
    while(true)
    {
        
        if(index == v.size())
            break;
        
        if(get<1>(v[index]) + get<2>(v[index]) > get<1>(v[index + 1]))
        {   
            get<2>(v[index]) = (get<1>(v[index]) + get<2>(v[index])) - get<1>(v[index + 1]);
            stack.push(index);
            index++;
        }
        else if(get<1>(v[index]) + get<2>(v[index]) == get<1>(v[index + 1]))
        {
            answer.push_back(get<0>(v[index]));
            index++;
        }
        else if(get<1>(v[index]) + get<2>(v[index]) < get<1>(v[index + 1]))
        {
            int remain = get<1>(v[index + 1]) - (get<1>(v[index]) + get<2>(v[index]));
            answer.push_back(get<0>(v[index]));
            index++;
                
            while(true)
            {
                if(stack.empty() || remain == 0)
                    break;
                    
                int stackIndex = stack.top();
                if(get<2>(v[stackIndex]) >= remain)
                {
                    get<2>(v[stackIndex]) -= remain;
                    remain = 0;
                }
                else
                {
                    remain -= get<2>(v[stackIndex]);
                    get<2>(v[stackIndex]) = 0;
                }
                    
                    
                if(get<2>(v[stackIndex]) == 0)
                {
                    answer.push_back(get<0>(v[stackIndex]));
                    stack.pop();
                }

            }        
        }
    }
        
    
    while(!stack.empty())
    {
        int index = stack.top();
        answer.push_back(get<0>(v[index]));
        stack.pop();
    }
    
    
    
    return answer;
}
