#include <cstdio>
int n, m, p, a[10001] = { 0 };	//a[i]表示i的祖先是a[i]

int find(int x)
{
	if (a[x] == x) return x;	  //如果找到祖先，即a[x]=x（自己的祖先是自己），返回节点的值
	//int a[x]的祖先 = find (a[x]);
	//a[x] = a[x]的祖先;
	//return a[x]的祖先;
	return a[x] = find(a[x]);     //递归查找祖先并更改父节点们的祖先
}

void getf(int xi, int yi)		//合并xi,yi
{
	int xz = find(xi), yz = find(yi);    //找祖先
	if (xz != yz) a[yz] = xz;
}

int main()
{
	scanf("%d%d%d", &n, &m, &p);

	for (int i = 1; i <= n; i++) a[i] = i;    //初始化把每个的父节点设为他们自己

	int xi, yi;

	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &xi, &yi);
		getf(xi, yi); //合并xi,yi
	}

	for (int i = 1; i <= p; i++)
	{
		scanf("%d%d", &xi, &yi);

		if (find(xi) == find(yi))	//如果xi的祖先节点=yi的祖先节点
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
