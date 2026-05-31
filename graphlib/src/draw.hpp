#pragma once
#include <fmt/core.h>
#include <fmt/ostream.h>
#include <iostream>
#include "the_concept.hpp"

namespace graphlib {

template <Graph G>
void draw_graph_to_dot(const G& graph, std::ostream& out) {
    fmt::print(out, "digraph G {{\n");
    
    auto verts = graph.vertices();
    for (auto v : verts) {
        fmt::print(out, "  \"{}\";\n", v);
        
        auto edges = graph.edges_from(v);
        for (auto edge : edges) {
            fmt::print(out, "  \"{}\" -> \"{}\" [label=\"{}\"];\n", v, edge.target, edge.weight);
        }
    }
    
    fmt::print(out, "}}\n");
}

}