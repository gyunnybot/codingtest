
void dfs(int here) {
    if(visited[here]) return;

    for(int there : adj[here]) {
        if(!visited[there]) {
            visited[there] = vistied[here] + 1;
            dfs(there);
        }
    }
}

int main() {
    int n,m,k,x;

    cin>>n>>m>>k>>x;

    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(x);

    for(int i=0;i<n;i++) {
        if(v[i]==k) ret++;
    }

    cout<<ret;

    return 0;
}
