#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <list>

class Graph {
public:
    int nodes;
    Graph(int number_of_nodes) : adjacency_list(number_of_nodes + 1) {
        nodes = number_of_nodes;
    }

    void AddEdge(int source, int destination, int weight) {
        adjacency_list[source].push_back(std::make_pair(destination, weight));
        adjacency_list[destination].push_back(std::make_pair(source,weight));
    }

    int GetDistanceDijkstra(int source, int target) const {
        std::vector<int> dist(adjacency_list.size(), INT_MAX);
        std::set<int> node;
        dist[0] = 0;
        dist[source] = 0;
        int path_disconn = 1;
        node.insert(source);
        int min_node = source;
        int min_dis = INT_MAX;
        while (node.size() != adjacency_list.size() - 1) {
            for (auto i : adjacency_list[source]) {
                if (dist[i.first] != INT_MAX) {
                    if (dist[i.first] > (i.second + dist[source])) {
                        dist[i.first] = i.second + dist[source];
                        continue;
                    }
                    else {
                        continue;
                    }
                }
                dist[i.first] = i.second + dist[source];
            }
            for (int i = 1; i <= nodes; ++i) {
                if (*node.find(i) != i) {
                    if (dist[i] < INT_MAX) {
                        if (dist[i] < min_dis) {
                            min_dis = dist[i];
                            path_disconn = 0;
                            min_node = i;
                        }
                    }
                }
            }
            min_dis = INT_MAX;
            if (path_disconn == 1)
                break;
            if (*node.find(min_node) != min_node)
                node.insert(min_node);
            source = min_node;
            path_disconn = 1;
        }
        if (dist[target] == INT_MAX) {
            return -1;
        }
        return dist[target];
    }

private:
    std::vector<std::vector<std::pair<int, int>>> adjacency_list;
};


int main() {
    int number_of_nodes;
    int number_of_edges;
    std::cin >> number_of_nodes >> number_of_edges;

    Graph graph(number_of_nodes);

    for (int i = 0; i < number_of_edges; ++i) {
        int from;
        int to;
        int weight;
        std::cin >> from >> to >> weight;
        graph.AddEdge(from, to, weight);
    }

    std::cout << graph.GetDistanceDijkstra(1, number_of_nodes);

    return 0;
}
