#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

vector<tuple<string, string, string, string>> v;
map<string, string> m;

bool compare(tuple<string, string, string, string> a, tuple<string, string, string, string> b)
{
    if(get<0>(a) != get<0>(b))
        return get<0>(a) < get<0>(b);
    else
    {
        if(get<1>(a) != get<1>(b))
            return stoi(get<1>(a)) < stoi(get<1>(b));
    }
}

void split(string s)
{
    string head = "";
    string number = "";
    string tail = "";
    
    for(int i=0; i<s.size(); i++)
    {
        if(isdigit(s[i]))
        {
            if(number == "")
                number += s[i];
            else if(tail != "")
                tail += s[i];
            else if(tail == "" && number.size() < 5)
                number += s[i];
        }
        else
        {
            if(number == "")
                head += tolower(s[i]);
            else
                tail += tolower(s[i]);
        }
    }

    v.push_back(make_tuple(head, number, tail, s));
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for(int i=0; i<files.size(); i++)
    {
        split(files[i]);
    }
    
    stable_sort(v.begin(), v.end(), compare);
    
    for(int i=0; i<v.size(); i++)
    {         
        answer.push_back(get<3>(v[i]));
    }
    
    
    return answer;
}