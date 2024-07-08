#include <bits/stdc++.h>
#define INF INT64_MAX
typedef long long ll;
using namespace std;

struct info{
    int node;
    ll cost;
};

struct compare{
    bool operator()(info &l, info &r){
        return l.cost>r.cost;
    }
};

int n;
vector<vector<info>> graph;

ll dijkstra(int start, int des){
    vector<int> d(n,INF);
    d[start]=0;
    priority_queue<info,vector<info>,compare> pq;
    pq.push({start,0});
    while(!pq.empty()){
        int now=pq.top().node;
        ll dist=pq.top().cost;
        pq.pop();
        for(int i=0;i<graph[now].size();i++){
            ll cost=dist+graph[now][i].cost;
            if(cost<d[graph[now][i].node]){
                d[graph[now][i].node]=cost;
                pq.push({graph[now][i].node,cost});
            }
        }
    }
    return d[des];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    
    return 0;
}