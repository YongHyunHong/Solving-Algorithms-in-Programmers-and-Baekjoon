#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool compare(string a, string b)
{
    for(int i=0; i<a.size(); i++)
    {
        if(a[i] == b[i])
            continue;
        if(a[i] > b[i])
            return true;
        if(a[i] < b[i])
            return false;
    }
    return true;
}

int solution(string t, string p) {
    int answer = 0;
    
    int size = p.size();
    
    for(int i=0; i + size <= t.size(); i++)
    {
        if(compare(p, t.substr(i, size)))
           answer++;
        
    }
    
    return answer;
}
