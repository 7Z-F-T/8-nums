/*
���м��״̬��¼�ѾŹ������±�ţ�
1 2 3
4 5 6
7 8 9
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int dep;//�������
int a[13];
int chai(int x)
{
    int ret;//��һ��0���Ķ�
    for(register int i=9;i>=1;--i)
    {
        if(x%10==0)ret=i;
        a[i]=x%10;
        x/=10;
    }
    return ret;
}

long long ans=123804765;//Ŀ��̬

long long sub()//�Ѳ𿪵�ѹ����
{
    long long x=0;
    for(register int i=1;i<=9;++i)
    x=x*10+a[i];
    return x;
}
void ids(int p,int d,int bef)// p:0���Ķ� d����ǰ��� bef:��һ�εĲ���
{
    if(sub()==ans)
	{
		cout<<"�ӳ�ʼ״̬��Ŀ��״̬��Ҫ�������ƶ�������";
		cout<<d-1<<endl;exit(0);
	}
    
	if(d>dep)
		return;//�ﵽ������
   
	//mvup �ѿո�������
    if(p>3&&bef!=1)
	{
		swap(a[p-3],a[p]);
		dfs(p-3,d+1,3);
		swap(a[p-3],a[p]);
	}
   
	//mvdown �ѿո�����
    if(p<7&&bef!=3)
	{
		swap(a[p+3],a[p]);
		dfs(p+3,d+1,1);
		swap(a[p+3],a[p]);
	}
   
	//mvleft ����
    if(p%3!=1&&bef!=2)
	{
		swap(a[p-1],a[p]);
		dfs(p-1,d+1,4);
		swap(a[p-1],a[p]);
	}
   
	//mvright ����
    if(p%3!=0&&bef!=4)
	{
		swap(a[p+1],a[p]);
		dfs(p+1,d+1,2);
		swap(a[p+1],a[p]);
	}
}
int main()
{
    //freopen("a.in","r",stdin);
    long long x;
	cout << "�������ʼ̬��";
	cin>>x;
    dep=0;
    while(1)
    {
        ++dep;//��������
        int p=chai(x);
        ids(p,1,0);
    }
    return 0;
}