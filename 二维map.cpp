�㷨�⡾ˮ����https://blog.csdn.net/feizaosyuacm/article/details/68937085
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string,map<string,int>> a;  //��άmap
map<string,map<string,int>>::iterator t1; //��ά������
map<string,int>::iterator t2;  //��ά������

int main()
{
    string fruit,place;
    int n,m,num;
    cin>>n;
    while(n--){
        cin>>m;
        while(m--){
            cin>>fruit>>place>>num;
            a[place][fruit] += num;
        }
        for(t1=a.begin();t1!=a.end();t1++){
            cout<<t1->first<<endl;
            for(t2=t1->second.begin();t2!=t1->second.end();t2++)
                cout<<"   |----"<<t2->first<<"("<<t2->second<<")"<<endl;
        }
        a.clear();   //��Ҫ ÿ�����
        if(n)
            printf("\n");
    }

    return 0;
}
