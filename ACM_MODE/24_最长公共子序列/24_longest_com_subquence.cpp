#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string X;
    string Y;
    // 多组测试数据
    // 每组两个字符串
    // 一直读取到 EOF
    while(cin >> X >> Y)
    {
        int n = X.size();
        int m = Y.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // --------------------------------------------------
        // dp[0][j] = 0
        // dp[i][0] = 0
        //
        // 因为其中一个字符串为空时，
        // 公共子序列长度一定是 0
        // --------------------------------------------------
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                //当前两个字符相同
                if(X[i - 1] == Y[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[n][m] << '\n';
    }
    return 0;
}