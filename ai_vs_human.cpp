#include<bits/stdc++.h>
using namespace std;

int pick = 0;

int prune(bool chance, int score, int sticks, int n)
{
    if((chance && score == 1) || (!chance && score == -1))
    {
        pick = sticks;
        return score;
    }
    else if(n == sticks)
    {
        pick = 1;
        return score;
    }
    else
        return 0;
}

int minimax(int n, bool chance)
{
    if(n == 0)
    {
        if(chance)
            return 1;
        return -1;
    }

    int score1 = minimax(n-1, !chance);
    int x = prune(chance, score1, 1, n);
    if(x != 0)
        return x;
    int score2 = minimax(n-2, !chance);
    x = prune(chance, score2, 2, n);
    if(x != 0)
        return x;
    int score3 = minimax(n-3, !chance);
    if(chance)
    {
        if(score3 == 1)
        {
            pick = 3;
            return 1;
        }
        else{
            pick = 1;
            return score3;
        }
    }
    else{
        if(score3 == 1)
        {
            pick = 1;
            return score3;
        }
        else{
            pick = 3;
            return score3;
        }
    }
}

bool toss()
{
    double x =((double) rand()/ (RAND_MAX));
    if(x >= 0.5)
        return true;
    return false;
}

int main()
{
    int n, person;
    bool t = true;
    char choice;
    while(t)
    {
        cout<<"enter no. of sticks = ";
        cin>>n;

        cout<<"Now its time for toss\n\n";
        bool chance = toss();
        if(chance)
            cout<<"AI won the toss\n\n";
        else
            cout<<"You won the toss\n\n";

        cout<<"total sticks are "<<n<<" on the table\n\n";
        cout<<"\n--------game starts now----------\n\n\n";

        if(!chance)
        {
            cout<<"pick up sticks in range of 1 to 3: ";
            cin>>person;
            while(person < 1 || person > 3)
            {
                cout<<"please pick up sticks striclty between 1 to 3: ";
                cin>>person;
            }
            cout<<"\nyou picked up "<<person<<" sticks\n";
            n = n - person;
            cout<<"remaining sticks are "<<n<<"\n\n";
            chance = !chance;
        }

        while(n)
        {
            int x = minimax(n, chance);
            cout<<"\nAI picked up "<<pick<<" sticks\n";
            n = n - pick;
            cout<<"remaining sticks are "<<n<<"\n\n";

            if(n == 0)
            {
                cout<<"\n\n-------------AI lost, You won....CONGRATULATIONS----------------\n\n\n\n";
                break;
            }

            cout<<"pick up sticks in range of 1 to 3: ";
            cin>>person;
            while(person < 1 || person > 3)
            {
                cout<<"please pick up sticks striclty between 1 to 3: ";
                cin>>person;
            }
            cout<<"\nyou picked up "<<person<<" sticks\n";

            while(person > n)
            {
                cout<<"you tried to pick more than remaining sticks\n";
                cout<<"enter less than remaining sticks on table: ";
                cin>>person;
            }
            cout<<"\nremaining sticks are "<<n<<"\n\n";

            n = n - person;
            if(n == 0)
            {
                cout<<"\n\n-------------You lost, AI won....BETTER LUCK NEXT TIME----------------\n\n\n\n";
                break;
            }
        }

        cout<<"Do you want to play again? Type 'y' for yes and 'n' for no: ";
        cin>>choice;
        if(choice == 'n')
            t = false;
    }

    return 0;
}
