#include <iostream>
#include "node.h"
#include "linkstack.h"
using namespace std;

const int Rows = 10;
const int Cols = 10;

int Maze[10][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
                    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
                    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
                    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int r[] = {0, 0, -1, 1};
int c[] = {-1, 1, 0, 0};//探索方向

struct MazePos
{
    int row, col;
    MazePos *parent;
    MazePos(int r, int c, MazePos *p = nullptr) : row(r), col(c), parent(p) {};
}; // 传入节点

bool isAcess(int r, int c,bool visited[Rows][Cols]){
    if(r<0||r>=10||c<0||c>=10){
        return false;
    }
    if(visited[r][c]){
        return false;
    }
    if(Maze[r][c]==1){
        return false;
    }
    return true;
}

bool findPath(int startRow,int startCol,int endRow,int endCol){
    bool visited[Rows][Cols] = {false};//初始化将所有的路径点都标记为未访问过；

    LinkStack<MazePos *> ms;
    MazePos *start = new MazePos(startRow, startCol);
    ms.Push(start);
    visited[startRow][startCol] = true;//设置起点

    while(!ms.Empty()){
        MazePos *cur;
        ms.Pop(cur);
        for (int i = 0; i < 4; i++)
        {
            int nr = cur->row + r[i];
            int nc = cur->col + c[i];
            if(isAcess(nr,nc,visited)){
                visited[nr][nc] = true;
                MazePos *next = new MazePos(nr, nc, cur);
                ms.Push(next);
            }
        }
        if (cur->row == endRow && cur->col == endCol)
        {
            cout << "找到路径：" << endl;
            MazePos *path[Rows * Cols]; // 最终路径最多这么多
            int pathLen = 0;
            while (cur != nullptr)
            {
                path[pathLen++] = cur;
                cur = cur->parent;
            }
            for (int i = pathLen - 1; i >= 0;i--){
                cout << '(' << path[i]->row << ',' << path[i]->col << ')'<<' ';
            }//输出路径
            cout << endl;
            for (int i = 0; i < pathLen;i++){
                delete path[i];
            }
            while(!ms.Empty()){
                ms.Clear();
            }//输出路径后释放内存
            return true;
        } // 判断是否找到终点
    }
    cout << "无解！" << endl;
    return false;
}

int main()
{
    findPath(1, 1, 8, 8);

    return 0;
}