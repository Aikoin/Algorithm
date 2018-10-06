//set基础知识
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<int> s;
void setprint(int n){
    cout << "Test output :" << n << endl;
    for(set<int>::iterator t = s.begin(); t!= s.end(); t++)
        cout << *t << " ";
    puts("");
        return;
}

int main()
{
    int n = 0;
    for(int i=0;i<10;i++)
        s.insert(i);
    setprint(++n);

    s.erase(9);  //根据元素删除
    setprint(++n);

    set<int>::iterator t1,t2;
    t1 = t2 = s.begin();
    s.erase(t1);  //删除迭代器指向位置的元素
    setprint(++n);

    t1 = t2 = s.begin();
    t2++;t2++;
    s.erase(t1,t2);  //删除区间[ita,itb)的元素
    setprint(++n);

    s.clear();  //删除所有元素

    int a[4] = {11,12,13,14};
    s.insert(a,a+4);  //将区间[a, a+4]里的元素插入容器
    setprint(++n);

    //s.find() 查找一个元素，如果容器中不存在该元素，返回值等于s.end()
    if(s.find(2) != s.end())
        cout << "2 is existent" << endl;
    else
        cout << "2 is non-existent" << endl;
    //s.count(val) 返回容器中值等于 val 的元素的个数 0或1
    if(s.count(12))
        cout << "12 is existent" <<endl;
    if(!s.count(12))
        cout << "12 is non-existent" << endl;

    return 0;
}



//set运用(还用到了stringstream的知识)
//算法题 【Andy's First Dictionary 】
#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    string s,s2;
    set<string> a;
    while(cin>>s){
        for(int i=0;i<s.size();i++){
            if(isalpha(s[i])) s[i] = tolower(s[i]);
            else s[i] = ' ';
        }
        stringstream ss(s);
        while (ss>>s2)
            a.insert(s2);
//        ss.clear();
    }
    set<string>::iterator t;
    for(t=a.begin();t!=a.end();t++){
        cout<<*t<<endl;
    }

    return 0;
}

}




//算法题【Ugly Numbers】
//这题还可以用优先队列+set做
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long LL;
int ugly[3] = {2,3,5};
set<LL> a;

int main()
{
    LL x,t;
    a.insert(1);
    for(int i=1;;i++){
        x = *(a.begin());  //目前最小的丑数
        if(i==1500){
            printf("The 1500'th ugly number is %lld.\n",x);
            break;
        }
        for(int i=0;i<3;i++){
            t = x * ugly[i];  //生成新的丑数
            a.insert(t);   //重复元素不会被放进集合
        }
        a.erase(a.begin());  //每次删除最小的丑数
    }
    return 0;
}


