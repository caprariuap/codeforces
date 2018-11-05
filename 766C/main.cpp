#include <iostream>
#define NMAX 10000
#define MOD 1000000007

using namespace std;

int i,j,n,m,mini,val[NMAX],dp[NMAX],arbint[NMAX];
int s[NMAX];

int calcmin(int a, int b)
{
    int ret=1500;
    for (int i=a; i<=b; i++)
        if (val[s[i]]<ret)
            ret=val[s[i]];
    return ret;
}

void actualizare(int nod, int st, int dr, int a, int b)
{
    if (st==dr)
    {
        arbint[nod]=b;
        return;
    }
    int mij=(st+dr)/2;
    if (a<=mij)
        actualizare(2*nod,st,mij,a,b);
    else
        actualizare(2*nod+1,mij+1,dr,a,b);
    arbint[nod]=min(arbint[2*nod],arbint[2*nod+1]);
}

void interogare(int nod, int st, int dr, int a, int b)
{
    if (st>=a&&dr<=b)
    {
        if (mini>arbint[nod])
        mini=arbint[nod];
        return;
    }
    int mij=(st+dr)/2;
    if (a<=mij)
        interogare(2*nod,st,mij,a,b);
    if (mij<b)
        interogare(2*nod+1,mij+1,dr,a,b);
}

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
    {
        char c;
        cin >> c;
        s[i]=c-'a'+1;
    }
    for (i=1; i<=26; i++)
        cin >> val[i];
    for (i=1; i<=n; i++)
        actualizare(1,1,n,i,val[s[i]]);
    dp[1]=1;
    dp[0]=1;
    for (i=2; i<=n; i++)
    {
        int poz=max(i-val[s[i]],1);
        for (j=poz; j<i; j++)
        {
            mini=15000;
            interogare(1,1,n,j,i);
            if (i-j+1<=mini)
                    dp[i]=(dp[i]+dp[j-1])%MOD;
        }
        dp[i]=(dp[i]+dp[i-1])%MOD;
    }
    cout << dp[n]%MOD << '\n';
    i=1;
    j=1;
    int MAXX=0;
    while (i<=n)
    {
        mini=1500;
        interogare(1,1,n,i,j);
        while (j-i+1<=mini&&j<=n)
        {
            j++;
            mini=min(mini,val[s[j]]);
        }
        j--;
        if (j-i+1>MAXX)
            MAXX=j-i+1;
        i++;
    }
    cout << MAXX << '\n';
    i=1;
    j=1;
    int NRSUB=0;
    while (i<=n)
    {
        mini=1500;
        interogare(1,1,n,i,j);
        while (j-i+1<=mini&&j<=n)
        {
            j++;
            mini=min(mini,val[s[j]]);
        }
        j--;
        i=j+1;
        j=i+1;
        NRSUB++;
    }
    cout << NRSUB << '\n';
}
