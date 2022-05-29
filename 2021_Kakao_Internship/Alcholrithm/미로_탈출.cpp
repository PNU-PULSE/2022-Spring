#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <string>

using namespace std;
using pii = pair<int, int>;

vector<int> adj[1010];
int dist[1010][2048];

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 987654321;
    map<int, int> trap_infos;
    map<pii, int> edge;
    map<pii, int> reverse_edge;

    for(int i = 1; i<= n; ++i) {
        trap_infos[i] = 0;
    }
    for(int i = 0; i < traps.size(); ++i) {
        trap_infos[traps[i]] = i + 1;
    }
    for(int i =0 ;i<= n ; ++i) {
        for (int j = 0; j < 2048; ++j) {
            dist[i][j] = 987654321;
        }
    }

    dist[start][0] =0;
    for(auto road : roads) {
        if (edge.find({road[0], road[1]}) == edge.end()) {
            edge[{road[0],road[1]}] = road[2];
        }
        else {
            edge[{road[0], road[1]}] = min(edge[{road[0], road[1]}], road[2]);
        }
        if(reverse_edge.find({road[1], road[0]}) == reverse_edge.end()) {
            reverse_edge[{road[1], road[0]}] = road[2];
        }
        else {
            reverse_edge[{road[1], road[0]}] = min(reverse_edge[{road[1], road[0]}], road[2]);
        }

        adj[road[0]].push_back({road[1]});
        adj[road[1]].push_back({road[0]});
    }

    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, 0, start});

    while(!pq.empty()) {
        auto [cost, bit, u] = pq.top();
        pq.pop();
        cost = -cost;

        for(int v : adj[u]) {
            bool flag_1 = (bit& (1 << trap_infos[u]));
            bool flag_2 = (bit & (1 << trap_infos[v]));
            if ((flag_1 && flag_2) || (!flag_1 && !flag_2)) {
                if (edge.find({u, v}) != edge.end() && dist[v][bit] > cost + edge[{u, v}]) {
                    dist[v][bit] = cost + edge[{u, v}];
                    pq.push({-dist[v][bit], trap_infos[v] > 0 ? bit ^ (1 << trap_infos[v]) : bit, v });
                }
            }
            else if ((flag_1 && !flag_2) || (!flag_1 && flag_2)) {
                if (reverse_edge.find({u, v}) != reverse_edge.end() && dist[v][bit] > cost + reverse_edge[{u, v}]) {
                    dist[v][bit] = cost + reverse_edge[{u, v}];
                    pq.push({-dist[v][bit], trap_infos[v] > 0 ? bit ^ (1 << trap_infos[v]) : bit, v});
                }
            }
        }
    }
    for(int i = 0; i< 2048; ++i) {
        answer = min(answer, dist[end][i]);
    }
    return answer;
}