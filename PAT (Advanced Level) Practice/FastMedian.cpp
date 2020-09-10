#include <set>

typedef struct CountingNode {
    struct CountingNode* lchild;
    struct CountingNode* rchild;
    int lcount;
    int rcount;
} CountingNode;