// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
// 1. 根据前序遍历的特点，确定根节点的值
// 2. 遍历中序遍历的元素，找到根结点的对应位置
// 3. 中序遍历的根元素的左边就是左子树，右边就是右子树
// 4. 拿到左右子树的长度，在前序遍历的元素集合中确定相关范围
// 5. 递归调用，构建左右子树

#include <iostream>
#include <exception>

using namespace std;

struct BinaryTreeNode {
  int value;
  BinaryTreeNode* left;
  BinaryTreeNode* right;
  BinaryTreeNode(int value){
    this->value = value;
    this->left = this->right = NULL;
  }
};

// 重构函数
BinaryTreeNode* construct_core(
  int *start_preorder, 
  int *end_preorder,
  int *start_inorder,
  int *end_inorder
){
  // 前序遍历的第一个节点就是根节点
  int root_value = *start_preorder;
  BinaryTreeNode* root = new BinaryTreeNode(root_value);
  if(start_preorder == end_preorder && start_inorder == end_inorder){
    return root;
  }
  
  // 找到中序遍历中 root 的位置
  int* root_inorder = start_inorder;
  while(root_inorder <= end_inorder && *root_inorder != root_value){
    ++root_inorder;
  }

  int left_length = root_inorder - start_inorder;
  int* left_preorder_end = start_preorder + left_length;
  
  // 构建左子树
  if(left_length > 0){
    root->left = construct_core(start_preorder + 1, left_preorder_end, start_inorder, root_inorder - 1);
  }

  // 构建右子树
  if(left_length < end_preorder - start_preorder){
    root->right = construct_core(left_preorder_end + 1, end_preorder, root_inorder + 1, end_inorder);
  }

  return root;
}

BinaryTreeNode* construct(int* preorder, int* inorder, int length){
  if(preorder == NULL || inorder == NULL || length <= 0){
    return NULL;
  }
  return construct_core(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

void print_tail_order(BinaryTreeNode* root){
  if(root == NULL){
    return;
  }
  if(root->left){
    print_tail_order(root->left);
  }
  if(root->right){
    print_tail_order(root->right);
  }
  cout<< root->value << " ";
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
int main(){
  const int length = 8;
  int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
  int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

  BinaryTreeNode* root = construct(preorder, inorder, length);
  print_tail_order(root);
  // cout<< root->value << endl;
  return 0;
}
