#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    //1,2 단계
    string id1="";
    for(int i=0; i<new_id.size(); i++)
    {
        if(isalpha(new_id[i]))
            id1+=tolower(new_id[i]);
        else
        {
            if(isdigit(new_id[i]) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
                id1+=new_id[i];
        }
    }

    //3 단계
    string id3="";
    int index = 0;
    
    while(true)
    {
        if(index >= id1.size())
            break;
        if(id1[index] != '.')
        {
            id3+=id1[index];
            index++;
        }
        else
        {
            id3+='.';
            while(true)
            {
                if(index == id1.size() || id1[index]!= '.')
                     break;
                index++;
            }
            
            if(index!=id1.size())
                id3+=id1[index];
            index++;
        }
    }
    
    
    string id4 = "";
    for(int i=0; i<id3.size(); i++)
    {
        if(i==0 || i == id3.size() - 1)
        {
            if(id3[i] == '.')
                continue;
            else
                id4 += id3[i];
        }
        else
            id4+=id3[i];
    }
    
    
    // 5단계
    if(id4.size() == 0)
        id4 +='a';
    
    //6단계
    string id6 = "";
    if(id4.size() >= 16)
        id6 = id4.substr(0, 15);
    else
        id6 = id4;
    
    if(id6[id6.size()-1] == '.')
        id6 = id6.substr(0, id6.size()-1);
    
    
    string id7 = "";
    
    if(id6.size() <= 2)
    {
        id7 = id6;
        if(id6.size() == 1)
        {
            id7+=id6[0];
            id7+=id6[0];
        }
        else if(id6.size() == 2)
        {
            id7 += id6[1];
        }
    }
    else
        id7 = id6;
    
    answer = id7;
    
    return answer;
}