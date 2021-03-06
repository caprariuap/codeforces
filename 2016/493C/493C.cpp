#include <iostream>
#include <algorithm>

using namespace std;

int n,m,i,j;
long long a[200010],b[200010],d,s1,s2;


int cb(long long x, int p, int u)
{
    int M;
    while (p<=u)
    {
        M=(p+u)/2;
        if (b[M]==x)
            return M;
        if (b[M]<x) p=M+1;
        else u=M-1;
    }
    return p;
}

int main()
{
    cin>>n;
    for (i=1; i<=n; i++)
        cin>>a[i];
    cin>>m;
    for (i=1; i<=m; i++)
        cin>>b[i];
    s1=2*n;
    s2=2*m;
    long long maxim=s1-s2;
    long long sc1,sc2;
    sc1=s1;
    sc2=s2;
    sort(a+1, a+n+1);
    sort(b+1, b+m+1);
    i=0;
    d=a[1]-1;
    int k;
    if (d<b[1]) k=0;
        else
        if (d>b[m]) k=m+1;
    else
        k=cb(d,1,m);

    int nr=n-i-m+k;

    if ((nr>0&&s1-s2+nr>maxim)||(s1-s2+nr==maxim&&s1+n-i>sc1))
        maxim=s1+nr-s2,sc1=s1+n-i,sc2=s2+m-k;

    for (i=1; i<=n; i++)
    {
        d=a[i];
        if (d<b[1]) k=0;
        else if (d>b[m]) k=m+1;
        else
            k=cb(d,1,m);
        int nr=n-i-m+k;
        if ( (nr>0&&s1-s2+nr>maxim) || (s1-s2+nr==maxim&&s1+n-i>sc1) )
            maxim=s1+nr-s2,
            sc1=s1+n-i,
            sc2=m-k;
    }
    cout<<sc1<<':'<<sc2<<'\n';
}
