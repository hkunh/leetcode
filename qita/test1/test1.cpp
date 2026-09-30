#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;
struct Node
{
    int index;
    vector<string> strs;
};
// 计算节点 node 能给当前批次新增多少个不同特征值
// int calcDiff(const Node &node, const unordered_set<string> &features)
// {
//     int diff = 0;
//     for(int i = 0; i < node.strs.size(); ++i)
//     {
//         if(!features.count(node.strs[i]))
//         {
//             diff += 1;
//         }
//     }
//     return diff;
// }
//node.strs内部去重
int calcDiff(
    const Node &node,
    const unordered_set<string> &features)
{
    int diff = 0;

    unordered_set<string> local;

    for(const string &s : node.strs)
    {
        if(features.count(s) == 0 &&
           local.count(s) == 0)
        {
            diff++;
            local.insert(s);
        }
    }

    return diff;
}
int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        vector<Node> nodes(n);
        // ================================
        // 输入
        // ================================
        for(int i = 0; i < n; ++i)
        {
            cin >> nodes[i].index;
            nodes[i].strs.resize(m);
            for(int j = 0; j < m; ++j)
            {
                cin >> nodes[i].strs[j];
            }
        }

        int k;
        cin >> k;
        // ================================
        // 为了保证同分时编号小的优先
        // 可以先按编号排序
        // ================================
        sort(nodes.begin(), nodes.end(),
            [](const Node& a, const Node& b)
            {
                return a.index < b.index;
            }
        );
        // ================================
        // visited[i] 表示 nodes[i] 是否已经分批
        // ================================
        vector<int> visited(n, 0);
        // ================================
        // 批次数
        //
        // n=10,k=3
        //
        // batchCount = 3
        //
        // 前两个3个，最后一个4个
        // ================================
        int batchCount = n / k;
        // 防止 n < k
        if(batchCount == 0)
        {
            batchCount = 1;
        }
        // ================================
        // 一个批次一个批次处理
        // ================================
        for(int batch = 0; batch < batchCount; ++batch)
        {
            unordered_set<string> features;
            vector<int>  result;
            
            int batchsize = 0;
            if(batch != batchCount - 1)
            {
                batchsize = k;
            }
            else{
                batchsize = k + n%k;
            }
            for(int c = 0; c < batchsize ; c++)
            {
                int max_index = -1;
                int diff_count = -1;
                for(int i = 0; i < n; ++i)
                {
                    if(visited[i] == 0)
                    {
                        int new_diff = calcDiff(nodes[i], features);
                        if(diff_count < new_diff)
                        {
                            diff_count = new_diff;
                            max_index = i;
                        }
                    }
                }
                for(int j = 0; j < m; j++)
                {
                    features.insert(nodes[max_index].strs[j]);
                }
                result.push_back(nodes[max_index].index);
                visited[max_index] = 1;
            }
            for(int l = 0; l < result.size(); l++)
            {
                cout << result[l];
                if(l != result.size() - 1)
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }
}