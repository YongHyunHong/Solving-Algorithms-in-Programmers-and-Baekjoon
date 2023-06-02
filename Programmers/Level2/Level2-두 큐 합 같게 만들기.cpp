#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long int sum = 0;
long long int result = 0;
queue<int> q1, q2;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    for(int i=0; i<queue1.size(); i++)
    {
        result += queue1[i];
        sum += queue1[i];
        q1.push(queue1[i]);
    }
    for(int i=0; i<queue2.size(); i++)
    {
        sum += queue2[i];
        q2.push(queue2[i]);
    }
    
    bool check = false;
    int count = 0;
    
    while(true)
    {
        if(result * 2 == sum)
        {
            check = true;
            break;
        }
        
        if(q1.empty() || q2.empty())
            break;
        
        if(count >= 600000)
            break;
        
        if(result * 2 < sum)
        {
            result += q2.front();
            q1.push(q2.front());
            q2.pop();

            answer++;
        }
        else if(result * 2 > sum)
        {
            result -= q1.front();
            q2.push(q1.front());
            q1.pop();

            answer++;
        }

        count++;
    }
    
    if(!check)
        answer = -1;
    
    
    return answer;
}