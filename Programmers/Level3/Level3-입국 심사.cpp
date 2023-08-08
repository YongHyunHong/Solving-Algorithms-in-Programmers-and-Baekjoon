#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    
    sort(times.begin(), times.end());
    long long answer = 0;
    
    
    long long low = 1;
    long long high = (long long)n  * times[times.size() - 1];
    
    while(low <= high)
    {
        long long mid = (low + high) / 2;
        
        long long tmp = 0;
        for(int i=0; i<times.size(); i++)
        {
            tmp += mid / times[i];
        }
        
        
        if(tmp < n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    answer = high + 1;
    
    return answer;
}