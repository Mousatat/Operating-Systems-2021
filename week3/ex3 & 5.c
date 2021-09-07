#include <stdio.h>

typedef enum { false, true } bool;
typedef struct ll *node;

struct ll
{
    int valueue;
    struct ll *next;
    struct ll *prev;
};
void print_list(node cnode)
{
    printf("%d \n", cnode->valueue);
    if(cnode->next!=NULL
       print_list(cnode->next);
}
node create_node(int value)
{
    node n;
    n = (node)malloc(sizeof(struct ll));
    n->valueue=value;
    n->next = NULL;
    n->prev = NULL;
    return n;
}
bool insert_node(node inode,node cnode, int after_value)
{
    if(cnode->valueue==after_value)
    {
        inode->next = cnode->next;
        cnode->next = inode;
        inode->prev = cnode;
        if(inode->next!=NULL)
            inode->next->prev = inode;
        return true;
    }
    else if(cnode->next!=NULL)
        insert_node(inode,cnode->next,after_value);
    else return false;
}
bool delete_node(node cn, int valueue)
{
    if(cn->valueue==valueue)
    {
        cn->prev->next = cn->next;
        cn->next->prev = cn->prev;
    }
    else if(cn->next!=NULL)
        delete_node(cn->next,valueue);
    else return false;
}
int main()
{
    node f = create_node(5);
    insert_node(create_node(4),f,5);
    insert_node(create_node(3),f,5);
    insert_node(create_node(2),f,5);
    insert_node(create_node(1),f,5);
    print_list(f);
    printf("\n \n");
    delete_node(f,3);
    print_list(f);
}
