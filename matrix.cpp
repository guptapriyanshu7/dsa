#include<iostream>
#define FOR(x,u) for(x=0;x<u;x++)
using namespace std;
int main()
{
    int a[3][3],i,j;
    FOR(i,3)
        FOR(j,3)
            cin>>a[i][j];
    FOR(i,3)
    {
        FOR(j,3)
            cout<<a[i][j]<<" "; 
        cout<<"\n";
    }  
    return 0;
}