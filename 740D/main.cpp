#include <iostream>

using namespace std;

void bs(int st, int dr,int x)
{
    while (st<=dr)
    {
        int m=(st+dr)/2;
        if (cost[x]-cost[m]>a[x])
            dr=m-1;
        else
            if (cost[x])
    }
}

void dfs(int x, int nr)
{
    b[nr]=x;
    for (int i=0; i<v[x].size(); i++)
        {
                dfs(v[x][i],nr+1);
                cost[v[x][i]]=cost[i]+c[v[x][i]];
        }
    bs(1,nr-1,x);
}

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
        cin >> a[i];
    for (i=2; i<=n; i++)
    {
        int x,y;
        cin >> x >> y;
        p[i]=x;
        c[i]=y;
        v[x].push_back(i);
    }
    dfs(1,1);
}
