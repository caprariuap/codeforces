#include <iostream>
#include <map>
#include <utility>
#define min(a,b) a<b ? a : b

using namespace std;

map <pair <int, int>, int> m,poz;
map <pair <int, int>, int>::iterator it;

int n,maxim,i,poz1,poz2,pozk1,maxim1;

int minim(int a, int b, int c)
{
    if (a<b)
        return min(a,c);
    else
        return min(c,b);
}

void solve(int a, int b, int c)
{
    pair <int, int> p;
    p=make_pair(a,b);
    it=m.find(p);
    if (it==m.end())
        m[p]=c,poz[p]=i;
    else
    {
        int x=m[p]+c;
        if (minim(a,b,x)>maxim)
        {
            maxim=minim(a,b,x);
            poz1=poz[p];
            poz2=i;

        }
        if (c>m[p])
            m[p]=c,poz[p]=i;
    }
//    cout << maxim << ' ' << poz1 << ' ' << poz2 << ' ' << i << '\n';
}

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if (a<b)
            solve(a,b,c);
        else
            solve(b,a,c);
        if (c<a)
            solve(c,a,b);
        else
            solve(a,c,b);
        if (b<c)
            solve(b,c,a);
        else
            solve(c,b,a);
        if (minim(a,b,c)>maxim1)
            maxim1=minim(a,b,c),pozk1=i;
    }
    if (maxim>maxim1)
    cout << 2 << '\n' << poz1 << ' ' << poz2;
    else
        cout << 1 << '\n' << pozk1;
    cout << '\n';
}
