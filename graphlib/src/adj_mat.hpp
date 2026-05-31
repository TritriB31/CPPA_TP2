#pragma once
#include <vector>

namespace graphlib {

template <typename WeightType>
class AdjacencyMatrix {
public:
    using vertex_type = int;
    using weight_type = WeightType;

    struct Edge {
        vertex_type target;
        weight_type weight;
    };

    struct Cell {
        bool has_edge;
        weight_type weight;
    };

    AdjacencyMatrix(int num_vertices) {
        size = num_vertices;
        matrix.resize(size, std::vector<Cell>(size, {false, weight_type()}));
    }

    void add_edge(vertex_type source, vertex_type target, weight_type weight) {
        matrix[source][target].has_edge = true;
        matrix[source][target].weight = weight;
    }

    std::vector<vertex_type> vertices() const {
        std::vector<vertex_type> res;
        for (int i = 0; i < size; ++i) {
            res.push_back(i);
        }
        return res;
    }

    std::vector<Edge> edges_from(vertex_type v) const {
        std::vector<Edge> res;
        for (int i = 0; i < size; ++i) {
            if (matrix[v][i].has_edge) {
                res.push_back({i, matrix[v][i].weight});
            }
        }
        return res;
    }

private:
    std::vector<std::vector<Cell>> matrix;
    int size;
};

}