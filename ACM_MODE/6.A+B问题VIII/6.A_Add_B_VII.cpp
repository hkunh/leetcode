#include <iostream>
using namespace std;
int main()
{
    int N;
    // 后端可能有多组测试数据，
    // 所以不断读取 N，直到 EOF
    while(cin >> N)
    {
        for(int i = 0; i < N; ++i)
        {
            int M;
            cin >> M;
            long long sum = 0;
            for(int j = 0; j < M; ++j)
            {
                long long x;
                cin >> x;
                sum += x;
            }
            cout << sum << "\n";
            // 同一组数据中，
            // 每两个结果之间需要一个空行。
            //
            // 但当前组最后一个结果后面不能再输出空行，
            // 因为下一组需要直接接着输出。
            if(i != N - 1)
            {
                cout << "\n";
            }
        }
    }
    return 0;
}