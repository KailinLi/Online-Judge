#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
    int v1;
    int v2;
    Edge(int u, int v): v1(u), v2(v) {}
};
//使用了求二分图最大匹配的 匈牙利算法
bool Dfs(int u, vector<vector<int>> &G, vector<Edge> &E, vector<int> &road, vector<int> &matching) {
    for (auto i = G[u].begin(); i != G[u].end(); ++i) {
        int v = (E[*i].v1 == u) ? E[*i].v2 : E[*i].v1;
        if (!road[v]) {
            road[v] = 1;
            if (matching[v] == -1 || Dfs(matching[v], G, E, road, matching)) {
                matching[u] = v;    //翻转交叉路
                matching[v] = u;    //使匹配边比不匹配变多1
                return true;
            }
        }
    }
    return false;
}
int main () {
    int row, column;
    cin >> row >> column;
    vector<vector<int>>input(row, vector<int>(column));
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            int tmp;
            cin >> tmp;
            input[i][j] = tmp;
        }
    }
    vector<int>leftPoint;   //二分图左边点集
    vector<int>rightPoint;  //二分图右边点集
    vector<vector<int>>Graph(row * column);
    vector<Edge>edge;       //边的集合
    //构造图
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            if (!input[i][j]) continue; //该块缺失, 直接返回
            if ((i + j) % 2) leftPoint.push_back(i * column + j);
            else rightPoint.push_back(i * column + j);  //划分黑白格

            //只向右和向下构造, 避免重复
            //使用临接表
            if (j + 1 < column && input[i][j + 1]) {
                Graph[i * column + j].push_back(static_cast<int>(edge.size()));
                Graph[i * column + j + 1].push_back(static_cast<int>(edge.size()));
                edge.emplace_back(i * column + j, i * column + j + 1);
            }
            if (i + 1 < row && input[i + 1][j]) {
                Graph[i * column + j].push_back(static_cast<int>(edge.size()));
                Graph[(i + 1) * column + j].push_back(static_cast<int>(edge.size()));
                edge.emplace_back(i * column + j, (i + 1) * column + j);
            }
        }
    }
    
    if (leftPoint.size() != rightPoint.size()) {    //左右划分不等, 不可能成立
        cout << "No" << endl;
        return 0;
    }
    //计算最大匹配数和匹配情况
    int maxMatch = 0;
    vector<int> matching(row * column, -1);
    for (auto u = leftPoint.begin(); u != leftPoint.end(); ++u) {
        if (matching[*u] == -1) {
            vector<int>road(row * column, 0);
            if (Dfs(*u, Graph, edge, road, matching)) {
                ++maxMatch;
            }
        }
    }
    //满足覆盖时, 匹配数和左右点数必定相等
    if (maxMatch != leftPoint.size()) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for (int i = 0; i < matching.size(); ++i) {
        if (matching[i] != -1 && matching[i] > i) {
            cout << "(" << i << "," << matching[i] << ")" << endl;  //按照小方块从左往右从上往下的编号, 输出覆盖情况
        }
    }
}