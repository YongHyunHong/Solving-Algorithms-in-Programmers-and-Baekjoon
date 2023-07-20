#include <string>
#include <vector>
#include <map>

using namespace std;

map<int, int> left;
map<int, int> right;

int answer = 0;

int solution(vector<int> topping) {
    
    for(int i=0; i<topping.size(); i++)
    {
        int num = topping[i];
        left[num]++;
    }
    
    for(int i=topping.size()-1; i>=0; i--)
    {
        int num = topping[i];
        if(left[num] > 0)
        {
            left[num]--;
            right[num]++;
        }
        
        if(left[num] == 0)
            left.erase(num);
        
        if(left.size() == right.size())
            answer++;
    }
    
    return answer;
}