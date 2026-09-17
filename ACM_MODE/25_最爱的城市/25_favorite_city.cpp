#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Floyd 算法 图中不能有负权环（负权回路）
int main()
{
    int n, m;
    // 多组测试数据，读取到 EOF
    while(cin >> n >> m)
    {
        const int INF = 1e9;

        // dist[i][j]：
        // 城市 i 到城市 j 的最短距离
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
        for(int i = 1; i <= n; ++i)
        {
            dist[i][i] = 0;
        }

        // --------------------------------------------------
        // 读取 m 条边
        //
        // 题目说“用线段两两连接”，
        // 因此这里是无向图：
        //
        // a -> b
        // b -> a
        //
        // 距离都为 l
        // --------------------------------------------------
        for(int i = 0; i < m; ++i)
        {
            int a, b, l;
            cin >> a >> b >> l;
            // 如果可能出现重复边，
            // 取其中较短的一条
            dist[a][b] = min(dist[a][b], l);
            dist[b][a] = min(dist[b][a], l);
        }

        // --------------------------------------------------
        // Floyd 算法
        //
        // k：
        // 当前允许作为“中间城市”的节点
        // --------------------------------------------------
        for(int k = 1; k <= n; ++k)
        {
            for(int i = 1; i <= n; ++i)
            {
                for(int j = 1; j <= n; ++j)
                {
                    // 如果 i -> k 或 k -> j 不连通，
                    // 没必要更新
                    if(dist[i][k] == INF || dist[k][j] == INF)
                    {
                        continue;
                    } 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int x, y;
        cin >> x >> y;
        if(dist[x][y] == INF)
        {
            cout << "No path" << "\n";
        }
        else{
            cout << dist[x][y] << "\n";
        }

    }
}