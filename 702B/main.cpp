#include <cstdio>
#include <map>

using namespace std;

int a[100010],n,i,j,p2[31];
long long ans;

map <int, int> m;

int main()
{
    p2[0]=1;
    for (i=1; i<=30; i++)
        p2[i]=p2[i-1]*2;
    scanf("%d",&n);
    for (i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        m[a[i]]++;
    }
    for (i=1; i<=n; i++)
    {
        m[a[i]]--;
        for (j=1; j<=30; j++)
            if (m.find(p2[j]-a[i])!=m.end())
                ans+=m[p2[j]-a[i]];
    }
    printf("%lld\n",ans);
}
