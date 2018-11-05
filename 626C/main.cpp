#include <iostream>
#define maxim(a,b) a>b ? a : b
#define minim(a,b) a<b ? a : b

using namespace std;

int n,m,i;

int main()
{
    cin >> n >> m;
    n*=2;
    m*=3;
    int mdnm=minim(n,m);
    for (i=6; i<=mdnm; i+=6)
    {
        int m1=maxim(n+2,m);
        int m2=maxim(n,m+3);
        if (m1<m2)
            n+=2;
        else
            m+=3;
        mdnm=minim(n,m);
    }
    int ans=maxim(n,m);
    cout << ans << '\n';
}
