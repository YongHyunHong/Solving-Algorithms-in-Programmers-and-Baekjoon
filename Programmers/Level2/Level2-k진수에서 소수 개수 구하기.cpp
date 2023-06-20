#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

int answer = 0;

vector<string> split(string s)
{
    string tmp="";
    stringstream ss(s);
    vector<string> result;
    
    while(getline(ss, tmp, '0'))
    {
        result.push_back(tmp);
    }
    
    return result;
}

string reverse(string s)
{
    string result = "";
    for(int i=s.size()-1; i>=0; i--)
        result +=s[i];
    
    return result;
}

bool isPrime(long long int x)
{
    if(x == 0)
        return false;
    if(x == 1)
        return false;
    if(x == 2)
        return true;
    
    for(long long int i=2; i*i<=x; i++)
    {
        if(x%i == 0)
            return false;
    }
    
    return true;
}

long long int change(string s)
{
    long long int result = 0;
    
    for(int i=0; i<s.size(); i++)
        result += (s[i] - '0') * pow(10, s.size()-i-1);
    
    return result;
}

void count(string s)
{
    vector<string> v = split(s);
    
    for(int i=0; i<v.size(); i++)
    {
        if(isPrime(change(v[i])))
            answer++;
    }
}


int solution(int n, int k) {
    
    string num = "";
    
    while(true)
    {
        if(n/k == 0)
            break;
        
        string add = to_string(n%k);
        n = n/k;
        num += add;
    }
    
    if(n!=0)
        num += to_string(n);
    
    count(reverse(num));
    
    return answer;
}