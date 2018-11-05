#include <iostream>

using namespace std;

long long n,i,j;

int main()
{
    cin>>n;
    cout<<"2\n";
    for (i=2; i<=n; i++)
        cout<<i*i*i+2*i*i+1<<'\n';
    return 0;
}
/*
i(i-1)+x*i=i*i(i+1)^2
i-1+x=i(i+1)^2
x=i^3+2i^2+1
*/
