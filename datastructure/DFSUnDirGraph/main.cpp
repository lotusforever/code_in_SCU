#include <iostream>
#include <stack>
using namespace std;

class Graph {
private:
    int vex;
    int** adjMatrix;
public:
    Graph(int vex) {
        this->vex=vex;
        adjMatrix = new int*[vex];
        for (int i=0;i<vex;i++) {
            adjMatrix[i]=new int[vex];
        }
        for (int i=0;i<vex;i++) {
            for (int j=0;j<vex;j++) {
                adjMatrix[i][j]=0;
            }
        }//初始化邻接矩阵赋值为0
    }

    ~Graph() {
        for (int i=0;i<vex;i++) {
            delete [] adjMatrix[i];
        }//释放每一行的内存
        delete [] adjMatrix;//释放指针数组的内存
    }

    void addEdge(int u,int v) {
        if (u>=vex||v>=vex||u<0||v<0) {
            throw out_of_range("Graph:addEdge():u or v out of range");
        }
        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;//无向图的邻接矩阵是对称矩阵
    }

    void dfs(int start) {
        bool* visited=new bool[vex];
        for (int i=0;i<vex;i++) {
            visited[i]=false;//初始化表示所有顶点均未访问；
        }

        stack<int> nodeStack;
        nodeStack.push(start);
        cout<<"从顶点"<<start<<"开始DFS深度搜索:"<<endl;
        while (!nodeStack.empty()) {
            int node=nodeStack.top();
            nodeStack.pop();

            if (!visited[node]) {
                visited[node]=true;
                cout<<node<<" ";
                for (int i=vex-1;i>=0;i--) {
                    if (adjMatrix[node][i]==1&&!visited[i]) {
                        nodeStack.push(i);
                    }
                }
            }
        }

    }
};

int main() {
    Graph g(5);

    // 添加边
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.dfs(0);
    cout<<endl;
    system("pause");
    return 0;
}