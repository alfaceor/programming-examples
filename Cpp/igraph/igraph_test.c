#include <stdio.h>
#include <igraph.h>

int main()
{
     igraph_real_t diameter;
     igraph_t graph;
     igraph_erdos_renyi_game(&graph, IGRAPH_ERDOS_RENYI_GNP, 1000, 5.0/1000,
                             IGRAPH_UNDIRECTED, IGRAPH_NO_LOOPS);
     igraph_diameter(&graph, &diameter, 0, 0, 0, IGRAPH_UNDIRECTED, 1);
     printf("Diameter of a random graph with average degree 5: %f\n",
             (double) diameter);
     igraph_destroy(&graph);
     return 0;
}
