#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int sum = 0;
    
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(int i=0; i<enemy.size(); i++)
    {
        q.push(enemy[i]);
        
        if(q.size() > k)
        {
            sum += q.top();
            q.pop();
        }
        
        if(sum > n)
        {
            answer = i;
            break;
        }
    }
    
    if(answer == 0)
        answer = enemy.size();
    
    return answer;
}