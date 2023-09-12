#include <iostream>
#include <vector>
using namespace std;
#include <iostream>


int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int start = 1;
    
    for(int i=0; i<stations.size(); i++)
    {
        int s = stations[i];
        
        if(start >= s - w && start <= s + w)
            start = s + w + 1;
        else
        {
            int len = s - w - start;
            
            answer += len/(w * 2 + 1);
            if(len % (w * 2 + 1) != 0)
                answer++;
            
            start = s + w + 1;
        }
    }
    
    if(start <= n)
    {
        int len = n - start + 1;
            
        answer += len/(w * 2 + 1);
        if(len % (w * 2 + 1) != 0)
            answer++;
    }

    return answer;
}