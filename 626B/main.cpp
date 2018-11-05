#include <iostream>

using namespace std;

int n,i,b,g,r;

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
    {
        char c;
        cin >> c;
        if (c=='B')
            b++;
        if (c=='R')
            r++;
        if (c=='G')
            g++;
    }
    r=min(2,r);
    b=min(2,b);
    g=min(2,g);
    if (b>=1&&r>=1&g>=1||(max(r,b)==2&&r+b+g==4&&r*b*g==0))
    {
        cout << "BGR\n";
        return 0;
    }
    if (b+r+g==max(max(r,b),g))
    {
        if (max(max(r,b),g)==max(r,b))
            if (r>b)
            {
                cout << "R\n";
                return 0;
            }
            else
            {
                cout << "B\n";
                return 0;
            }
        else
        {
            cout << "G\n";
            return 0;
        }
    }
    if (b==1&&r==1)
    {
        cout << "G\n";
        return 0;
    }
    if (b==1&&g==1)
    {
        cout << "R\n";
        return 0;
    }
    if (g==1&&r==1)
    {
        cout << "B\n";
        return 0;
    }
    if (b==2)
    {
        cout << "GR\n";
        return 0;
    }
    if (r==2)
    {
        cout << "BG\n";
        return 0;
    }
    if (g==2)
    {
        cout << "BR\n";
        return 0;
    }
}
