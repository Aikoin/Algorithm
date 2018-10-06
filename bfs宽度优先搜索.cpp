#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

vector<int> E[110];  //邻接链表存图，每个点都有一个链表，用vector替代链表
queue<int> q;  //用队列存走过的点，符合先进先出
bool vis[110];  //记录已经走过的点，防止重复访问

void Bfs(int root,int n) //n个点的图 从root点开始搜索
{
    memset(vis,0,sizeof(vis));  //初始化
    vis[root] = 1;
    q.push(root);

    int u, len;

    while (!q.empty()) {  //当队列不为空
        u = q.front();  //u点每次保存队列最前面的点
        q.pop();       //删除最前面的点

        len = E[u].size();  //这个点有多少个相连的点

        for(int i=0;i<len;++i){  //找到所有和u相连的点，点已存在一个vector里
            if(vis[E[u][i]] == 0){
                vis[E[u][i]] = 1;
                q.push(E[u][i]);  //把新发现的点放进队列中
            }
        }
    }

    for(int i = 1;i<=n;++i){
        cout<<"vis["<<i<<"] = "<<vis[i]<<endl;  //打印 看是否已搜完所有点
    }
}

int main()
{
    //存图
    E[1].push_back(2);
    E[1].push_back(5);
    E[2].push_back(5);
    E[2].push_back(3);
    E[3].push_back(4);
    E[5].push_back(4);
    E[4].push_back(6);

    //bfs搜索
    Bfs(1,6);
}
