#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
} NODE;

NODE* createnode(int item){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

NODE* insertNodes(){
    int item;
    char choice;
    printf("Enter value of node(or -1 for NULL): ");
    scanf("%d", &item);
    if(item == -1) return NULL;
    NODE* new_node = createnode(item);
    printf("Do you want to add left child to %d ?(y/n)\n",item);
    scanf("\n%c", &choice);
    if(choice == 'y' || choice == 'Y'){
        new_node->left = insertNodes();
    }
    printf("Do you want to add right child to %d ?(y/n)\n",item);
    scanf("\n%c", &choice);
    if(choice == 'y' || choice == 'Y'){
        new_node->right = insertNodes();
    }
    return new_node;
}

void display_inorder(NODE *root){
    if(root!=NULL){
        display_inorder(root->left);
        printf("%d\t", root->data);
        display_inorder(root->right);
    }
}

int count_nodes(NODE* root){
    if(root==NULL) return 0;
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}

int height(NODE* root){
    int left, right;
    if(root==NULL) return -1;
    else{
        left = height(root->left);
        right = height(root->right);
        if(left>right) return left+1;
        return right+1;
    }
}

int leaf_nodes(NODE* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return leaf_nodes(root->left) + leaf_nodes(root->right);
}

int nonleaf_nodes(NODE* root){
    if(root==NULL || (root->left == NULL && root->right==NULL)) return 0;
    return nonleaf_nodes(root->left) + nonleaf_nodes(root->right) + 1;
}

int main(){
    NODE* root = NULL;
    printf("Build tree dynamically\n");
    root = insertNodes();
    printf("Inorder traversal is \n");
    display_inorder(root);
    printf("\nTotal nodes : %d\n", count_nodes(root));
    printf("\nHeight : %d\n",height(root));
    printf("\nTotal leaf nodes : %d\n", leaf_nodes(root));
    printf("\nTotal non leaf nodes : %d\n", nonleaf_nodes(root));
    return 0;
}