#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100 + 10;
const int inf = 0x3f3f3f3f;
struct SAP
{
	int cap[MAXN][MAXN], flow[MAXN][MAXN], g[MAXN][MAXN];
	int n;
	int h[MAXN], vh[MAXN], source, sink;
	int mk[MAXN];
	void init(int n)
	{
		this->n = n;
		memset(cap, 0, sizeof(cap));
		memset(g, 0, sizeof(g));
		memset(mk, 0, sizeof(mk));
	}
	void addCap(int i, int j, int val)
	{
		cap[i][j] += val;
		g[i][j] = 1;
	}
	int sap(const int idx, const int maxCap)
	{
		if (idx == sink)
			return maxCap;
		int l = maxCap, d, minH = n;
		for (int i = 0; i < n; i++)
		{
			if (cap[idx][i] - flow[idx][i] > 0)
			{
				if (h[idx] == h[i] + 1)
				{
					d = sap(i, min(l, cap[idx][i] - flow[idx][i]));
					flow[idx][i] += d;
					flow[i][idx] -= d;
					l -= d;
					if (h[source] == n || l == 0) return maxCap - l;
				}
				minH = min(minH, h[i] + 1);
			}
		}
		if (l == maxCap)
		{
			vh[h[idx]]--;
			vh[minH]++;
			if (vh[h[idx]] == 0)
				h[source] = n;
			h[idx] = minH;
		}
		return maxCap - l;
	}
	int solve(int source, int sink)
	{
		if (source == sink) return inf;
		this->sink = sink;
		this->source = source;
		memset(flow, 0, sizeof(flow));
		memset(h, 0, sizeof(h));
		memset(vh, 0, sizeof(vh));
		int ans = 0;
		while (h[source] != n)
			ans += sap(source, inf);
		return ans;
	}
	void dfs(int u)
	{
		mk[u] = 1;
		for (int i = 0; i < n; i++)
		{
			if (!mk[i] && cap[u][i] - flow[u][i] > 0) dfs(i);
		}
	}
	void output()
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (g[i][j] && cap[i][j] - flow[i][j] == 0 && mk[i] != mk[j])
					printf("%d %d\n", i + 1, j + 1);
	}
}sap;

int main()
{
	freopen("a", "r", stdin);
	int n, m;
	bool blank = false;
	while (scanf("%d%d", &n, &m))
	{
		if (n == 0 && m == 0) break;
		if (blank) puts("");
		blank = true;
		int source = 0, sink = 1;
		sap.init(n);
		for (int i = 1; i <= m; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			u--; v--;
			sap.addCap(u, v, w);
			sap.addCap(v, u, w);
		}
		int res = sap.solve(source, sink);
		sap.dfs(0);
		sap.output();
	}
	return 0;
}
