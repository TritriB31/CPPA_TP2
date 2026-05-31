#pragma once
#include <unordered_map>
#include <vector>

namespace graphlib {

template <typename WeightType, typename VertexType = int>
class AdjacencyList {
public:
    using vertex_type = VertexType;
    using weight_type = WeightType;

    struct Edge {
        vertex_type target;
        weight_type weight;
    };

    void add_vertex(vertex_type v) {
        if (adj_map.find(v) == adj_map.end()) {
            adj_map[v] = std::vector<Edge>();
        }
    }

    void add_edge(vertex_type source, vertex_type target, weight_type weight) {
        add_vertex(source);
        add_vertex(target);
        adj_map[source].push_back({target, weight});
    }

    std::vector<vertex_type> vertices() const {
        std::vector<vertex_type> res;
        for (const auto& pair : adj_map) {
            res.push_back(pair.first);
        }
        return res;
    }

    std::vector<Edge> edges_from(vertex_type v) const {
        if (adj_map.find(v) != adj_map.end()) {
            return adj_map.at(v);
        }
        return {};
    }

private:
    std::unordered_map<vertex_type, std::vector<Edge>> adj_map;
};

}