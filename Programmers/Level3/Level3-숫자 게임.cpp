#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int answer = 0;

int solution(vector<int> A, vector<int> B) {
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int index = 0;
    
    for(int i=0; i<B.size(); i++)
    {
        if(A[index] < B[i])
        {
            answer++;
            index++;
        }
    }
    
    return answer;
}