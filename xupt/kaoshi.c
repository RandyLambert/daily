#include <stdio.h>
typedef struct Node
{
    struct Node *next;
    int value;
} Node;
Node* getnode(Node *node)
{
    Node *next;
    if (!node)
    {
        return NULL;
    }
    next = node->next;
    while (node != next->next)
    {
        next = next->next;
    }
    return next;
}
void delNode(Node *node)
{
    Node *p1 = getnode(node);
    if (p1)
    {
        getnode(p1)->next = p1->next;
    }
}
