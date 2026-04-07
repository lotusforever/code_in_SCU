#include <iostream>
#include <string>
#include <climits>
using namespace std;

struct Edge {
    int u,v,w;
    Edge(int u0,int v0,int w0):u(u0),v(v0),w(w0){}
    Edge() {
        u = v = w = 0;
    }
};

void prim(int n,int** graph,long long& total_weight,Edge*& mst_edges,int & mst_edge_count) {
    bool* visited=new bool[n];//顶点i是否已经加入mst中；
    int* minDist=new int[n];//表示从当前已选集合到i的最小权
    int* parent=new int[n];//记忆谁将i加入生成树的，方便后续书橱生成树

    for (int i=0;i<n;i++) {
        visited[i]=false;
        minDist[i]=INT_MAX;//在c++中INT_MAX是int能表示的最大值，用于表示无穷表示两个顶点之间不可达
        parent[i]=-1;
    }
    minDist[0]=0;

    total_weight=0;
    mst_edge_count=0;
    mst_edges=new Edge[n];

    cout<<"初始状态："<<endl;
    cout<<"visited=";
    for (int i=0;i<n;i++) {
        cout<<(visited[i]==true?"T":"F");
    }cout<<endl;
    cout<<"minDist=";
    for (int i=0;i<n;i++) {
        if (minDist[i] == INT_MAX) cout << "INF ";
        else cout << minDist[i] << " ";
    }cout<<endl;

    for (int r=0;r<n;r++) {
        int u=-1;
        for (int i=0;i<n;i++) {
            if (!visited[i]) {
                if (u==-1||minDist[i]<minDist[u]) { // 修正：使用比较而非赋值
                    u=i;
                }
            }
        }

        if (u==-1||minDist[u]==INT_MAX) {
            delete[] visited;
            delete[] minDist;
            delete[] parent;
            delete[] mst_edges;
            exit(1);
        }

        visited[u]=true;
        total_weight+=minDist[u];

        if (parent[u]!=-1) {
            int a=u<parent[u]?u:parent[u];
            int b=u>parent[u]?u:parent[u];
            mst_edges[mst_edge_count]=Edge(a,b,minDist[u]);
            mst_edge_count++;
        }

        for (int v=0;v<n;v++) {
            if (!visited[v]&&graph[u][v]!=INT_MAX) {
                if (graph[u][v]<minDist[v]) {
                    minDist[v]=graph[u][v];
                    parent[v]=u;
                }
            }
        }

        cout << "  当前 visited: ";
        for (int i = 0; i < n; i++) cout << (visited[i] ? "T" : "F") << " ";
        cout << "\n  当前 minDist: ";
        for (int i = 0; i < n; i++) {
            if (minDist[i] == INT_MAX) cout << "INF ";
            else cout << minDist[i] << " ";
        }
        cout << "\n\n";

    }

    // 在循环结束后再释放辅助数组，避免在循环中提前释放导致的访问冲突
    delete[] visited;
    delete[] minDist;
    delete[] parent;
}

int** build_graph(int n) {
    int** g=new int*[n];
    for (int i=0;i<n;i++) {
        g[i]=new int[n];
        for (int j=0;j<n;j++) {
            g[i][j]=INT_MAX;
        }
        g[i][i]=0;
    }return g;
}

void free_graph(int** g,int n) {
    for (int i=0;i<n;i++) {
        delete[] g[i];
    }
    delete[] g;
}

int main() {
    const int n = 5;

    int** graph = build_graph(n);

    // 添加边：0-1(2), 0-3(6), 1-2(3), 1-3(8), 1-4(5), 2-4(7), 3-4(9)
    auto add = [&](int u, int v, int w) {
        graph[u][v] = w;
        graph[v][u] = w;
    };
    add(0,1,2); add(0,3,6);
    add(1,2,3); add(1,3,8); add(1,4,5);
    add(2,4,7); add(3,4,9);

    long long total_weight;
    Edge* mst_edges = nullptr;
    int mst_edge_count = 0;

    prim(n, graph, total_weight, mst_edges, mst_edge_count);

    cout << "MST 总权重：" << total_weight << "\n";
    cout << "MST 包含以下 " << mst_edge_count << " 条边：\n";
    for (int i = 0; i < mst_edge_count; i++) {
        cout << "  [" << (i + 1) << "] (" << mst_edges[i].u << ", "
             << mst_edges[i].v << ", " << mst_edges[i].w << ")\n";
    }

    delete[] mst_edges;
    free_graph(graph, n);
    system("pause");

    return 0;
}