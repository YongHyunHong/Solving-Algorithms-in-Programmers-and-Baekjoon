#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
map<string, string> m;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for(int i=0; i<terms.size(); i++)
        m[terms[i].substr(0 ,1)] = terms[i].substr(2);
    
    for(int i=0; i<privacies.size(); i++)
    {
        string date = privacies[i].substr(0, 10);
        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day = date.substr(8, 2);
        
        // 2019.07,01 5달
            
        string person = privacies[i].substr(11, 1);
        string terms = m[person];
        
        string nextMonth = to_string((stoi(month) + stoi(terms)) % 12);
        string nextYear = to_string((stoi(month) + stoi(terms)) / 12 + stoi(year));
        string nextDay;
        
        if(nextMonth == "0")
        {
            nextMonth = "12";
            nextYear = to_string(stoi(nextYear) - 1);
        }
        
        if(day != "01")
            nextDay = to_string(stoi(day) - 1);
        else
        {
            nextDay = "28";
            nextMonth = to_string(stoi(nextMonth) - 1);
            
            if(nextMonth == "00")
            {
                nextMonth = "12";
                nextYear = to_string(stoi(nextYear) - 1);
            }
        }
        
        string todayYear = today.substr(0, 4);
        string todayMonth = today.substr(5, 2);
        string todayDay = today.substr(8, 2);
        
        if(stoi(todayYear) > stoi(nextYear))
            answer.push_back(i + 1);
        else if(stoi(nextYear) == stoi(todayYear))
        {
            if(stoi(todayMonth) > stoi(nextMonth))
                answer.push_back(i + 1);
            else if(stoi(nextMonth) == stoi(todayMonth))
            {
                if(stoi(todayDay) > stoi(nextDay))
                    answer.push_back(i + 1);
            }
        }
    }
    
    
    return answer;
}
