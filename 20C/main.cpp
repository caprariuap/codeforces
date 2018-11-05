#include <cstdio>
#include <vector>

using namespace std;

long long n,m,i,j,h[100100],d[100100],p[100100],poz[100100],nr;

vector <long long> v[100100],cost[100100];

void upheap(long long pp)
{
    long long p=pp;
    long long x=h[p];
    while (d[x]<d[h[p/2]]&&p>1)
    {
        swap(h[p],h[p/2]);
        swap(poz[h[p]],poz[h[p/2]]);
        p/=2;
    }
}

void eliminare()
{
    poz[h[nr]]=1;
    poz[h[1]]=0;
    h[1]=h[nr];
    nr--;
    long long ind=1;
    while (ind*2<=nr)
    {
        long long f=ind*2;
        if (f+1<=nr&&d[h[f+1]]<d[h[f]])
            f++;
        if (d[h[f]]<d[h[ind]])
        {
            swap(poz[h[f]],poz[h[ind]]);
            swap(h[ind],h[f]);
            ind=f;
        }
        else
            return;
    }
}

void afisare(long long x)
{
    if (p[x]!=0)
        afisare(p[x]);
    printf("%lld ",x);
}

int main()
{
    scanf("%lld%lld",&n,&m);
    for (i=2; i<=n; i++)
        d[i]=100000000010;
    for (i=1; i<=m; i++)
    {
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        v[a].push_back(b);
        cost[a].push_back(c);
        v[b].push_back(a);
        cost[b].push_back(c);
    }
    h[++nr]=1;
    poz[1]=1;
    while (nr)
    {
        long long x=h[1];
        eliminare();
        for (i=0; i<v[x].size(); i++)
            if (d[v[x][i]]>d[x]+cost[x][i])
            {
                if (poz[v[x][i]]==0)
                {
                    d[v[x][i]]=d[x]+cost[x][i];
                    h[++nr]=v[x][i];
                    poz[v[x][i]]=nr;
                    upheap(nr);
                    p[v[x][i]]=x;
                }
                else
                {
                    p[v[x][i]]=x;
                    d[v[x][i]]=d[x]+cost[x][i];
                    upheap(poz[v[x][i]]);
                }
            }
    }
    if (d[n]==100000000010)
        printf("-1");
    else
    {
        afisare(n);
    }
}
