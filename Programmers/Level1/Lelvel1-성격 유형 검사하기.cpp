#include <string>
#include <vector>

using namespace std;
int R, T;
int C, F;
int J, M;
int A, N;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    for(int i=0; i<survey.size(); i++)
    {
        string s = survey[i];
        int score = choices[i];
        
        if(s == "RT")
        {
            if(score == 1)
                R+=3;
            else if(score == 2)
                R+=2;
            else if(score == 3)
                R+=1;
            else if(score == 5)
                T+=1;
            else if(score == 6)
                T+=2;
            else if(score == 7)
                T+=3;
        }
        else if(s == "TR")
        {
            if(score == 1)
                T+=3;
            else if(score == 2)
                T+=2;
            else if(score == 3)
                T+=1;
            else if(score == 5)
                R+=1;
            else if(score == 6)
                R+=2;
            else if(score == 7)
                R+=3;
        }
        else if(s == "CF")
        {
            if(score == 1)
                C+=3;
            else if(score == 2)
                C+=2;
            else if(score == 3)
                C+=1;
            else if(score == 5)
                F+=1;
            else if(score == 6)
                F+=2;
            else if(score == 7)
                F+=3;
        }
        else if(s == "FC")
        {
            if(score == 1)
                F+=3;
            else if(score == 2)
                F+=2;
            else if(score == 3)
                F+=1;
            else if(score == 5)
                C+=1;
            else if(score == 6)
                C+=2;
            else if(score == 7)
                C+=3;
        }
        else if(s == "JM")
        {
            if(score == 1)
                J+=3;
            else if(score == 2)
                J+=2;
            else if(score == 3)
                J+=1;
            else if(score == 5)
                M+=1;
            else if(score == 6)
                M+=2;
            else if(score == 7)
                M+=3;
        }
        else if(s == "MJ")
        {
            if(score == 1)
                M+=3;
            else if(score == 2)
                M+=2;
            else if(score == 3)
                M+=1;
            else if(score == 5)
                J+=1;
            else if(score == 6)
                J+=2;
            else if(score == 7)
                J+=3;
        }
        else if(s == "AN")
        {
            if(score == 1)
                A+=3;
            else if(score == 2)
                A+=2;
            else if(score == 3)
                A+=1;
            else if(score == 5)
                N+=1;
            else if(score == 6)
                N+=2;
            else if(score == 7)
                N+=3;
        }
        else if(s == "NA")
        {
            if(score == 1)
                N+=3;
            else if(score == 2)
                N+=2;
            else if(score == 3)
                N+=1;
            else if(score == 5)
                A+=1;
            else if(score == 6)
                A+=2;
            else if(score == 7)
                A+=3;
        }
    }
    
    if(R >= T)
        answer+="R";
    else
        answer+="T";
    
    if(C >= F)
        answer+="C";
    else
        answer+="F";
    
    if(J >= M)
        answer+="J";
    else
        answer+="M";
    
    if(A >= N)
        answer+="A";
    else
        answer+="N";
    
    return answer;
}