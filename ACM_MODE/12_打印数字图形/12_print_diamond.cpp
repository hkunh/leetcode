#include <iostream>
using namespace std;
int main()
{
    int N = 0;
    while(cin >> N)
    {
        int w = 2 * N - 1;
        int h = 2 * N - 1;
        for(int i = 1; i <= h; ++i)
        {
            int l = 0;
            int r = 0;
            if(i <= N)
            {
                l = N - i + 1;
                r = N + i - 1;
            }
            else
            {
                l = i - N + 1;
                r = 3*N - i - 1;
            }
            for(int j = 1; j <= w; ++j)
            {
                if(l <= j && j <= N)
                {
                    cout <<  j - l + 1;
                }
                else if(N < j && j <= r)
                {
                    cout << r - j + 1;
                }
                else{
                    if(j <= r)
                    {
                        cout << " ";
                    }
                }
            }

            cout << "\n";

        }
    }
}