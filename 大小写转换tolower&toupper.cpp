//下面是一个C语言demo

#include <stdio.h>  //printf
#include <string.h> //strlen
//#include <ctype.h>  //tolower

int tolower(int c)   //大写转换成小写
{
    if((c>='A')&&(c<='Z'))
            return c+('a'-'A');
    return c;
}

int toupper(int c)  //小写转换成大写
{
    if((c>='a')&&(c<='z'))
        return c+('A'-'a');
    return c;
}

int main()
{
    int i;
    char s[] = "THIS IS A STRING";
    printf("%s\n",s);
    for(i=0;i<strlen(s);i++)
        s[i] = tolower(s[i]);
    printf("%s\n",s);
    printf("\n");

    return 0;
}


//下面是C++demo

//法一：利用库函数  toupper和tolower在C++中定义分别在std和cctype中 
#include <iostream>
#include <string>
#include <cctype>  //tolower
using namespace std;

int main()
{
    string s = "THIS IS A STRING";
    cout<<s<<endl;
    for(int i=0;i<s.size();i++)
        s[i] = tolower(s[i]);
    cout<<s<<endl;
    return 0;
}



//法二：利用STL的transform()函数
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s = "this IS A STRING";
    cout<<s<<endl;   
//  既有C版本的toupper/tolower函数,又有STL模板函数toupper/tolower，二者存在冲突。
    transform(s.begin(),s.end(),s.begin(),::tolower);  //在toupper/tolower前面加::，强制指定是C版本的
    cout<<s<<endl;
    for(auto &str : s)
        str = ::toupper(str);
    cout<<s<<endl;
    return 0;
}

#if 0
transform函数
作用是：将某操作应用于指定范围的每个元素。
transform函数有两个重载版本：
transform(first,last,result,op);//first是容器的首迭代器，last为容器的末迭代器，result为存放结果的容器，op为要进行操作的一元函数对象或sturct、class。
transform(first1,last1,first2,result,binary_op);//first1是第一个容器的首迭代器，last1为第一个容器的末迭代器，first2为第二个容器的首迭代器，result为存放结果的容器，binary_op为要进行操作的二元函数对象或sturct、class
#endif

