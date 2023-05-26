#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    map<string, int> p;
    map<int, string> r;
    
    for(int i=0; i<players.size(); i++)
    {
        p[players[i]] = i;
        r[i] = players[i];
    }
    
    for(int i=0; i<callings.size(); i++)
    {
        int backRank = p[callings[i]];
        int frontRank = backRank - 1;
        
        string frontPlayer = r[frontRank];
        
        p[callings[i]] = frontRank;
        p[frontPlayer] = backRank;
        
        r[backRank] = frontPlayer;
        r[frontRank] = callings[i];
    }
    
    for(int i=0; i<r.size(); i++)
    {
        answer.push_back(r[i]);
    }
    
    return answer;
}
