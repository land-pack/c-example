#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct _node {
    int data;
    struct _node *link[2];
}Node;

typedef struct _tree{
    struct _node *root;
}Tree;

Tree * init_tree()
{
    Tree *temp = (Tree*)malloc(sizeof(Tree));
    temp->root = NULL;
    return temp;
}

Node * make_node(int data)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->link[0] = temp->link[1] = NULL;
    temp->data = data;
    return temp;
}

int insert(Tree *tree, int data)
{
    if(tree->root == NULL){
        tree->root = make_node(data);
    }else{
        Node * it = tree->root;
        int dir ;
        for(;;){
            dir = it->data < data;
            if(it->data == data){
                return 0;
            }else if(it->link[dir] == NULL){
                break;
            }
            it = it->link[dir];
        }
        it->link[dir] = make_node(data);
    }
    return 1;
}
int remove_node(Tree *tree, int data)
{
    if(tree->root != NULL)
    {
        Node *p = NULL;
        Node *succ;
        Node *it = tree->root;
        int dir;
        for(;;){
            if( it == NULL){
                return 0;
            }else if(it->data == data){
                break;
            }
            dir = it->data < data;
            p = it;
            it = it->link[dir];
        }
/***********************************************************************/

        if(it->link[0] != NULL && it->link[1] != NULL){
            p = it;
            succ = it->link[1];
            while(succ->link[0] != NULL){
                p = succ;
                succ = succ->link[0];
            }
            it->data = succ->data;
            p->link[p->link[1] == succ] = succ->link[1];
            free(succ);
/***********************************************************************/
        }else{  /*it->link[0] == NULL || it->link[1] == NULL */
            dir = it->link[0] == NULL;
            if( p == NULL){
                tree->root = it->link[dir];
            }else{
                p->link[p->link[1] == it] = it->link[dir];
            }
            free(it);
        }
    }

    return 1;
}
int find_recursive(Node *root, int data)
{
    if(root == NULL){
        return 0;
    }else if(root->data == data){
        return 1;
    }else{
        int dir = root->data < data;
        return find_recursive(root->link[dir],data);
    }
}

int find(Tree *tree,int data)
{
    return find_recursive(tree->root,data);
}

void tips(){
    time_t curTime;
    struct tm *ts;
    time_t testTime = time(&curTime);
    ts = localtime(&curTime);
    //struct tm *tsgm = gmtime(&curTime);
    puts("*************************************************************");
    printf("Date:%s",asctime(ts));
    puts("Please input right cmd");
    puts("1)Search");
    puts("2)Quit");
    puts("*************************************************************");
}
int search(Tree *tree)
{
    char cmd;
    int isExist;
    int target;
    tips();
    while((cmd=getchar())!=EOF){
        if(cmd=='1'){
            puts("-------------------------------------------------------------");
            printf("Please input the target:");
            scanf("%d",&target);
            isExist=find(tree,target);
            if(isExist){
                 printf("Target %d is exists \n",target);
            puts("-------------------------------------------------------------");
                 puts("\n");
                 continue;
                //break;
            }else{
                 puts("Target Not exitst");
            puts("-------------------------------------------------------------");
                 puts("\n");
                 continue;
                //break;
            }
        }else if(cmd=='2'){
            puts("bye~");
            break;
        }else{
        tips();
        }
    }
    return 1;
}


void structure_recursive(Node *root,int level)
{
    int i;
    if(root == NULL){
        for(i = 0;i<level;i++){
            putchar('\t');
        }
        puts("~");
    }else{
        structure_recursive(root->link[1],level + 1);
        for(i = 0;i < level;i++){
            putchar('\t');
        }
        printf("%d\n",root->data);
        structure_recursive(root->link[0],level + 1);
    }
}

void structure(Tree *tree)
{
    structure_recursive(tree->root,0);
}

int main(void)
{
    Tree * tree = init_tree();
    insert(tree,8);
    insert(tree,10);
    insert(tree,11);
    insert(tree,6);
    insert(tree,7);
    insert(tree,5);
    structure(tree);
    return 0;
}
