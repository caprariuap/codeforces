#include <cstdio>

using namespace std;

int x,y,n,i,j,a,b,c;

int solve()
{
    int ans=0;
    while (a!=x)
    {
        a=x;
        if (b+c-1<a)
            a=b+c-1;
        ans++;
        int aux=a;
        a=b;
        b=c;
        c=aux;
    }
    return ans;
}

int main()
{
    scanf("%d%d",&x,&y);
    a=b=c=y;
    printf("%d\n",solve());
}
