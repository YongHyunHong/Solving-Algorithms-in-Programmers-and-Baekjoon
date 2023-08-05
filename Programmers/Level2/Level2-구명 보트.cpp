#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    
    int low = 0;
    int high = people.size() - 1;
    
    
    while(low <= high)
    {
        int sum = people[low] + people[high];
        
        if(sum <= limit)
        {
            answer++;
            low++;
            high--;
        }
        else
        {
            answer++;
            high--;
        }
    }
    
    
    return answer;
}