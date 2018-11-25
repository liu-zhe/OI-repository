#include <cstdio>
#include <queue>

#define maxn 1000000

using namespace std;

/*----------邻接表----------*/

int head[maxn], num = 0;
struct node
{
	int data;
	int to;
	int next;
} edge[maxn];

inline void add_edge(int from, int to, int data)
{
	edge[++num].next = head[from];
	head[from] = num;
	edge[num].data = data;
	edge[num].to = to;
}

/*----------优先级队列----------*/

struct Heap			//小根堆
{
	int d, e;			//到e权值为d
	bool operator<(const Heap &b) const  //运算符重载
	{
		return d > b.d;
	}
};

priority_queue<Heap> q;

/*----------Dijkstra----------*/

int n, m, dis[maxn] = {}, start;
bool vis[maxn] = {};

inline void Dijkstra(int start)
{
	Heap x;
	q.push((Heap) {0, start});		//定义临时对象
	dis[start] = 0;
	
	while (!q.empty())
	{
		x = q.top();		//找一个与当前节点距离最小的点
		q.pop();
		int e = x.e;

		if (vis[e])	
			continue;

		vis[e] = true;
		for (int i = head[e]; i; i = edge[i].next)		//用找到的点更新最短路并加入堆
		{
			dis[edge[i].to] = min(dis[edge[i].to], dis[e] + edge[i].data);	
			q.push((Heap){dis[edge[i].to], edge[i].to});
		}
	}
}

/*----------主函数----------*/

int main(int argc, char **argv)
{
	scanf("%d%d%d", &n, &m, &start);
	for (int i = 1; i <= m; i++)
	{
		int q, w, e;
		scanf("%d%d%d", &q, &w, &e);
		add_edge(q, w, e);
	}

	for (int i = 1; i <= n; i++)		//初始化
		dis[i] = 2147483647;

	Dijkstra(start);

	for (int i = 1; i <= n; i++)
		printf("%d ", dis[i]);
	return 0;
}
