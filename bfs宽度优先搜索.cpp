#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

vector<int> E[110];  //�ڽ������ͼ��ÿ���㶼��һ��������vector�������
queue<int> q;  //�ö��д��߹��ĵ㣬�����Ƚ��ȳ�
bool vis[110];  //��¼�Ѿ��߹��ĵ㣬��ֹ�ظ�����

void Bfs(int root,int n) //n�����ͼ ��root�㿪ʼ����
{
    memset(vis,0,sizeof(vis));  //��ʼ��
    vis[root] = 1;
    q.push(root);

    int u, len;

    while (!q.empty()) {  //�����в�Ϊ��
        u = q.front();  //u��ÿ�α��������ǰ��ĵ�
        q.pop();       //ɾ����ǰ��ĵ�

        len = E[u].size();  //������ж��ٸ������ĵ�

        for(int i=0;i<len;++i){  //�ҵ����к�u�����ĵ㣬���Ѵ���һ��vector��
            if(vis[E[u][i]] == 0){
                vis[E[u][i]] = 1;
                q.push(E[u][i]);  //���·��ֵĵ�Ž�������
            }
        }
    }

    for(int i = 1;i<=n;++i){
        cout<<"vis["<<i<<"] = "<<vis[i]<<endl;  //��ӡ ���Ƿ����������е�
    }
}

int main()
{
    //��ͼ
    E[1].push_back(2);
    E[1].push_back(5);
    E[2].push_back(5);
    E[2].push_back(3);
    E[3].push_back(4);
    E[5].push_back(4);
    E[4].push_back(6);

    //bfs����
    Bfs(1,6);
}
