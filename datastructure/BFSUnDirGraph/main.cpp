#include <iostream>
#include <queue>
using namespace std;

class Graph {
private:
    int v;//顶点数量
    int** adjMatrix;//二维数组是表示矩阵
public:
    Graph(int v) {
        this->v=v;
        adjMatrix=new int*[v];
        for (int i=0;i<v;i++) {
            adjMatrix[i]=new int[v];
        }
        for (int i=0;i<v;i++) {
            for (int j=0;j<v;j++) {
                adjMatrix[i][j]=0;
            }//初始赋值为0，无向图没有任何边存在
        }
    }

    ~Graph() {
        for (int i=0;i<v;i++) {
            delete [] adjMatrix[i];
        }
        delete [] adjMatrix;
    }

    void addElem(int u,int v) {
        if (u>=this->v||v>=this->v||u<0||v<0) {
            throw out_of_range("Graph:addEdge():u or v out of range");
        }
        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;
    }

    void bfs(int start) {
        bool* visited=new bool[v];
        for (int i=0;i<v;i++) {
            visited[i]=false;
        }//所有元素均标记为未访问

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int u=q.front();
            q.pop();
            cout<<u<<" ";

            if (!visited[u]) {
                visited[u]=true;
                for (int i=0;i<v;i++) {
                    if (adjMatrix[u][i]==1&&!visited[i]) {
                        q.push(i);
                    }
                }
            }
        }delete [] visited;//queue在函数结束侯会自动销毁
    }
};

int main(){
    Graph g(5);
    g.addElem(0,4);
    g.addElem(3,4);
    g.addElem(2,1);
    g.addElem(2,3);
    g.addElem(1,3);
    g.addElem(4,2);
    g.bfs(3);
    cout<<endl;
    system("pause");
    return 0;
}