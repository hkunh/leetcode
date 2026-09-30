#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    char X;
    int n;
    while(cin >> X)
    {
        if(X == '@')
        {
            break;
        }
        cin >> n;
        int w = 2 * n - 1;
        for(int i = 1; i <= n; ++i)
        {
            int l = n - i + 1;
            int r = n + i - 1;
            for(int j = 1; j <= r; ++j)
            {
                if(l == j || j == r || i == n)
                {
                    cout << X;
                }
                else
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }
}