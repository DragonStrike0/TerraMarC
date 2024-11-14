#include "tree.h"


r_node starting(Position start, int initial_cost){
    r_node *root = malloc(sizeof(r_node));
    root->pos = start;
    root->cost = initial_cost;
    root->children = malloc(sizeof(r_node)*9);
    return *root;
}




