��hdu�� What Are You Talking About 
//������ʵ�ص����õ�STL���map���⣬������ס�ҵ�ȴ��getchar()
//���������������ֽ��ⷽʽ����ϸ��ע�ͣ�˵һ˵getchar()�ڴ����е�����
����һ��
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
//��Ҫ:����start֮���лس����س�ͣ���ڻ���������ȡ�ַ�ʱ���ȶ�ȡ����س�������Ҫgetchar();
    getchar();
    char buf[1024];
    char ch;
    int n = 0;
    while(scanf("%c",&ch)){
        if(isalpha(ch))
            buf[n++] = ch;  //��������һֱ����ĸ���Ͱ��������ĸ���ηŽ�buf
        else{
            buf[n] = '\0';  //������Ĳ�������ĸ���ͷŽ�ȥһ��������'\0'
            //strcmp: ��str1==str2���򷵻���;��str1<str2���򷵻ظ���;��str1>str2���򷵻�������
            if(strcmp(buf,"END")==0) break;  //�����ʱ��buf��END������ѭ�� ��Ϊ�õ��ַ���������Ҫ�õ�strcmp
            if(m.count(buf)!=0) //��map�в���buf�Ƿ�Ϊ�ؼ��� ����� �����buf��map�ж�Ӧ��ֵ(Ӣ��)
                cout<<m[buf];
            else cout<<buf;   //������ǹؼ��־�ֱ�����
            cout<<ch;   //����������ĸ���ַ�(�ո񣬻��У�tab�����...)
            n = 0;  //��n���µ���0 buf���¿�ʼ�����ַ�
            //��Ϊ������'\0'�����Լ�ʹbuf�����³�ʼ��Ҳû��ϵ����Ϊÿ�ζ�ȡ��'\0'�ͻ�ֹͣ
            //��Ȼ��û��ǳ�ʼ��һ��
        }
    }

    return 0;
}




��������
//�뷨һ�����ȱ�� ��ÿ�н�βû�б��������������
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
    //��Ϊ��һ��while������ͬʱ����eng��mar������������END�󲻻���������ѭ������������������ŵ�START��Ż�����
    getchar(); //���start���и��س��������getline���ȡ����������ڵĻس��������������ǵĵ�һ�����������Ҫgetchar()
    string line;
    while(getline(cin,line)&&line!="END"){  //��Ҫ: getline ����һ��֮��Ļس�����ŵ�������!!!
        string str = ""; //�൱��һ���մ�
        for(int i=0;i<line.size();i++){
            if(isalpha(line[i])) str += line[i]; //�������ĸ ������������str����
            else{
                if(m.find(str)!=m.end())  //��map��find��������str�Ƿ�Ϊһ����ֵ ����ֵ��һ�������� ���ص��Ǳ�����Ԫ�ص�λ�ã�û���򷵻�map.end()
                    cout<<m[str];
                else cout<<str;  //����Ϊһ����ֵ����ԭ�����
                cout<<line[i];  //����˴��Ĳ�Ϊ��ĸ���ַ� (ע�ⲻ��������)
                str = "";
            }
        }
        cout<<endl;  //�ֶ�����2333
    }

    return 0;
}
