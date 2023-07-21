#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) { // k가 한번에 건너뛸수 있는 거
    
    int low = 1;
    int high = 0;
    
    for(int i=0; i<stones.size(); i++)
    {
        high = max(high, stones[i]);
    }
    
    while(low <= high)
    {
        int mid = (low + high) / 2;
        
        
        int c = 0;
        bool check = false;
        for(int i=0; i<stones.size(); i++)
        {
            if(stones[i] - mid  <= 0)
                c++;
            else
                c = 0;
            
            if(c >= k)
                check = true;
        }
        
        if(check)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    
    return low;
}