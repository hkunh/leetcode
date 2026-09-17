#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Node{
    char value;
    int left;
    int right;
};
void preorder(int index,const vector<Node>& nodes, string& result)
{
    if(index == 0)
    {
        return;
    }
    result += nodes[index].value;
    preorder(nodes[index].left, nodes, result);
    preorder(nodes[index].right, nodes, result);
}
void inorder(int index, const vector<Node>& nodes, string& result)
{
    if(index == 0)
    {
        return;
    }
    inorder(nodes[index].left, nodes, result);
    result += nodes[index].value;
    inorder(nodes[index].right, nodes, result);

}
void postorder(int index, const vector<Node>& nodes, string& result)
{
    if(index == 0)
    {
        return;
    }
    // 左子树
    postorder(
        nodes[index].left,
        nodes,
        result
    );

    // 右子树
    postorder(
        nodes[index].right,
        nodes,
        result
    );

    // 根
    result += nodes[index].value;
}
int main()
{
    int N;
    while(cin >> N)
    {
        // 节点编号从 1 开始，
        // 所以开 N+1 个位置
        vector<Node> nodes(N + 1);
        // 用来判断哪个节点是根节点
        //
        // isChild[i] == true
        // 表示编号 i 的节点曾经作为别人的孩子出现
        vector<bool> isChild(N + 1, false);
        for(int i = 1; i <= N; ++i)
        {
            char value;
            int left;
            int right;

            cin >> value >> left >> right;
            nodes[i].value = value;
            nodes[i].left = left;
            nodes[i].right = right;
            // 如果 left/right 不为 0，
            // 说明对应节点是某个节点的孩子
            if(left != 0)
            {
                isChild[left] = true;
            }
            if(right != 0)
            {
                isChild[right] = true;
            }
        }

        // --------------------------------------------------
        // 找根节点
        //
        // 根节点不会作为任何节点的孩子出现
        // --------------------------------------------------
        int root = 0;
        for(int i = 1; i <=N; ++i)
        {
            if(!isChild[i])
            {
                root = i;
                break;
            }
        }

        // --------------------------------------------------
        // 三种遍历
        // --------------------------------------------------

        string pre;
        string in;
        string post;

        preorder(
            root,
            nodes,
            pre
        );

        inorder(
            root,
            nodes,
            in
        );

        postorder(
            root,
            nodes,
            post
        );


        // --------------------------------------------------
        // 输出
        // --------------------------------------------------

        cout << pre << '\n';
        cout << in << '\n';
        cout << post << '\n';
    }
    return 0;
}
