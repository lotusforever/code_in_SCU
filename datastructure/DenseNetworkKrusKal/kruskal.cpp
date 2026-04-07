#include <iostream>
#include <climits>

using namespace std;

// 边的结构：u, v, 权重 w
struct Edge {
    int u, v, w;
};

int parent[100], rank_[100];

void init_uf(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank_[i] = 0;
    }
}

int find(int x) {
    int root = x;
    while (root != parent[root]) {
        root = parent[root];
    }
    while (x != root) {
        int t = parent[x];
        parent[x] = root;
        x = t;
    }
    return root;
}

bool unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry) return false;
    // 小树挂大树
    if (rank_[rx] < rank_[ry]) {
        parent[rx] = ry;
    } else if (rank_[rx] > rank_[ry]) {
        parent[ry] = rx;
    } else {
        parent[ry] = rx;
        rank_[rx]++;
    }
    return true;
}

int main() {
    const int n = 5;
    const int INF = INT_MAX;

    // 邻接矩阵（5x5），初始化为 INF
    int graph[5][5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
        graph[i][i] = 0; // 自环为0
    }

    // 加边（无向图）
    graph[0][1] = graph[1][0] = 2;
    graph[0][3] = graph[3][0] = 6;
    graph[1][2] = graph[2][1] = 3;
    graph[1][3] = graph[3][1] = 8;
    graph[1][4] = graph[4][1] = 5;
    graph[2][4] = graph[4][2] = 7;
    graph[3][4] = graph[4][3] = 9;

    // 把所有有效边存进 edges 数组（只存上三角，避免重复）
    Edge edges[25]; // 最多 5*4/2 = 10 条，25 够用
    int edge_cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != INF) {
                edges[edge_cnt++] = {i, j, graph[i][j]};
            }
        }
    }

    // 手写插入排序（按 w 升序）
    for (int i = 1; i < edge_cnt; i++) {
        Edge tmp = edges[i];
        int j = i - 1;
        while (j >= 0 && edges[j].w > tmp.w) {
            edges[j + 1] = edges[j];
            j--;
        }
        edges[j + 1] = tmp;
    }

    // 开始 Kruskal：初始化并查集，选边
    init_uf(n);
    long long sum = 0;
    Edge mst[10]; // 存 MST 的边，最多 n-1=4 条
    int mst_cnt = 0;

    cout << "Kruskal 过程：\n";
    for (int i = 0; i < edge_cnt; i++) {
        Edge e = edges[i];
        if (unite(e.u, e.v)) {
            mst[mst_cnt++] = e;
            sum += e.w;
            cout << "选 (" << e.u << "," << e.v << ") 权 " << e.w << "\n";
            if (mst_cnt == n - 1) break;
        } else {
            cout << "跳 (" << e.u << "," << e.v << ") —— 会成环\n";
        }
    }

    // 输出结果
    cout << "\nMST 总权：" << sum << "\n";
    cout << "共 " << mst_cnt << " 条边：\n";
    for (int i = 0; i < mst_cnt; i++) {
        cout << "(" << mst[i].u << "," << mst[i].v << "," << mst[i].w << ")\n";
    }
    system("pause");
    return 0;
}