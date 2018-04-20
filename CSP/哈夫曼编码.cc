#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
using namespace std;
struct HuffmanNode {
    int frequency;
    int l;
    int r;
    HuffmanNode(int _frequency, int _l, int _r): frequency(_frequency), l(_l), r(_r) {}
    HuffmanNode(int _frequency) : HuffmanNode(_frequency, -1, -1) {}
};
void dfs(vector<int> &path, int u, vector<HuffmanNode> &nodes) {
    if (nodes[u].l == -1 && nodes[u].r == -1) {
        printf("%c: ", u + 'a');
        for (auto p : path) printf("%d", p);
        printf("\n");
        return;
    }
    path.push_back(0);
    dfs(path, nodes[u].l, nodes);
    path[path.size() - 1] = 1;
    dfs(path, nodes[u].r, nodes);
    path.pop_back();
    return;
}
int main () {
    std::ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    vector<int> character(26, 0);
    char getC;
    while (scanf("%c", &getC) == 1) {
        ++character[getC - 'a'];
    }
    vector<HuffmanNode> nodes;
    priority_queue<int, vector<int>, function<bool(int, int)>> q([&nodes](int l, int r){
        return nodes[l].frequency > nodes[r].frequency;
    });
    for (auto i : character) {
        if (!i) continue;
        nodes.emplace_back(i);
        q.push(static_cast<int>(nodes.size()) - 1);
    }
    while (q.size() > 1) {
        int lhs = q.top(); q.pop();
        int rhs = q.top(); q.pop();
        nodes.emplace_back(nodes[lhs].frequency + nodes[rhs].frequency, lhs, rhs);
        q.push(static_cast<int>(nodes.size()) - 1);
    }
    vector<int> path;
    int current = q.top();
    dfs(path, current, nodes);
    return 0;
}