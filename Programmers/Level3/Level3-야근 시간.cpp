#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#include <queue>

long long answer = 0;
long long solution(int n, vector<int> works) {
    
    priority_queue<int> q;
    
    for(int i=0; i<works.size(); i++)
    {
        q.push(works[i]);
    }
    
    while(true)
    {
        if(q.empty())
            break;
        if(n==0)
            break;
        
        int front = q.top();
        q.pop();
        
        front--;
        n--;
        if(front > 0)
            q.push(front);
    }
    
    while(!q.empty())
    {
        int front = q.top();
        q.pop();
        answer += front*front;
    }
    
    return answer;
}