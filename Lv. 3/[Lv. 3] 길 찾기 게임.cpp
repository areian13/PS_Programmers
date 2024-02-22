#include <vector>
#include <queue>

using namespace std;

typedef struct Node
{
    int idx;
    int x, y;

    Node* l = nullptr;
    Node* r = nullptr;

    Node(int idx, int x, int y)
    {
        this->idx = idx;
        this->x = x;
        this->y = y;
    }

    friend bool operator<(const Node& a, const Node& b)
    {
        if (a.y != b.y)
            return a.y < b.y;
        return a.x < b.x;
    }
};

class BinaryTree
{
public:
    Node* root = nullptr;

    void Push(const Node& data)
    {
        root = Push(root, data);
    }
    Node* Push(Node* node, const Node& data)
    {
        if (node == nullptr)
            return new Node(data.idx, data.x, data.y);

        if (data.x < node->x)
            node->l = Push(node->l, data);
        else
            node->r = Push(node->r, data);
        return node;
    }
    void Preorder(Node* node, vector<int>& result)
    {
        if (node == nullptr)
            return;

        result.push_back(node->idx);
        Preorder(node->l, result);
        Preorder(node->r, result);
    }
    void Preorder(vector<int>& result)
    {
        Preorder(root, result);
    }
    void Postorder(Node* node, vector<int>& result)
    {
        if (node == nullptr)
            return;

        Postorder(node->l, result);
        Postorder(node->r, result);
        result.push_back(node->idx);
    }
    void Postorder(vector<int>& result)
    {
        Postorder(root, result);
    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    priority_queue<Node> PQ;

    int n = nodeinfo.size();
    for (int i = 0; i < n; i++)
    {
        int idx = i + 1;
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];

        PQ.push({ idx,x,y });
    }

    BinaryTree tree;
    while (!PQ.empty())
    {
        tree.Push(PQ.top());
        PQ.pop();
    }

    vector<vector<int>> result(2);
    tree.Preorder(result[0]);
    tree.Postorder(result[1]);
    return result;
}