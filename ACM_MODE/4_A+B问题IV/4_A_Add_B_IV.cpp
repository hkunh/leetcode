#include <iostream>
using namespace std;
int main()
{
    int N;
    while(cin >> N)
    {
        if(N == 0)
        {
            break;
        }
        long long sum = 0;
        // 当前这一组后面有 N 个整数
        for(int i = 0; i < N; ++i)
        {
            long long x;
            cin >> x;
            sum += x;
        }
        cout << sum << "\n";
    }
    return 0;
}