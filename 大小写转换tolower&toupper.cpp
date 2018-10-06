//������һ��C����demo

#include <stdio.h>  //printf
#include <string.h> //strlen
//#include <ctype.h>  //tolower

int tolower(int c)   //��дת����Сд
{
    if((c>='A')&&(c<='Z'))
            return c+('a'-'A');
    return c;
}

int toupper(int c)  //Сдת���ɴ�д
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


//������C++demo

//��һ�����ÿ⺯��  toupper��tolower��C++�ж���ֱ���std��cctype�� 
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



//����������STL��transform()����
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s = "this IS A STRING";
    cout<<s<<endl;   
//  ����C�汾��toupper/tolower����,����STLģ�庯��toupper/tolower�����ߴ��ڳ�ͻ��
    transform(s.begin(),s.end(),s.begin(),::tolower);  //��toupper/tolowerǰ���::��ǿ��ָ����C�汾��
    cout<<s<<endl;
    for(auto &str : s)
        str = ::toupper(str);
    cout<<s<<endl;
    return 0;
}

#if 0
transform����
�����ǣ���ĳ����Ӧ����ָ����Χ��ÿ��Ԫ�ء�
transform�������������ذ汾��
transform(first,last,result,op);//first���������׵�������lastΪ������ĩ��������resultΪ��Ž����������opΪҪ���в�����һԪ���������sturct��class��
transform(first1,last1,first2,result,binary_op);//first1�ǵ�һ���������׵�������last1Ϊ��һ��������ĩ��������first2Ϊ�ڶ����������׵�������resultΪ��Ž����������binary_opΪҪ���в����Ķ�Ԫ���������sturct��class
#endif

