#include<bits/stdc++.h>
using namespace std;

int n,m,k;

int fitness(int **marks, vector<int>r, vector<int>l)
{
    int i,j,h,sum = 0;
    vector<int> f;
    for(i=0;i<l.size();i++)
    {
        for(j=0;j<r.size();j++)
        {
            for(h=0;h<m;h++)
            {
                f.push_back(pow(marks[l][h] - marks[r][h] , 2));
            }
        }
        sort(f.begin(),f.end());
        sum += f[0];
        f.clear();
    }
    return sum;
}

int crossover(vector<int>a,vector<int>b)
{
    vector<int>c,d;

    for(i=0;i<a.size();i++)
    {
        c[i] = a[i];
        d[i] = b[i];
    }

    for(i=1;i<3;i++)
    {
        swap(c[a.size()-i],d[b.size()-i]);
    }
    vector<int>l1,l2;
    int f3 = fitness(marks,c,l1);
    int f4 = fitness(marks,d,l2);
    vector<pair<int,char>>f;
    f.push_back(f1,'a');
    f.push_back(f2,'b');
    f.push_back(f3,'c');
    f.push_back(f4,'d');
    sort(f.begin(),f.end(),comp);

}

int main()
{
    int i,j;
    cout<<"enter number of students"<<"\n";
    cin>>n;
    cout<<"enter number of subjects\n";
    cin>>m;
    int **marks;
    marks = new int *[n];
    for(i=0;i<n;i++)
        marks[i] = new int [m];
    cout<<"enter marks for each student\n";
    for(i=0;i<n;i++)
    {
        for(j=0j<m;j++)
            cin>>marks[i][j];
    }
    cout<<"enter number of clusters\n";
    cin>>k;
    set<int> s;
    //generate 4 population
    //select 2 best fitness value
    //crossover()
    //do it for 10 times
}
