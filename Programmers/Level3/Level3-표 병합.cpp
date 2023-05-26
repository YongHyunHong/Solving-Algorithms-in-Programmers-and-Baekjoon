#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
vector<string> split(string input, char delimiter) 
{
    vector<string> result;
    stringstream ss(input);
    string tmp;
 
    while (getline(ss, tmp, delimiter)) 
        result.push_back(tmp);
 
    return result;
}

string arr[2501];
int parent[2501];

void reset()
{
    for(int i=1; i<=2500; i++)
    {
        parent[i] = i;
        arr[i] = "EMPTY";
    }
}

int Find(int x)
{
    if(x == parent[x])
        return x;
    return parent[x] = Find(parent[x]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    
    if(x != y)
        parent[x] = y;
}

int get(int x, int y)
{
    return (x - 1) * 50 + y;
}

void print()
{
        for(int i=1; i<=4; i++)
    {
        for(int j=1; j<=4; j++)
        {
            int index = get(i, j);
            cout<<arr[index]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    reset();
    
    for(int i=0; i<commands.size(); i++)
    {
        vector<string> v = split(commands[i], ' ');
        
        if(v[0] == "UPDATE")
        {
            if(v.size() == 4)
            {
                int x = stoi(v[1]);
                int y = stoi(v[2]);
                string value = v[3];
                
                int f1 = get(x ,y);
                arr[f1] = value;
                
                for(int i=1; i<=2500; i++)
                {
                    if(i != f1 && Find(parent[i]) == Find(parent[f1]))
                        arr[i] = value;
                }

            }
            else
            {
                string value1 = v[1];
                string value2 = v[2];
                
                for(int i=1; i<=2500; i++)
                {
                   if(arr[i] == value1)
                       arr[i] = value2;
                }
            }
        }
        else if(v[0] == "MERGE")
        {
            int x1 = stoi(v[1]);
            int y1 = stoi(v[2]);
            int x2 = stoi(v[3]);
            int y2 = stoi(v[4]);
            
            int f1 = get(x1, y1);
            int f2 = get(x2, y2);
            
            if(f1 == f2)
                continue;
            
            if(arr[f1] == "EMPTY" && arr[f2] != "EMPTY")
            {
               for(int i=1; i<=2500; i++)
                {
                    if(i != f2 && Find(parent[i]) == Find(parent[f1]))
                    {
                        arr[i] = arr[Find(parent[f2])];
                        Union(i, f2);
                    }
                }
                arr[f1] = arr[Find(parent[f2])];
                Union(f1, f2);
            }
            else 
            {
                for(int i=1; i<=2500; i++)
                {
                    if(i != f1 && Find(parent[i]) == Find(parent[f2]))
                    {
                        arr[i] = arr[Find(parent[f1])];
                        Union(i, f1);
                    }
                }
                arr[f2] = arr[Find(parent[f1])];
                Union(f2, f1);
            }
        }
        else if(v[0] == "UNMERGE")
        {
            int x1 = stoi(v[1]);
            int y1 = stoi(v[2]);
            
            int f1 = get(x1, y1);
            string a = arr[f1];
            
            for(int i=1; i<=2500; i++)
            {
                if(i != f1 && Find(parent[i]) == Find(parent[f1]))
                {
                    arr[i] = "EMPTY";
                    parent[i] = i;
                }
            }
            
            parent[f1] = f1;
        }
        else if(v[0] == "PRINT")
        {
            int x = stoi(v[1]);
            int y = stoi(v[2]);
            
            answer.push_back(arr[get(x, y)]);
        }
    }
    
    for(int i=1; i<=4; i++)
    {
        cout<<arr[Find(parent[i])]<<" "<<Find(parent[i])<<"\n";
    }
    
    return answer;
}
