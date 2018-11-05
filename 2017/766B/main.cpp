#include <iostream>
#include <algorithm>

using namespace std;

int n,a[1000000],i;

int main()
{
    cin >> n;
    for (i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for (i=3; i<=n; i++)
        if (a[i-1]+a[i-2]>a[i])
        {
            cout << "YES\n";
            return 0;
        }
    cout << "NO\n";
    return 0;
}
