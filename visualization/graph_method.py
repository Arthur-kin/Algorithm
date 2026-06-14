import heapq
import os

def read_graph(file_name="input.txt"):
    """讀取 input.txt 檔案並建立鄰接串列"""
    if not os.path.exists(file_name):
        print(f"Error: {file_name} not found.")
        return None, None, None
    
    with open(file_name, "r") as f:
        lines = f.readlines()
        
    if not lines:
        return None, None, None
    
    # 讀取點數 V 與邊數 E
    V, E = map(int, lines[0].split())
    
    # 建立鄰接串列: adj[u] = [(v, weight), ...]
    adj = {i: [] for i in range(V)}
    edges = []
    has_negative_edge = False
    
    for line in lines[1:E+1]:
        if line.strip():
            u, v, w = map(int, line.split())
            adj[u].append((v, w))
            edges.append((u, v, w))
            if w < 0:
                has_negative_edge = True
                
    return V, adj, edges, has_negative_edge

def is_dag(V, adj):
    """使用 DFS 偵測圖形是否為 Directed Acyclic Graph (DAG)
    透過三色標記法 (0: 未造訪, 1: 造訪中, 2: 已完成) 尋找有無 Back-edge
    """
    visited = [0] * V
    
    def dfs(u):
        visited[u] = 1 # 標記為造訪中
        for v, _ in adj[u]:
            if visited[v] == 1:
                return False # 發現 Back-edge，代表有環，不是 DAG
            if visited[v] == 0:
                if not dfs(v):
                    return False
        visited[u] = 2 # 標記為已完成
        return True

    for i in range(V):
        if visited[i] == 0:
            if not dfs(i):
                return False
    return True

def topological_sort(V, adj):
    """對 DAG 進行拓撲排序"""
    visited = [False] * V
    stack = []
    
    def dfs(u):
        visited[u] = True
        for v, _ in adj[u]:
            if not visited[v]:
                dfs(v)
        stack.append(u)
        
    for i in range(V):
        if not visited[i]:
            dfs(i)
    return stack[::-1] # 翻轉過來才是標準的拓撲排序順序

def solve_dag(V, adj, start=0):
    """DAG 最短路徑演算法，複雜度 O(V + E)"""
    dist = [float('inf')] * V
    dist[start] = 0
    
    topo_order = topological_sort(V, adj)
    
    for u in topo_order:
        if dist[u] != float('inf'):
            for v, weight in adj[u]:
                if dist[u] + weight < dist[v]:
                    dist[v] = dist[u] + weight
    return dist

def solve_dijkstra(V, adj, start=0):
    """Dijkstra 演算法 (適用於無負邊的圖)，複雜度 O(E log V)"""
    dist = [float('inf')] * V
    dist[start] = 0
    
    # 最小優先佇列 (Min-Priority Queue)，存放 (距離, 頂點)
    pq = [(0, start)]
    
    while pq:
        d, u = heapq.heappop(pq)
        
        if d > dist[u]:
            continue
            
        for v, weight in adj[u]:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                heapq.heappush(pq, (dist[v], v))
    return dist

def solve_bellman_ford(V, edges, start=0):
    """Bellman-Ford 演算法 (適用於有負邊的圖)，複雜度 O(VE)
    同時檢查是否含有從起點可達的負權重迴圈
    """
    dist = [float('inf')] * V
    dist[start] = 0
    
    # 進行 V - 1 次的 Relaxation
    for _ in range(V - 1):
        for u, v, weight in edges:
            if dist[u] != float('inf') and dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                
    # 第 V 次檢查有無負權重迴圈 (Negative weight cycles)
    for u, v, weight in edges:
        if dist[u] != float('inf') and dist[u] + weight < dist[v]:
            # 如果還能被優化，代表有從起點 0 可達的負迴圈
            return None 
            
    return dist

def main():
    # 1. 讀取圖形測資
    V, adj, edges, has_negative_edge = read_graph()
    if V is None:
        return

    # 2. 判斷圖形種類
    # 先看是否為 DAG (有向無環圖)
    if is_dag(V, adj):
        graph_type = "A directed acyclic graph"
        algorithm_used = "DAG Shortest Paths Algorithm"
        shortest_distances = solve_dag(V, adj, start=0)
        
    # 如果不是 DAG，再看有沒有負權重邊
    elif not has_negative_edge:
        graph_type = "A graph with no negative weight edges"
        algorithm_used = "Dijkstra's Algorithm"
        shortest_distances = solve_dijkstra(V, adj, start=0)
        
    else:
        # 有負邊，交給 Bellman-Ford 處理並順便偵測負迴圈
        shortest_distances = solve_bellman_ford(V, edges, start=0)
        
        if shortest_distances is None:
            graph_type = "A graph with negative weight cycles"
            print(f"Graph Type: {graph_type}")
            print("Warning: No shortest paths can be found.")
            return
        else:
            graph_type = "A graph with negative weight edges but no negative weight cycles"
            algorithm_used = "Bellman-Ford Algorithm"

    # 3. 輸出結果
    print(f"Graph Type: {graph_type}")
    print(f"Algorithm Selected: {algorithm_used} (Optimal Time Complexity)")
    print("Shortest paths from vertex 0:")
    for vertex in range(V):
        d = shortest_distances[vertex]
        print(f"To vertex {vertex}: Distance = {d if d != float('inf') else 'Unreachable'}")

if __name__ == "__main__":
    main()
