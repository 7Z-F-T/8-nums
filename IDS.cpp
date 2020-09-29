/*
这中间的状态记录把九宫格如下编号：
1 2 3
4 5 6
7 8 9
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int dep;//限制深度
int a[13];
int chai(int x)
{
    int ret;//记一下0在哪儿
    for(register int i=9;i>=1;--i)
    {
        if(x%10==0)ret=i;
        a[i]=x%10;
        x/=10;
    }
    return ret;
}

long long ans=123804765;//目标态

long long sub()//把拆开的压起来
{
    long long x=0;
    for(register int i=1;i<=9;++i)
    x=x*10+a[i];
    return x;
}
void ids(int p,int d,int bef)// p:0在哪儿 d：当前深度 bef:上一次的操作
{
    if(sub()==ans)
	{
		cout<<"从初始状态到目标状态需要的最少移动次数：";
		cout<<d-1<<endl;exit(0);
	}
    
	if(d>dep)
		return;//达到最大深度
   
	//mvup 把空格往上移
    if(p>3&&bef!=1)
	{
		swap(a[p-3],a[p]);
		dfs(p-3,d+1,3);
		swap(a[p-3],a[p]);
	}
   
	//mvdown 把空格往下
    if(p<7&&bef!=3)
	{
		swap(a[p+3],a[p]);
		dfs(p+3,d+1,1);
		swap(a[p+3],a[p]);
	}
   
	//mvleft 往左
    if(p%3!=1&&bef!=2)
	{
		swap(a[p-1],a[p]);
		dfs(p-1,d+1,4);
		swap(a[p-1],a[p]);
	}
   
	//mvright 往右
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
	cout << "请输入初始态：";
	cin>>x;
    dep=0;
    while(1)
    {
        ++dep;//迭代加深
        int p=chai(x);
        ids(p,1,0);
    }
    return 0;
}