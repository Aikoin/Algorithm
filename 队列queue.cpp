算法题 【Team Queue 】
//用到了queue和map
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int t,kase = 0;
    while(cin>>t&&t!=0){  //队伍个数
        printf("Scenario #%d\n",++kase);
        int n,x;
        map<int,int> team;  //team[x]表示编号为x的人所在的团队编号
        for(int i = 0;i<t;i++){
            cin>>n;  //队伍中元素个数
            while(n--){
                cin>>x; //元素
                team[x] = i; //元素x对应队伍编号i
            }
        }
        string com;
        queue<int> q,q2[1005];  //q是团队的队列，而q2[i]是团队i成员的队列
        while(1){
            cin>>com;
            if(com == "ENQUEUE"){
                cin>>x;
                int t = team[x]; //元素x对应的队伍编号
                if(q2[t].empty()) q.push(t);
                q2[t].push(x);
            }
            else if(com == "DEQUEUE"){
                int t = q.front();
                cout<<q2[t].front()<<endl;
                q2[t].pop();
                if(q2[t].empty()) q.pop();
            }
            else if(com == "STOP") break;
        }
        printf("\n");
    }

    return 0;
}
