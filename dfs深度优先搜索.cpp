//用函数递归实现的dfs
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> E[110];  //用来存图
bool vis[110];  //记录已经走过的点，防止重复访问

//需要一个栈，符合后进先出 但一般不用栈，直接通过函数递归即可
void Dfs(int u)
{
    vis[u] = 1;
    int len = E[u].size();
    for(int i = 0;i<len;++i){
        if(vis[E[u][i]] == 0)
            Dfs(E[u][i]);
    }
}

int main()
{
    memset(vis,0,sizeof(vis));  //初始化
    //存图
    E[1].push_back(2);
    E[1].push_back(5);
    E[2].push_back(3);
    E[2].push_back(5);
    E[3].push_back(4);
    E[5].push_back(4);
    E[4].push_back(6);

    //dfs搜索
    Dfs(1);

    return 0;
}




//用栈实现的dfs
#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;

vector<int> E[110];
stack<int> s;
bool vis[110];
bool is_push;

void dfs(int u)  //用栈实现的dfs
{
    vis[u] = 1;
    s.push(u);
    while (!s.empty()) {
        is_push = false;
        u = s.top();
        int len = E[u].size();
        for(int i = 0;i<len;++i){
            if(vis[E[u][i]] == 0){
                vis[E[u][i]] = 1;
                s.push(E[u][i]);
                is_push = true;
                break;
            }
        }
        if(!is_push)  //is_push为false时执行语句
            s.pop();
    }
}

int main()
{
    memset(vis,0,sizeof(vis));  //初始化
    //存图
    E[1].push_back(2);
    E[1].push_back(5);
    E[2].push_back(3);
    E[2].push_back(5);
    E[3].push_back(4);
    E[5].push_back(4);
    E[4].push_back(6);

    //dfs搜索
    dfs(1);

    return 0;
}

