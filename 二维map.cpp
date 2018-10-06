算法题【水果】https://blog.csdn.net/feizaosyuacm/article/details/68937085
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string,map<string,int>> a;  //二维map
map<string,map<string,int>>::iterator t1; //外维迭代器
map<string,int>::iterator t2;  //内维迭代器

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
        a.clear();   //重要 每次清空
        if(n)
            printf("\n");
    }

    return 0;
}
