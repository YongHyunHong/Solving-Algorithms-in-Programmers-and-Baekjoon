#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// n회 t분 간격으로 도착, 최대 m명탑승가능
// 09:00 부터

string convert(int time)
{
    string busTime = "";
    
    int x = time/60;
    int y = time%60;
        
    if(x < 10)
        busTime += "0" + to_string(x) + ":";
    else
        busTime += to_string(x) + ":";
        
    if(y < 10)
        busTime += "0" + to_string(y);
    else
        busTime += to_string(y);
    
    return busTime;
}

string minusMin(string time)
{
    string ss = "";
    ss += time[0];
    ss += time[1];
    
    string mins = "";
    mins += time[3];
    mins += time[4];
    
    int x = stoi(ss);
    int y = stoi(mins);
     
    
    if(y > 0)
        return convert(60 * x + y - 1);
    else
        return convert(60 * (x - 1) + 59);
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    sort(timetable.begin(), timetable.end());
    
    int bus = 1;
    int people = 0;
    int i = 0;
    string lastTime = "";
    int lastPeople = 0;
    int lastBus = 0;
    
    for(int i=0; i<timetable.size(); i++)
        cout<<timetable[i]<<"\n";
    
    
    while(true)
    {
        if(i == timetable.size() || bus == n + 1)
            break;
        
        string peopleTime = timetable[i];
        
        string busTime = convert((bus - 1) * t + 540);    
        
        if(bus <= n)
        {
            if(busTime >= peopleTime)
            {
                if(people < m)
                {
                    people++;
                    i++;

                    lastTime = peopleTime;
                    lastPeople = people;
                    lastBus = bus;
                }
                else
                {
                    people = 0;
                    bus++;
                }
            }
            else
            {
                bus++;
                people = 0;
            }
        }
    }

    
    if(lastBus == n)
    {
        if(lastPeople == m)
            answer = minusMin(lastTime);
        else
            answer = convert((n - 1) * t + 540);
    }
    else
        answer = convert((n - 1) * t + 540);
    
    return answer;
}