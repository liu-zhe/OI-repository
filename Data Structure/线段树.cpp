#include <iostream>

using namespace std;

#define root 1,n,1
#define lson l,m,rt*2
#define rson m+1,r,rt*2+1
#define now_node l,r,rt

const int maxn=100005;
long long m,n,z[maxn*4]={0},flag[maxn*4]={0};

void update(int rt)
{
	z[rt] = z[rt*2] + z[rt*2+1];	//我们的线段是处理区间和的，所以我们写了“+”；
}

void build(int l, int r,int rt) //建立一棵线段树
{
	if(l == r)		//当左端点=右端点时，就表示它是一个叶子节点，这时我们就给它赋值
	{
		int v;
		cin>>v;
		z[rt]=v;
		return;
	}
	int m=(l+r)/2;		//二分当前区间
	build(lson);		//左边一段作为左子树，递归建立左子树
	build(rson);		//右边一段作为右子树，递归建立右子树
	update(rt);		//将左右子树的修改应用于当前节点
}

void add(int l,int r,int rt,int v)      //给l～r 编号为rt的区间加上v，同时打标记
{
	z[rt] += (r-l+1) * v;
	flag[rt] += v;               //给它打一个v，为避免覆盖，这里是+=
}

void push_down(int l,int r,int rt)      //在询问时，把标记下放
{
	if(flag[rt] != 0)
	{
		int m=(l+r)/2;
		add(lson,flag[rt]);  //打左儿子
		add(rson,flag[rt]);  //打右儿子 233
		flag[rt]=0;       //标记清零
	}
}

void modify(int l,int r,int rt,int findl,int findr,long long v) //修改findl~findr区间的值，把它们都加上v
{
	if(findl==l && r==findr) 			//将区间的修改应用于它的每一个子节点
	{
		add(now_node,v);
		return;
	}
	push_down(now_node);
	int m=(l+r)/2;			//二分当前区间
	if(findl<=m)			//要修改的区间在左子树上
	{
		if(m<findr)		//特判：要改的区间贯穿左右子树
		{
			modify(lson,findl,m,v);		//在左子树上改findl~m这段
			modify(rson,m+1,findr,v);	//在右子树上改m+1~findr这段
		}
		else modify(lson,findl,findr,v);
	}
	else modify(rson,findl,findr,v);		//要找的区间在右子树上
	update(rt);
}

long long query(int l,int r,int rt,int findl,int findr)		//询问某段区间的和 findl表示要询问的区间的左端点，findr表示要询问的区间的右端点
{
	if(findl==l && r==findr) return z[rt];		//当前端点等于要找的端点时 返回
	push_down(now_node);
	int m=(l+r)/2;			//二分当前区间
	if(findl<=m)			//要找的区间在左子树上
	{
		if(m<findr) return query(lson,findl,m)+query(rson,m+1,findr);	//特判：要找的区间贯穿左右子树
		else return query(lson,findl,findr);
	}
	else return query(rson,findl,findr);	//要找的区间在右子树上
}

int main()
{
	cin>>n>>m;       	//线段树区间的长度为n，有次操作
	build(root); 		//从根结点开始建立线段树

	for(int i=1;i<=m;i++)
	{
		int cmd;
		cin>>cmd;
		switch(cmd)
		{
			case 1:			//修改线段树节点值
			int findl,findr;
			long long v;
			cin>>findl>>findr>>v;
			modify(root,findl,findr,v); 	//从根结点递归修改
			break;

			case 2:			//询问线段树l~r区间的和
			int l,r;
			cin>>l>>r;
			long long re=query(root,l,r);
			cout<<re<<endl;
			break;
		}
	}
	return 0;
}
