#include <iostream>

using namespace std;

long long n,i;

int main()
{
    cin >> n;
    for (i=n/2+1; i<=100000; i++)
        if (n*(i+1)%(2*i-n)==0&&i!=1&&(n*(i+1)/(2*i-n))!=1)
            if (i * (n*(i+1)/(2*i-n)) < 1000000000 && i * (n*(i+1)/(2*i-n)) > 0)
            {
                cout << i << ' ' << n*(i+1)/(2*i-n) << ' ' << i * (n*(i+1)/(2*i-n)) << '\n';
                return 0;
            }
    cout << "-1" << '\n';
}
/*z=xy
1/x+1/y+1/xy=2/n
x+y+1=2xy/n
nx+ny+n=2xy
x(n-2y)+n(y+1)=0
x(2y-n)=n(y+1)
x=n(y+1)/(2y-n)
*/
