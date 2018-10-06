#include<iostream>
#include <map>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    char col[20];
    while(cin>>n)
    {
        if(n==0) break;
        map<string,int> balloons;
        for (int i=0;i<n;i++)
        {
            cin>>col;
            balloons[col]++;
        }
        map<string,int>::iterator p,m;
        p=m=balloons.begin();
        for (p;p!=balloons.end();p++)
        {
            if(p->second > m->second) m=p;
        }
        cout<<m->first<<endl;
    }
}



//算法题 【Ananagrams】   经典！！！
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string trans(const string& str){
    string s = str;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    sort(s.begin(),s.end());
    return s;
}

int main()
{
    string s1;
    vector<string> word;
    map<string,int> m;
    while(cin>>s1){
        if(s1[0]=='#') break;
        word.push_back(s1);
        string s2 = trans(s1);
        m[s2]++;  //若只出现过一次则值为1 若多次则起码为2
    }
    vector<string> result;
    for(int i=0;i<word.size();i++){
        if(m[trans(word[i])]==1) result.push_back(word[i]);  
    }
    sort(result.begin(),result.end());
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

    return 0;
}



//算法题 【Misha and Changing Handles】
【法一】 //我自己的ac代码
#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string,string> m; //old new
    map<string,string>::iterator t;
    string old,ne;
    int q;
    while(cin>>q){
        for(int i=0;i<q;i++){
            cin>>old>>ne;
            m[old] = ne;
            for(t=m.begin();t!=m.end();t++){
                if(old==t->second){  //如果此次输入的旧id是之前换过的新id
                    t->second = ne;  //就用这次输入的新id换掉之前换的新id
                    m.erase(old);    //把这组old-new删去
                }
            }
        }
        int s = m.size();
        cout<<s<<endl;
        for(t=m.begin();t!=m.end();t++){
            cout<<t->first<<" "<<t->second<<endl;
        }
    }
    return 0;
}

【法二】//别人的，也很简洁，值得参考
#include <iostream>
#include <map>
using namespace std;

int main(){
    map <string, string> mp;  //new old
    int q;
    cin >> q;
    while(q--){
        string str1,str2;  //old new
        cin >> str1 >> str2;
        //如果旧名字不存在，那么直接将这一对存储在map中
        if(mp.find(str1) == mp.end()){
            mp[str2] = str1;
        }
        //如果旧名字存在，那么将当前的新名字和旧名字所对应的更旧的名字作为一对存储在map中
        else{
            mp[str2] = mp[str1];
            mp.erase(str1);
        }
    }
    //遍历输出
    int cont = mp.size();
    cout << cont << endl;
    for(map<string,string>::iterator it = mp.begin();it != mp.end(); it++){
        cout << it->second << " " << it->first << endl;
    }    
    return 0;
}


