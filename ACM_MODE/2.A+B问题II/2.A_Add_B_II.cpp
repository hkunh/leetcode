#include <iostream>
using namespace std;
int main()
{
    int N;
    // 不断读取每一组测试数据的 N
    // 直到输入结束 EOF
    while(cin >> N)
    {
        for(int i = 0; i < N; ++i)
        {
            long long a, b;
            cin >> a >> b;
            cout << a + b << "\n";
        }
    }
    return 0;
}