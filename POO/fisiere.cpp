#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream f("date.in");
    ofstream g("date.out");

    int n, v[100], i;
    f>>n;
    for (i = 1; i <= n; i++)
    {
        f>>v[i];
    }

    for (i = 1; i <= n; i++)
    {
        g<<v[i]<<" ";
    }
    return 0;
}