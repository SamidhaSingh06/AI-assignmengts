#include<bits/stdc++.h>
using namespace std;

int pick = 0;

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
            cout<<"Player1 won the toss\n\n";
        else
            cout<<"Player2 won the toss\n\n";

        cout<<"total sticks are "<<n<<" on the table\n\n";
        cout<<"\n--------game starts now----------\n\n\n";

        if(!chance)
        {
            cout<<"Player2, pick up sticks in range of 1 to 3: ";
            cin>>person;
            while(person < 1 || person > 3)
            {
                cout<<"please pick up sticks striclty between 1 to 3: ";
                cin>>person;
            }
            cout<<"\Player2 picked up "<<person<<" sticks\n";
            n = n - person;
            cout<<"remaining sticks are "<<n<<"\n\n";
        }

        while(n)
        {
            cout<<"Player1, pick up sticks in range of 1 to 3: ";
            cin>>person;
            while(person < 1 || person > 3)
            {
                cout<<"please pick up sticks striclty between 1 to 3: ";
                cin>>person;
            }
            cout<<"\nPlayer1 picked up "<<person<<" sticks\n";

            while(person > n)
            {
                cout<<"you tried to pick more than remaining sticks\n";
                cout<<"enter less than remaining sticks on table: ";
                cin>>person;
            }
            n = n - person;
            cout<<"\nremaining sticks are "<<n<<"\n\n";


            if(n == 0)
            {
                cout<<"\n\n-------------Player1 lost, Player2 won....CONGRATULATIONS PLAYER 2----------------\n\n\n\n";
                break;
            }

            cout<<"Player2, pick up sticks in range of 1 to 3: ";
            cin>>person;
            while(person < 1 || person > 3)
            {
                cout<<"please pick up sticks striclty between 1 to 3: ";
                cin>>person;
            }
            cout<<"\nPlayer2 picked up "<<person<<" sticks\n";

            while(person > n)
            {
                cout<<"you tried to pick more than remaining sticks\n";
                cout<<"enter less than remaining sticks on table: ";
                cin>>person;
            }
            n = n - person;
            cout<<"\nremaining sticks are "<<n<<"\n\n";


            if(n == 0)
            {
                cout<<"\n\n-------------Player2 lost, Player1 won....CONGRATULATIONS PLAYER 1----------------\n\n\n\n";
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
