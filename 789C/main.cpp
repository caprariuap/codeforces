#include <iostream>

using namespace std;

long long Abs(long long x)
{
    if (x<0)
        return -x;
    return x;
}

long long n,i,a[100010],ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (i=1; i<=n; i++)
        cin >> a[i];
    for (i=1; i<n; i++)
        a[i]=Abs(a[i+1]-a[i]);
    long long sum0,sum1;
    sum0=sum1=0;
    ans=-1e9;
    ans-=10;
    for (i=1; i<n; i++)
    {
        if (i&1) sum0+=a[i],sum1-=a[i];
        else
            sum0-=a[i],sum1+=a[i];
        ans=max(ans,max(sum0,sum1));
        if (sum0<0)
            sum0=0;
        if (sum1<0)
            sum1=0;
    }
    cout << ans << '\n';
}
