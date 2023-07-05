#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

int node[10001];
vector<int> v[10001];
map<string, int> number;
map<int, string> numberInt;
map<string, int> earnMoney; // 결과값

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    for(int i=0; i<enroll.size(); i++)
    {
        number[enroll[i]] = i;
        numberInt[i] = enroll[i];
    }

    
    for(int i=0; i<referral.size(); i++)
    {
        string curr = enroll[i];
        string high = referral[i];
        
        if(high != "-")
            v[number[curr]].push_back(number[high]);
    }
    
    for(int i=0; i<seller.size(); i++)
    {
        string people = seller[i];
        int peopleNum = number[people];
        int money = amount[i] * 100;
        
        
        if(earnMoney[people] == 0)
            earnMoney[people] = money - (int)(money * 0.1);
        else
            earnMoney[people] += money - (int)(money * 0.1);
        
        money = money * 0.1;
        
        
        while(true)
        {
            if(v[peopleNum].empty() || money == 0)
                break;
            
            peopleNum = v[peopleNum][0];
            people = numberInt[peopleNum];
            
            if(earnMoney[people] == 0)
                earnMoney[people] = money - (int)(money * 0.1);
            else
                earnMoney[people] += money - (int)(money * 0.1);
            
            money = (int)(money * 0.1);
            
        }
    }

    for(int i=0; i<enroll.size(); i++)
    {
        string name = enroll[i];
        answer.push_back(earnMoney[name]);
    }
    
    return answer;
}