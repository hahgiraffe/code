/*
 * @Author: haha_giraffe
 * @Date: 2020-03-19 10:45:14
 * @Description: 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 
    这道题的思路不难的,首先每个节点有两个值,一个值是二叉排序树的值,另一个值是大根堆的值,
    插入过程就是首先根据二叉排序树正确找到位置,然后判断该节点的值是否比父节点大,如果是则相应的左旋和右旋父节点.(好像没这么简单...)
*/

typedef struct node Node;
typedef struct treap_t Treap;
typedef Node* nodePoint;

struct node
{ 
   int key;//关键字 
   int priority;//随机优先级
   Node* left;//左节点
   Node* right;//右节点

};

Node* root;//Treap的根结点

//左旋转
 void rotate_left(Node* &node)
 {
   Node* x = node->right;
   node->right = x->left;
   x->left =node;
   node = x;
 }

 //右旋转
 void rotate_right(Node* &node)
 {
   Node* x = node->left;
   node->left = x->right;
   x->right = node;
   node = x;
 }

 //插入操作
 void treap_insert(Node* &root, int key, int priority)
 {
   //根为NULL，则直接创建此结点为根结点
   if (root == NULL)
   {
     root = (Node*)new Node;
     root->left = NULL;
     root->right = NULL;
     root->priority = priority;
     root->key = key;
   }
   //向左插入结点
   else if (key <root->key)
   {
     treap_insert(root->left, key, priority);
     if (root->left->priority < root->priority)
       rotate_right(root);
   }

   //向左插入结点
   else
   {
     treap_insert(root->right, key, priority);
     if (root->right->priority < root->priority)
       rotate_left(root);
   }
 }

 //删除结点操作
 void treap_delete(Node* &root, int key)
 {
   if (root != NULL)
   {
     if (key < root->key)
       treap_delete(root->left, key);
     else if (key > root->key)
       treap_delete(root->right, key);
     else
     {
       //左孩子为空
       if (root->left == NULL)
         root = root->right;

       //右孩子为空
       else if (root->right == NULL)
         root = root->left;

       //左右孩子均不为空
       else
       {
         //先旋转，然后再删除
         if (root->left->priority < root->right->priority)
         {
           rotate_right(root);
           treap_delete(root->right, key);
         }
         else
         {
           rotate_left(root);
           treap_delete(root->left,key);
         }
       }
     }
   }
 }

//中序遍历
void in_order_traverse(Node* root)
{
  if (root!= NULL)
  {
    in_order_traverse(root->left);
    printf("%d\t", root->key);
    in_order_traverse(root->right);
  }
}

//计算树的高度
int depth(Node* node)
{
    if(node == NULL)
        return -1;
    int l = depth(node->left);
    int r = depth(node->right);
    return (l < r)?(r+1):(l+1);
}

int main()
{
  srand(time(0));

  //产生最大伪随机数0至RAND_MAX(32767)
  //printf("%d\n",RAND_MAX);

  //随机插入10个节点
  printf("----------------------创建Treap树堆-----------------------\n");
  printf("顺序插入0至9十个数，键值与优先级如下\n");
  for (int i = 0; i < 10; i++)
  {
    int pri=rand();
    printf("key:%d priority:%d\n",i,pri);
    treap_insert(root,i,pri);
  }

  //中序遍历Treap
  printf("\n插入完毕，中序遍历Treap所得结果为:\n");
  in_order_traverse(root);

  printf("\nTreap高度：%d\n", depth(root));

  printf("----------------------删除结点-----------------------\n");
  printf("请输入要删除的结点键值\n");
  int rmKey;
  scanf("%d",&rmKey);
  treap_delete(root, rmKey);

  printf("\n删除完毕，中序遍历Treap所得结果为:\n");
  in_order_traverse(root);

 printf("\nTreap高度：%d\n", depth(root));
  getchar();
  getchar();
  return 0;
}
