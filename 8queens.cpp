#include <iostream>
#include <queue>
using namespace std;

struct chess
{
    int queens;
    int board[8][8];
};

queue<chess> q1;


bool checker(chess &newBoard, int j)
{
    int k,l,i = newBoard.queens;

    //row checker
    for(k = 0; k < 8; k++)
    {
        if(newBoard.board[i][k] == 1)
            return false;
    }

    //column checker
    for(k = 0; k < 8; k++)
    {
        if(newBoard.board[k][j] == 1)
            return false;
    }

    //forward and above diagonal
    k = 0;
    l = 0;
    while(i-k >= 0 && j+l < 8)
    {
        if(newBoard.board[i-k][j+l] == 1)
            return false;
        k++;
        l++;
    }

    //forward and below diagonal
    k = 0;
    l = 0;
    while(i+k < 8 && j+l < 8)
    {
        if(newBoard.board[i+k][j+l] == 1)
            return false;
        k++;
        l++;
    }

    //backward and above diagonal
    k = 0;
    l = 0;
    while(i-k >= 0 && j-l >= 0)
    {
        if(newBoard.board[i-k][j-l] == 1)
            return false;
        k++;
        l++;
    }

    //backward and below diagonal
    k = 0;
    l = 0;
    while(i+k < 8 && j-l >= 0)
    {
        if(newBoard.board[i+k][j-l] == 1)
            return false;
        k++;
        l++;
    }
    return true;
}

int main()
{
    chess C;
    C.queens=0;
    chess c,c1;
    int i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            c.board[i][j] = 0;
    }

    c.queens = 0;
    q1.push(c);

    while(!q1.empty())
    {
        chess c1 = q1.front();
        q1.pop();
        int q = c1.queens;
        //8 times
        for(j=0;j<8;j++)
        {
            //if(c1.board[q][j] == -1)
              //  continue;
            if(checker(c1,j))
            {
                //c1.board[q][j] = -1;
                chess c2 = c1;
                c2.board[q][j] = 1;
                c2.queens++;
                if(c2.queens == 8)
                {
                    C = c2;
                    break;
                }
                q1.push(c2);
            }
        }
        if(C.queens == 8)
        {
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                    cout<<C.board[i][j]<<" ";
                cout<<endl;
            }
            C.queens = 0;
            cout<<endl<<endl<<endl;
        }
    }
}
