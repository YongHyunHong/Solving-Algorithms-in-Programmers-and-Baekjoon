#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> split(string s)
{
    stringstream ss(s);
    string tmp = "";
    vector<string> result;
    
    while(getline(ss, tmp, ' '))
    {
        result.push_back(tmp);
    }
    
    return result;
}

map<string, string> m;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(int i=0; i<record.size(); i++)
    {
        vector<string> v = split(record[i]);
        
        if(v.size() == 3)
        {
            string message = v[0];
            string id = v[1];
            string name = v[2];

            m[id] = name;
        }
    }
    
    for(int i=0; i<record.size(); i++)
    {
        vector<string> v = split(record[i]);
        
        string message = v[0];
        string id = v[1];
        
        if(message == "Enter")
            answer.push_back(m[id] + "님이 들어왔습니다.");
        else if(message == "Leave")
            answer.push_back(m[id] + "님이 나갔습니다.");
    }
    
    
    return answer;
}