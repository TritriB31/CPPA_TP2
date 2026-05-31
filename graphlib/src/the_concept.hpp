#pragma once
#include <concepts>

namespace graphlib {

    template <typename G>
    concept Graph = requires(G g, typename G::vertex_type v) {
        typename G::weight_type;
        g.vertices();
        g.edges_from(v);
    };

}