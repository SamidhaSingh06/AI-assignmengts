#include <bits/stdc++.h>
using namespace std;

struct node
{
    int index;
    int cost;
};
int n;
vector<int> v0;

bool comp(node i, node j)
{
    return (i.cost < j.cost);
}

int mst(int **graph, int k)
{
    vector<node>q;
    int c = 0, j;
    int arr[n] = {0};
    arr[k] = 1;
    while(true)
    {
        for(j=1;j<n;j++)
        {
            if(arr[j] == 0 && graph[k][j] != -1)
            {
                node m;
                m.index = j;
                m.cost = graph[k][j];
                q.push_back(m);
            }
        }
        if(q.empty())
            return c + v0[k];

        sort(q.begin(),q.end(),comp);
        k = q[0].index;
        c += q[0].cost;
        arr[k] = 1;
        q.clear();
    }
}

void input_graph(int **graph)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("enter cost for %d to %d = ",i+1,j+1);
            scanf("%d",&graph[i][j]);
            if(i == j)
                graph[i][j] = -1;
        }
        v0.push_back(graph[i][0]);
    }
}

int main()
{
    int i, j, sum = 0;
    printf("enter no.of cities = ");
    scanf("%d",&n);
    vector<int> closed;
    vector<node> v;
    int arr1[n] = {0};
    int **graph,h[n];
    graph = new int *[n];

    for(i=0;i<n;i++)
        graph[i] = new int[n];

    input_graph(graph);

    for(i=1;i<n;i++)
        h[i] = mst(graph,i);

    i=0;
    closed.push_back(0);
    arr1[0] = 1;

    while(closed.size() != n)
    {
        for(j=1;j<n;j++)
        {
            if(graph[i][j] != -1)
            {
                node n1;
                n1.index = j;
                n1.cost = graph[i][j] + h[j];
                v.push_back(n1);
            }
        }

        sort(v.begin(),v.end(),comp);

        closed.push_back(v[0].index);
        sum += graph[i][v[0].index];

        for(j=0;j<n;j++)
        {
            graph[i][j] = -1;
            graph[j][v[0].index] = -1;
        }

        arr1[v[0].index] = 1;

        if(closed.size() != n)
        {
            for(i=1;i<n;i++)
            {
                if(arr1[i] != 1)
                    h[i] = mst(graph,i);
            }
        }

        i = v[0].index;
        v.clear();
    }

    sum += v0[i];
    for(i=0;i<closed.size();i++)
        cout<<closed[i] + 1<<" -> ";
    cout<<1<<"\n";
    cout<<"total cost is "<<sum;
}
