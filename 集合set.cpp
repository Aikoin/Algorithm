//set����֪ʶ
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

    s.erase(9);  //����Ԫ��ɾ��
    setprint(++n);

    set<int>::iterator t1,t2;
    t1 = t2 = s.begin();
    s.erase(t1);  //ɾ��������ָ��λ�õ�Ԫ��
    setprint(++n);

    t1 = t2 = s.begin();
    t2++;t2++;
    s.erase(t1,t2);  //ɾ������[ita,itb)��Ԫ��
    setprint(++n);

    s.clear();  //ɾ������Ԫ��

    int a[4] = {11,12,13,14};
    s.insert(a,a+4);  //������[a, a+4]���Ԫ�ز�������
    setprint(++n);

    //s.find() ����һ��Ԫ�أ���������в����ڸ�Ԫ�أ�����ֵ����s.end()
    if(s.find(2) != s.end())
        cout << "2 is existent" << endl;
    else
        cout << "2 is non-existent" << endl;
    //s.count(val) ����������ֵ���� val ��Ԫ�صĸ��� 0��1
    if(s.count(12))
        cout << "12 is existent" <<endl;
    if(!s.count(12))
        cout << "12 is non-existent" << endl;

    return 0;
}



//set����(���õ���stringstream��֪ʶ)
//�㷨�� ��Andy's First Dictionary ��
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




//�㷨�⡾Ugly Numbers��
//���⻹���������ȶ���+set��
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
        x = *(a.begin());  //Ŀǰ��С�ĳ���
        if(i==1500){
            printf("The 1500'th ugly number is %lld.\n",x);
            break;
        }
        for(int i=0;i<3;i++){
            t = x * ugly[i];  //�����µĳ���
            a.insert(t);   //�ظ�Ԫ�ز��ᱻ�Ž�����
        }
        a.erase(a.begin());  //ÿ��ɾ����С�ĳ���
    }
    return 0;
}


