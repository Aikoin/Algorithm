//�㷨�� ��Ugly Numbers��
//���õ���set���ϵ�֪ʶ���������ֻ��set��Ҳ�ܼ�
#include <iostream>
#include <vector>
#include <set>  //�ü�������
#include <queue>  //���ȶ���
#include <algorithm>
using namespace std;

typedef long long LL;  //�򻯴��� ע������һ��Ҫ��long long������int
int ugly[3] = {2,3,5};
set<LL> a;
priority_queue<LL,vector<LL>,greater<LL>> q; //��С����

int main()
{
    LL x,t;
    a.insert(1);
    q.push(1);
    for(int i=1;;i++){
        x = q.top();
        if(i==1500){
            printf("The 1500'th ugly number is %lld.\n",x);
            break;
        }
        for(int i=0;i<3;i++){
            t = x * ugly[i];  //�����µĳ���
            if(a.count(t)==0){  //δ���ֹ���������
                a.insert(t);
                q.push(t);
            }
        }
        q.pop();
    }
    return 0;
}





//�㷨�� ��Windows Message Queue ��
#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
    char mes[10];
    int x,y;  //xΪ��Ϣ�Ĳ��� yΪ��Ϣ������ֵ
    bool operator <(const node& a) const{   //����ĺ����������Ҫ��const ��ס�ͺ�
        return y>a.y;  //�Ƚ����ǵ�����ֵy��yԽ�����ȼ�Խ��
    }
};

int main()
{
    priority_queue<node> q;
    node a;
    string com;
    while(cin>>com){
        if(com == "PUT"){
            scanf("%s%d%d",a.mes,&a.x,&a.y);
            q.push(a);
        }
        else{
            if(q.empty()) cout<<"EMPTY QUEUE!"<<endl;
            else{
                printf("%s %d\n",q.top().mes,q.top().x);
                q.pop();
            }
        }
    }
    return 0;
}