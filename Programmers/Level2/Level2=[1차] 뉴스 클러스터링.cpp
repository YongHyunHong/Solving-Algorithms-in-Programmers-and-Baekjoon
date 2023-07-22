#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

map<string, int> add;
map<string, int> a1;
map<string, int> a2;
int result;

int solution(string str1, string str2) {
    int answer = 0;
    
    string s1 = "";
    string s2 = "";
    for(int i=0; i<str1.size(); i++)
    {
        if(isalpha(str1[i]))
            s1+=tolower(str1[i]);
        else
            s1+=str1[i];
    }
    for(int i=0; i<str2.size(); i++)
    {
        if(isalpha(str2[i]))
            s2+=tolower(str2[i]);
        else
            s2+=str2[i];
    }
    
    
    for(int i=0; i<s1.size()-1; i++)
    {
        string s = "";
        if(isalpha(s1[i]))
            s+=s1[i];
        if(isalpha(s1[i+1]))
            s+=s1[i+1];
        
        if(s.size()==2)
        {
            a1[s]++;
            add[s]++;
        }
    }
    
    for(int i=0; i<s2.size()-1; i++)
    {
        string s = "";
        if(isalpha(s2[i]))
            s+=s2[i];
        if(isalpha(s2[i+1]))
            s+=s2[i+1];
        
        if(s.size()==2)
        {
            a2[s]++;
            add[s]++;
        }
    }
    
    
    int sub = 0;
    
    for(auto it = a1.begin(); it!= a1.end(); it++)
    {
        string s = it->first;
        
        if(a2[s] != 0)
        {
            sub+=min(a1[s], a2[s]);
            add[s] -= min(a1[s], a2[s]);
        }
    }
    
    for(auto it = add.begin(); it!= add.end(); it++)
    {
        result+=it->second;
    }
    
    cout<<sub<<" "<<result<<"\n";
    
    if(result == 0)
        answer = 65536;
    else
        answer = sub * 65536/ result;
    
    return answer;
}