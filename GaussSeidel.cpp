#include<bits/stdc++.h>
#define f1(x,y,z) ((7+y)/2)
#define f2(x,y,z) ((1+x+z)/2)
#define f3(x,y,z)  ((1+y)/2)
using namespace std;
int main()
{
    float e;
    cout <<"Enter tolerance:"<<endl;
    cin >> e;
    float x,y,z,x0=0,y0=0,z0=0,e1,e2,e3;
    do
    {
        x = f1(x0,y0,z0);
        y = f2(x,y0,z0);
        z = f3(x,y,z0);
        e1 = abs(x0-x);
        e2 = abs(y0-y);
        e3 = abs(z0-z);
        x0 = x;
        y0 = y;
        z0 = z;
    }
    while(e1>e && e2>e && e3>e);
        cout<< x << " "<<y<<" "<<z;
    return 0;
}

