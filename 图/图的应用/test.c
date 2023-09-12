

void Prim(G, TE)
{
    TE = {}; // 初始化书的边集为空
    U = {w}; // 添加一个任意节点
    while (G.V-U != {})
    {
        设(u,v)是使u属于U与v属于(U-V)，且权值最小的边;
        TE = TE ∪ {(u, v)};
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