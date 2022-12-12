#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    freopen("graphGenerate.txt", "w", stdout);
    cout << 100 << " " << 300 << endl;

    for (int i = 0; i < 300; i++)
    {
        cout << rand() % 100 << " " << rand() % 100 << " " << rand() % 30 << endl;
    }
}