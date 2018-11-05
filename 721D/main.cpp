#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

long long n,k,x,neg,a[200010],i,j,nrzero;

struct Node
{
    long long i;
    bool operator < (const Node &rhs) const
    {
        return abs(a[i]) > abs(a[rhs.i]);
    }
};

priority_queue <Node> q;

int main()
{
    cin>>n>>k>>x;
    int cnt=0;
    for (i=1; i<=n; i++)
    {
        cin>>a[i];
        q.push(Node{i});
        if (a[i]<0)
            cnt++;
    }
    if (cnt & 1) neg=1;
    else neg=0;
    for (i=1; i<=k; i++)
    {
        long long i=q.top().i;
        q.pop();
        if (neg)
        {
            if (a[i]>=0) a[i]+=x;
            else a[i]-=x;
        }
        else
        {
            if (a[i]>=0)
            {
                a[i]-=x;
                if (a[i]<0)
                    neg=1-neg;
            }
            else
            {
                a[i]+=x;
                if (a[i]>=0) neg=1-neg;
            }
        }
        q.push(Node{i});
    }
    for (i=1; i<=n; i++)
        cout<<a[i]<<' ';
    cout<<'\n';
}
