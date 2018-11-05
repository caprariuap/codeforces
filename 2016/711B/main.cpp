#include <iostream>

using namespace std;

long long n,a[510][510],i,j,x,y,sumr[510],sumc[510],s1,s2,ans;

void solve()
{
    if (n==1)
    {
        cout<<"1";
        return;
    }
    if (sumr[x]!=sumc[y])
    {
        cout<<"-1";
        return;
    }
    if (s1!=s2&&(x!=n-y+1&&x!=y))
    {
        cout<<"-1";
        return;
    }
    for (i=1 ; i<=n; i++)
        if (i!=x)
        {
            if (sumr[i]-sumr[x]==0)
            {
                cout<<"-1";
                return;
            }
            if (ans==0)
                ans=sumr[i]-sumr[x];
            else if (sumr[i]-sumr[x]!=ans)
            {
                cout<<"-1";
                return;
            }
        }
    for (i=1 ; i<=n; i++)
        if (i!=y)
        {
            if (sumc[i]-sumc[y]==0)
            {
                cout<<"-1";
                return;
            }
            if (ans==0)
                ans=sumc[i]-sumc[y];
            else if (sumc[i]-sumc[y]!=ans)
            {
                cout<<"-1";
                return;
            }
        }
    sumr[x]+=ans;
    sumc[y]+=ans;
    if (x==y)
        s1+=ans;
    if (x==n-y+1)
        s2+=ans;
    if (s2!=sumr[x]||s2!=sumc[y])
    {
        cout<<"-1";
        return;
    }
    if (s1!=sumr[x]||s2!=sumc[y])
    {
        cout<<"-1";
        return;
    }
    if (ans>0)
        cout<<ans;
    else
    {
        cout<<"-1";
        return;
    }
}

int main()
{
    cin>>n;
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
        {
            cin>>a[i][j];
            if (a[i][j]==0)
                x=i,y=j;
        }
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
            sumr[i]+=a[i][j],sumc[j]+=a[i][j];
        s1+=a[i][i];
        s2+=a[i][n-i+1];
    }
    solve();
    return 0;
}
