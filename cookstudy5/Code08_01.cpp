// 08_01.cpp
// 완전 이진 트리 생성

#include "../CookHeader.h"

typedef struct _TreeNode{
    struct _TreeNode* left = NULL;
    string data;
    struct _TreeNode* right =NULL;
} TreeNode;

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
    node3 -> left = node6;

    println(root -> data);
    println(root -> left -> data + " " + root -> right -> data);
    println(root -> left -> left -> data + " " + root -> left -> right -> data + " " + root -> right -> left -> data);
}