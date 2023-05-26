#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int f = 0;
    int b = sequence.size() - 1;
    
    int start = 0;
    int end = 0;
    long long int sum = sequence[0];
    
    while(start <= end && end < sequence.size())
    {
           
        if(sum < k)
        {
            end ++;
            sum+=sequence[end];
        }
        else
        {   
            if(sum == k)
            {
                if((b - f) > (end - start))
                {
                    b = end;
                    f = start;
                }
            }
            sum-=sequence[start];
            start++;
        }
    }

    answer.push_back(f);
    answer.push_back(b);
    
    
    return answer;
}
