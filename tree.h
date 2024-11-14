#include "stack.h"
#include "moves.h"
#include "stack.h"
#include "loc.h"
#include "stdlib.h"

#ifndef UNTITLED1_TREE_H
#define UNTITLED1_TREE_H

typedef struct {
    int x,y;
    char orientation;
} Position;

typedef struct r_node {
    Position pos;
    int cost;
    int move;
    int depth;
    struct r_node** children;
} r_node;




#endif //UNTITLED1_TREE_H
