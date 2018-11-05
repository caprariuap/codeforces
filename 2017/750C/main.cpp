#include <iostream>

using namespace std;

int n,minim,maxim,i,cost,divi,sum;

void solve()
{
    cin >> n;
    maxim=100000000;
    minim=-100000000;
    sum=0;
    for (i=1; i<=n; i++)
    {
        cin >> cost >> divi;
        if (divi==1)
            minim=max(1900-sum,minim);
        if (divi==2)
            maxim=min(1899-sum,maxim);
        if (minim>maxim&&minim!=-100000000&&maxim!=100000000)
        {
            cout << "Impossible\n";
            return;
        }
        sum+=cost;
    }
    if (maxim==100000000)
    {
        cout << "Infinity\n";
        return;
    }
    cout << maxim+sum << '\n';
}


int main()
{
    solve();
}
