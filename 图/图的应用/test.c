

void Prim(G, T)
{
    T = {}; // 初始化生成树的边节点集合为空集
    U = {w};
    while (G.V-U != {})
    {
        min_arc = (u∈U, v∈(V-U));
        T = {min_arc} ∪ T;
        U = U ∪ {v};
    }
}

void Kruskal(G, T)
{
    T = N;
    U = {}; // MST的边集初始为空
    num = n;
    while (num > 1)
    {
        // 从E中选取权值最小的边(u,v)
        min_arc = (u, v);
        U = U ∪ {min_arc};
        num--;
    }
}