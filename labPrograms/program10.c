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

NODE* insertbst(NODE* root, int item){
    NODE* temp;
    temp = createnode(item);
    if(root == NULL) return temp;
    else{
        if(item<root->data) root->left = insertbst(root->left, item);
        else root->right = insertbst(root->right, item);
    }
    return root;
}

void preorder(NODE* root){
    if(root!=NULL){
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(NODE* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void postorder(NODE* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

NODE* inordersuccessor(NODE* root){
    NODE* cur = root;
    while(cur->left != NULL) cur = cur->left;
    return cur;
}

NODE* deletebst(NODE* root, int key){
    NODE* temp;
    if(root == NULL) return NULL;
    else if(key<root->data) root->left = deletebst(root->left, key);
    else if(key>root->data) root->right = deletebst(root->right, key);
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        if(root->right == NULL){
            temp = root->left;
            free(root);
            return temp;
        }
        if(root->left == NULL){
            temp = root->right;
            free(root);
            return temp;
        }
        temp = inordersuccessor(root->right);
        root->data = temp->data;
        root->right = deletebst(root->right, temp->data);
    }
    return root;
}

int main(){
    NODE* root = NULL;
    int ch, item, key;
    for(;;){
        printf("\n1. Insert node\n2. Preorder\n3. Inorder\n4. Postorder\n5. Delete node\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &item);
            root = insertbst(root, item);
            break;
        case 2:
            printf("\nPreorder traversal is \n");
            preorder(root);
            break;
        case 3:
            printf("\nInorder traversal is \n");
            inorder(root);
            break;
        case 4:
            printf("\nPostorder traversal is \n");
            postorder(root);
            break;
        case 5:
            printf("Enter the node: ");
            scanf("%d", &key);
            root = deletebst(root, key);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}