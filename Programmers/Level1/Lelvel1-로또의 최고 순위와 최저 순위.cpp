#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int zero = 0;
    int minCount = 0;
    int maxCount = 0;
    
    for(int i=0; i<lottos.size(); i++)
    {
        if(lottos[i] != 0)
        {
            if(find(win_nums.begin(), win_nums.end(), lottos[i]) != win_nums.end())
                minCount++;
        }
        else
            zero++;
    }
    
    maxCount = zero + minCount;
    
    if(maxCount >= 2 && maxCount <=6)
        answer.push_back(7-maxCount);
    else
        answer.push_back(6);
    
    if(minCount >= 2 && minCount <=6)
        answer.push_back(7-minCount);
    else
        answer.push_back(6);
    
    return answer;
}