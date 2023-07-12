#include <string>
#include <vector>

using namespace std;

char arr[3][3];

bool check()
{
    bool result = true;
    
    int O = 0;
    int X = 0;
    
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(arr[i][j] == 'O')
                O++;
            else if(arr[i][j] == 'X')
                X++;
        }
    }
    if(!(O - X == 1 || O - X == 0))
        result = false;

    int winO = 0;
    int winX = 0;
    
    if(arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2])
    {
        if(arr[0][0] == 'O')
            winO++;
        else if(arr[0][0] == 'X')
            winX++;
    }
    
    if(arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2])
    {
        if(arr[1][0] == 'O')
            winO++;
        else if(arr[1][0] == 'X')
            winX++;
    }
    if(arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2])
    {
        if(arr[2][0] == 'O')
            winO++;
        else if(arr[2][0] == 'X')
            winX++;
    }
    if(arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0])
    {
        if(arr[0][0] == 'O')
            winO++;
        else if(arr[0][0] == 'X')
            winX++;
    }
    if(arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2])
    {
        if(arr[0][2] == 'O')
            winO++;
        else if(arr[0][2] == 'X')
            winX++;
    }
    if(arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1])
    {
        if(arr[1][1] == 'O')
            winO++;
        else if(arr[1][1] == 'X')
            winX++;
    }
    
    if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
    {
        if(arr[1][1] == 'O')
            winO++;
        else if(arr[1][1] == 'X')
            winX++;
    }
    if(arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2])
    {
        if(arr[1][1] == 'O')
            winO++;
        else if(arr[1][1] == 'X')
            winX++;        
    }
    
    if(winX>=1 && winO>=1)
        result = false;
    else if(winX == 1 || winO == 1)
    {
        if(winX == 1)
        {
            if(O != X)
            result = false;
        }
        else if(winO == 1)
        {
            if(!(O == X + 1))
                result = false;
        }
    }

    
    return result;
}

int solution(vector<string> board) {
    int answer = -1;
    
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].size(); j++)
        {
            arr[i][j] = board[i][j];
        }
    }
    
    if(check())
        answer = 1;
    else
        answer = 0;
    
    return answer;
}