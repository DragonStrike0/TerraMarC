#include "tree.h"



t_tree* create_tree(t_localisation start_loc, int start_cost, int max_depth) {
    t_tree* tree = malloc(sizeof(t_tree));
    tree->max_depth = max_depth;
    tree->total_nodes = 0;
    tree->root = create_node(start_loc, start_cost, NO_MOVE, NULL, 0);
    return tree;
}

t_node* create_node(t_localisation loc, int cost, t_move move, t_node* parent, int depth) {
    t_node* node = malloc(sizeof(t_node));
    node->loc = loc;
    node->cost = cost;
    node->last_move = move;
    node->parent = parent;
    node->children = NULL;
    node->child_count = 0;
    node->depth = depth;
    return node;
}


