#include <iostream>
#define pu(x) ((x^(x-1))&x)

using namespace std;

int n,k,i,aib[1000100];

void update(int val, int poz)
{
    for (int i=poz; i<=n; i+=pu(i))
        aib[i]+=val;
}

long long query(int poz)
{
    long long ret=0;
    for (int i=poz; i; i-=pu(i))
        ret+=aib[i];
    return ret;
}

long long q(int st, int dr)
{
    return query(dr)-query(st-1);
}

int main()
{
    cin >> n >> k;
    int poz1=1;
    long long ans=1;
    k=min(k,n-k);
    for (i=1; i<=n; i++)
    {
        int poz2=poz1+k;
        if (poz2>n)
            poz2-=n;
        if (poz1<poz2)
            ans=ans+q(poz1+1,poz2-1)+1;
        else
            ans=ans+q(poz1+1,n)+q(1,poz2-1)+1;
        update(1,poz2);
        update(1,poz1);
        cout << ans << '\n';
        poz1=poz2;
    }
}
