#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    // 1미터를 n개로 나누고
    // 벽에 페인트를 칠하는 롤러 길이 m
    
    int check = 0;
    
    for(int i=0; i<section.size(); i++)
    {
        if(section[i] > check)
        {
            answer++;
            check = section[i] + m - 1;
        }
    }
    
    return answer;
}
