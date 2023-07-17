#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
stack<int> s;

int solution(vector<int> order) {
    int answer = 0;
    
    int index = 1;
    
    for(int i=0; i<order.size(); i++)
    {
        int num = order[i];
        
        while(true)
        {
            if(index > num)
                break;
            s.push(index);
            index++;
        }
        
        if(s.top() == num)
        {
            s.pop();
            answer++;
        }
        else
            break;
    }
    
    
    
    return answer;
}