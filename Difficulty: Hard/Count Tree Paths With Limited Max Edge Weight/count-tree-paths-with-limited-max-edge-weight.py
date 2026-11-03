class Solution:
    def maximumWeight(self, n, edges, queries):
        # code here
        # union find. given a component with n nodes and component with m nodes, if there is 
        # an edge that connect these 2 components. there are mxn pathes

        parents = [i for i in range(n+1)]
        components = [1]*(n+1)

        def find(i):
            if i != parents[i]:
                parents[i] = find(parents[i])
            return parents[i]

        edges = sorted(edges, key=lambda e: e[2])
        queries = sorted(enumerate(queries), key=lambda e: e[1])
        ret = [0]*len(queries)

        edge_idx = 0
        ans = 0
        for i, q in queries:
            while edge_idx < len(edges) and edges[edge_idx][2] <= q:
                u, v, _ = edges[edge_idx]
                r1 = find(u)
                r2 = find(v)
                if r1 != r2:
                    ans += components[r1] * components[r2]
                    parents[r1] = r2
                    components[r2] += components[r1]
                    components[r1] = 0
                edge_idx += 1
            ret[i] = ans
        return ret