// 08_02-selfstudy.cpp
// 이진 트리의 순회(재귀 함수 사용)

#include "../CookHeader.h"

typedef struct _TreeNode{
    string data;
    struct _TreeNode* left = NULL;
    struct _TreeNode* right = NULL;
} TreeNode;

void preOrder(TreeNode* node){ //전위
    if(node == NULL){
        return;
    }
    print(node -> data + "->");
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(TreeNode* node){ //
    if(node == NULL){
        return;
    }
    inOrder(node->left);
    print(node->data+"->");
    inOrder(node->right);
}

void postOrder(TreeNode* node){
    if(node == NULL){
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    print(node->data+"->");
}

int main() {
    TreeNode* root;

    TreeNode* node1 = new TreeNode;
    node1 -> data = "화사";
    root = node1;

    TreeNode* node2 = new TreeNode;
    node2 -> data = "솔라";
    node1 -> left = node2;

    TreeNode* node3 = new TreeNode;
    node3 -> data = "문별";
    node1 -> right = node3;

    TreeNode* node4 = new TreeNode;
    node4 -> data = "휘인";
    node2 -> left = node4;

    TreeNode* node5 = new TreeNode;
    node5 -> data = "쯔위"; 
    node2 -> right = node5;

    TreeNode* node6 = new TreeNode;
    node6 -> data = "선미";
    node3 -> right = node6;

    TreeNode* node7 = new TreeNode;
    node7 -> data = "다현";
    node4 -> right = node7;

    TreeNode* node8 = new TreeNode;
    node8 -> data = "사나";
    node6 -> right = node8;


    print("전위 순회 : ");
    preOrder(root);
    println("끝");

    print("중위 순회 : ");
    inOrder(root);
    println("끝");

    print("후위 순회 : ");
    postOrder(root);
    println("끝");
}