�㷨�� ��Team Queue ��
//�õ���queue��map
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int t,kase = 0;
    while(cin>>t&&t!=0){  //�������
        printf("Scenario #%d\n",++kase);
        int n,x;
        map<int,int> team;  //team[x]��ʾ���Ϊx�������ڵ��Ŷӱ��
        for(int i = 0;i<t;i++){
            cin>>n;  //������Ԫ�ظ���
            while(n--){
                cin>>x; //Ԫ��
                team[x] = i; //Ԫ��x��Ӧ������i
            }
        }
        string com;
        queue<int> q,q2[1005];  //q���ŶӵĶ��У���q2[i]���Ŷ�i��Ա�Ķ���
        while(1){
            cin>>com;
            if(com == "ENQUEUE"){
                cin>>x;
                int t = team[x]; //Ԫ��x��Ӧ�Ķ�����
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
