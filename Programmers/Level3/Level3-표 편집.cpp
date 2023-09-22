#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h>

using namespace std;

struct Node{
    int n;
    Node* prev;
    Node* next;
    
    Node(int n, Node* prev, Node* next) : n(n), prev(prev), next(next){}
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    stack<Node*> remove;
    Node* curr;
    
    Node* it = new Node(0, NULL, NULL);
    
    for(int i=0; i<n; i++)
        answer += "O";
    
    for(int i=1; i<n; i++)
    {
        it->next = new Node(i, it, NULL);
        it = it->next;
        
        if(i == k)
            curr = it;
    }
    
    for(int i=0; i<cmd.size(); i++)
    {
        if(cmd[i][0] == 'U')
        {
            int move = stoi(cmd[i].substr(2));
            
            while(true)
            {
                if(move == 0)
                    break;
                
                curr = curr->prev;
                move--;
            }
        }
        else if(cmd[i][0] == 'D')
        {
            int move = stoi(cmd[i].substr(2));
            
            while(true)
            {
                if(move == 0)
                    break;
                
                curr = curr->next;
                move--;
            }
        }
        else if(cmd[i][0] == 'C')
        {
            remove.push(curr);
            
            if(curr->prev != NULL)
                curr->prev->next = curr->next;
            else
                curr->next->prev = NULL;
                
            if(curr->next != NULL)
                curr->next->prev = curr->prev;
            else
                curr->prev->next = NULL;
            
            if(curr->next == NULL)
                curr = curr->prev;
            else
                curr = curr->next;
        }
        else if(cmd[i][0] == 'Z')
        {
            Node* node = remove.top();
            remove.pop();
            
            if(node->prev == NULL)
                node->next->prev = node;
            else if(node->next == NULL)
                node->prev->next = node;
            else
            {
                node->prev->next = node;
                node->next->prev = node;
            }
        }
    }
    
    while(!remove.empty())
    {
        answer[remove.top()->n] = 'X';
        remove.pop();
    }
    
    return answer;
}