#include "stack.h"
#include "moves.h"
#include "loc.h"
#include "stdlib.h"
#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

typedef struct {
    t_move moves[9];
    int count_moves;
}t_avlbl_moves;

typedef struct node{
    t_localisation loc;
    int cost;
    t_move last_move;
    struct node* parent;
    struct node** children;
    int child_count;
    int depth;
}t_node;

typedef struct {
    t_node *root;
    int max_depth;
    int total_nodes;
}t_tree;



t_tree* create_tree(t_localisation start_loc, int start_cost, int max_depth);

t_node* create_node(t_localisation loc, int cost, t_move move, t_node* parent, int depth);

void add_child(t_node* parent, t_node* child);

void build_tree_level(t_node* node, t_avlbl_moves* available_moves, int terrain_costs[MAX_Y][MAX_X]);

t_node* find_min_cost_leaf(t_tree* tree);

void get_path_to_node(t_node* node, t_move* moves, int* move_count);

void free_tree(t_tree* tree);





#endif //UNTITLED1_TREE_H
