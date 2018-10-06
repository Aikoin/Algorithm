//此为存图方式的一种（终于学会了好开心！）
#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 1005;
const int MAXM = 10005; //边

struct node
{
    int to,next;
};

node Edge[MAXM];
int head[MAXN],cnt;  //head[i]表示节点i的第一条边

void init()  //初始化
{
    memset(head,-1,sizeof(head));
    cnt = 0;
}

void AddEdge1(int u,int v)  //起点u，终点v
{
    Edge[++cnt].to = v;  //这条边指向的节点
    Edge[cnt].next = head[u];  //同一个节点u指向的上一条边
    head[u] = cnt;  //节点u的第一条边为当前边
}

void AddEdge2(int u,int v){  //双向图
    AddEdge1(u,v);
    AddEdge1(v,u);
}

void Print()
{
    int st; //第st个节点
    cout<<"Begin with[Please input]: ";
    cin>>st;
    cout<<endl;
    for(int i = head[st];~i;i = Edge[i].next){ //开始为第一条边，每次指向该节点指向的下一条边 ~i可以理解为i!=-1
        cout<<"Start: "<<st<<endl;
        cout<<"End: "<<Edge[i].to<<endl;
        cout<<endl;
    }
}

int main()
{
    int u,v,n;
    init();
    cout<<"Please input the sum of the edge: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>u>>v;
        AddEdge2(u,v);
    }
    while(1){
        Print();
    }


    return 0;
}
