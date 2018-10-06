//��Ϊ��ͼ��ʽ��һ�֣�����ѧ���˺ÿ��ģ���
#include <iostream>
#include <string.h>
using namespace std;
const int MAXN = 1005;
const int MAXM = 10005; //��

struct node
{
    int to,next;
};

node Edge[MAXM];
int head[MAXN],cnt;  //head[i]��ʾ�ڵ�i�ĵ�һ����

void init()  //��ʼ��
{
    memset(head,-1,sizeof(head));
    cnt = 0;
}

void AddEdge1(int u,int v)  //���u���յ�v
{
    Edge[++cnt].to = v;  //������ָ��Ľڵ�
    Edge[cnt].next = head[u];  //ͬһ���ڵ�uָ�����һ����
    head[u] = cnt;  //�ڵ�u�ĵ�һ����Ϊ��ǰ��
}

void AddEdge2(int u,int v){  //˫��ͼ
    AddEdge1(u,v);
    AddEdge1(v,u);
}

void Print()
{
    int st; //��st���ڵ�
    cout<<"Begin with[Please input]: ";
    cin>>st;
    cout<<endl;
    for(int i = head[st];~i;i = Edge[i].next){ //��ʼΪ��һ���ߣ�ÿ��ָ��ýڵ�ָ�����һ���� ~i�������Ϊi!=-1
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
