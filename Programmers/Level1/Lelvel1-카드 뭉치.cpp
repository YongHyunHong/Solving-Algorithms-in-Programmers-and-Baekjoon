#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    bool check = true;
    int index = 0;
    
    while(true)
    {
        if(index == goal.size())
            break;
        
        if(goal[index] == cards1[0])
        {
            index++;
            cards1.erase(cards1.begin());
            continue;
        }
        
        if(goal[index] == cards2[0])
        {
            index++;
            cards2.erase(cards2.begin());
            continue;
        }
        
        check = false;
        break;
    }

    
    if(check)
        answer = "Yes";
    else
        answer = "No";
    
    return answer;
}
