【hdu】 What Are You Talking About 
//这题其实重点是用到STL里的map解题，但是难住我的却是getchar()
//所以在这里用两种解题方式和详细的注释，说一说getchar()在代码中的作用
【法一】
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    string start,eng,mar;
    map<string,string> m;
    cin>>start;
    while(cin>>eng&&eng!="END"){
        cin>>mar;
        m[mar] = eng;
    }
    cin>>start;
//重要:输入start之后有回车，回车停留在缓冲区，读取字符时会先读取这个回车，所以要getchar();
    getchar();
    char buf[1024];
    char ch;
    int n = 0;
    while(scanf("%c",&ch)){
        if(isalpha(ch))
            buf[n++] = ch;  //如果输入的一直是字母，就把输入的字母依次放进buf
        else{
            buf[n] = '\0';  //当输入的不再是字母，就放进去一个结束符'\0'
            //strcmp: 若str1==str2，则返回零;若str1<str2，则返回负数;若str1>str2，则返回正数。
            if(strcmp(buf,"END")==0) break;  //如果此时的buf是END即结束循环 因为用的字符数组所以要用到strcmp
            if(m.count(buf)!=0) //在map中查找buf是否为关键字 如果是 就输出buf在map中对应的值(英文)
                cout<<m[buf];
            else cout<<buf;   //如果不是关键字就直接输出
            cout<<ch;   //输出这个非字母的字符(空格，换行，tab，标点...)
            n = 0;  //让n重新等于0 buf重新开始储存字符
            //因为会遇到'\0'，所以即使buf不重新初始化也没关系，因为每次读取到'\0'就会停止
            //当然最好还是初始化一下
        }
    }

    return 0;
}




【法二】
//与法一相比有缺陷 若每行结尾没有标点符号则输出错误
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    string start,eng,mar;
    map<string,string> m;
    cin>>start;
    while(cin>>eng>>mar&&eng!="END"){
        m[mar] = eng;
    }
    //因为第一个while里面是同时输入eng和mar，所以在输入END后不会立即跳出循环，而是在输出紧接着的START后才会跳出
    getchar(); //输出start后有个回车，下面的getline会读取这个缓冲区内的回车，把它当作我们的第一个输出，所以要getchar()
    string line;
    while(getline(cin,line)&&line!="END"){  //重要: getline 敲完一行之后的回车不会放到缓冲区!!!
        string str = ""; //相当于一个空串
        for(int i=0;i<line.size();i++){
            if(isalpha(line[i])) str += line[i]; //如果是字母 就依次连接在str后面
            else{
                if(m.find(str)!=m.end())  //用map的find函数查找str是否为一个键值 返回值是一个迭代器 返回的是被查找元素的位置，没有则返回map.end()
                    cout<<m[str];
                else cout<<str;  //若不为一个键值，则原样输出
                cout<<line[i];  //输出此处的不为字母的字符 (注意不包含换行)
                str = "";
            }
        }
        cout<<endl;  //手动换行2333
    }

    return 0;
}
