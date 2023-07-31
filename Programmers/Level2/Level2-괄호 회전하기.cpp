#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
int answer = 0;

bool counts(string s)
{
    bool check = true;
    stack<char> st;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '[' || s[i] == '(' || s[i] == '{')
            st.push(s[i]);
        else if(s[i] == ']')
        {
            if(!st.empty() && st.top() == '[')
                st.pop();
            else
                check = false;
        }
        else if(s[i] == ')')
        {
            if(!st.empty() && st.top() == '(')
                st.pop();
            else
                check = false;            
        }
        else if(s[i] == '}')
        {
            if(!st.empty() && st.top() == '{')
                st.pop();
            else
                check = false;            
        }
    }
    
    if(!st.empty())
        check = false;
    
    return check;
}

int solution(string s) {
    
    for(int i=0; i<s.size(); i++)
    {
        string k = "";
        k += s.substr(i, s.size()) + s.substr(0, i);
        
        if(counts(k))
            answer++;
    }
    
    return answer;
}