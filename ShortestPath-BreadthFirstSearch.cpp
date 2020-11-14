#include <list>
#include <vector>
#include <iostream>



class Graph {
public:
    explicit Graph(int total_nodes_) : total_nodes(total_nodes_) {
        adjacency_list.resize(total_nodes + 1);
    }

    void AddEdge(int from, int to) {
        if ((from > 0) && (to > 0) && (from < total_nodes + 1) && (to < total_nodes + 1)) {
            adjacency_list[from].push_back(to);
        }
    }

    int GetDistance(int source, int destination) {
        if (source == destination) {
            return -1;
        }
        std::vector<bool> visited(total_nodes + 1);
        for (int i = 1; i <= total_nodes; i++)
            visited[i] = false;
        std::list<int>queue;
        visited[source] = true;
        queue.push_back(source);
        int edge_present = 0;
        std::vector<int> distance(total_nodes + 1, 0);
        while (!queue.empty()) {
            source = queue.front();
            queue.pop_front();
            for (auto i = adjacency_list[source].begin(); i != adjacency_list[source].end(); ++i) {
                edge_present++;
                if (*i == destination)
                    return ++distance[source];
                if (!visited[*i]) {
                    distance[*i] = distance[source] + 1;
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
            if (edge_present == 0)
                return -1;
        }
        return -1;
    }

private:
    std::vector<std::vector<int>> adjacency_list;
    int total_nodes;
};


int main() {
    int total_nodes;
    std::cin >> total_nodes;
    Graph graph(total_nodes);
    int number_of_edges, from, to;
    std::cin >> number_of_edges;
    for (int i = 0; i < number_of_edges; i++) {
        std::cin >> from >> to;
        graph.AddEdge(from, to);
    }
    int source, destination;
    std::cin >> source >> destination;
    if (total_nodes == 0)
        std::cout << "-1";
    else
        std::cout << graph.GetDistance(source, destination);
    return 0;
}
