//�ú����ݹ�ʵ�ֵ�dfs
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> E[110];  //������ͼ
bool vis[110];  //��¼�Ѿ��߹��ĵ㣬��ֹ�ظ�����

//��Ҫһ��ջ�����Ϻ���ȳ� ��һ�㲻��ջ��ֱ��ͨ�������ݹ鼴��
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
    memset(vis,0,sizeof(vis));  //��ʼ��
    //��ͼ
    E[1].push_back(2);
    E[1].push_back(5);
    E[2].push_back(3);
    E[2].push_back(5);
    E[3].push_back(4);
    E[5].push_back(4);
    E[4].push_back(6);

    //dfs����
    Dfs(1);

    return 0;
}




//��ջʵ�ֵ�dfs
#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;

vector<int> E[110];
stack<int> s;
bool vis[110];
bool is_push;

void dfs(int u)  //��ջʵ�ֵ�dfs
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
        if(!is_push)  //is_pushΪfalseʱִ�����
            s.pop();
    }
}

int main()
{
    memset(vis,0,sizeof(vis));  //��ʼ��
    //��ͼ
    E[1].push_back(2);
    E[1].push_back(5);
    E[2].push_back(3);
    E[2].push_back(5);
    E[3].push_back(4);
    E[5].push_back(4);
    E[4].push_back(6);

    //dfs����
    dfs(1);

    return 0;
}

