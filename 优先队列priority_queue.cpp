//算法题 【Ugly Numbers】
//还用到了set集合的知识，这题如果只用set做也很简单
#include <iostream>
#include <vector>
#include <set>  //用集合判重
#include <queue>  //优先队列
#include <algorithm>
using namespace std;

typedef long long LL;  //简化代码 注意这里一定要用long long不能用int
int ugly[3] = {2,3,5};
set<LL> a;
priority_queue<LL,vector<LL>,greater<LL>> q; //从小到大

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
            t = x * ugly[i];  //生成新的丑数
            if(a.count(t)==0){  //未出现过则放入队列
                a.insert(t);
                q.push(t);
            }
        }
        q.pop();
    }
    return 0;
}





//算法题 【Windows Message Queue 】
#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

struct node
{
    char mes[10];
    int x,y;  //x为消息的参数 y为消息的优先值
    bool operator <(const node& a) const{   //这里的函数名后必须要加const 记住就好
        return y>a.y;  //比较它们的优先值y，y越大优先级越低
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