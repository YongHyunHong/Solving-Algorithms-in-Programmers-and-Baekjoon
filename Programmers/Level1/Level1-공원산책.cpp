#include <string>
#include <vector>
#include <iostream>

using namespace std;
int x;
int y;
char arr[51][51];
int n,m;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    int n = park.size();
    int m = park[0].size();
    
    for(int i=0; i<park.size(); i++)
    {
        for(int j=0; j<park[i].size(); j++)
        {
            arr[i][j] = park[i][j];
            
            if(park[i][j] == 'S')
            {
                x = i;
                y = j;
            }
        }
    }
    
     for(int z = 0; z < routes.size(); z++)
     {
         char d = routes[z][0];
         int num = routes[z][2] - '0';
         
         bool check = true;
         
         if(d == 'E')
         {
             int count = 0;
             
             if(y + num >= m)
                 check = false;
             else
             {
                 while(true)
                 {
                     if(park[x][y + count] == 'X')
                     {
                         check = false;
                         break;
                     }

                    if(count == num)
                         break;

                     count ++;
                 }
             }
             
             if(check)
                 y+=num;
         }
         else if(d == 'W')
         {
             int count = 0;
             
             if(y - num < 0)
                 check = false;
             else
             {
                 while(true)
                 {
                     if(park[x][y - count] == 'X')
                     {
                         check = false;
                         break;
                     }

                    if(count == num)
                         break;

                     count ++;
                 }
             }
             
             if(check)
                 y-=num;
         }
         else if(d == 'S')
         {
             int count = 0;
             
             if(x + num >=n)
                 check = false;
             else
             {
                 while(true)
                 {
                     if(park[x + count][y] == 'X')
                     {
                         check = false;
                         break;
                     }

                     if(count == num)
                         break;

                     count ++;
                 }
             }
             
             if(check)
                 x+=num;
         }
         else if(d == 'N')
         {
             int count = 0;
             
             if(x - num < 0)
                 check = false;
             else
             {
                 while(true)
                 {
                     if(park[x - count][y] == 'X')
                     {
                         check = false;
                         break;
                     }
                     if(count == num)
                         break;

                     count ++;
                 }
             }
             
             if(check)
                 x-=num;
         }
     }
    
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}
