#include <iostream>
using namespace std;
#define MaxSize 100
struct ElemType
{
  int value;
};
// 二叉树的结点（链式存储）
typedef struct BiTNode
{
  ElemType data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
// 二叉树的建立
void CreateBiTree(BiTree &T)
{
  char ch;
  cin >> ch;
  if (ch == '0')
    T = NULL;
  else
  {
    T = (BiTree)malloc(sizeof(BiTNode));
    T->data.value = ch;
    CreateBiTree(T->lchild);
    CreateBiTree(T->rchild);
  }
}
// 先序遍历
void PreOrder(BiTree T)
{
  if (T != NULL)
  {
    visit(T); // 自定义一个访问函数
    PreOrder(T->lchild);
    PreOrder(T->rchild);
  }
}
// 中序遍历
void InOrder(BiTree T)
{
  if (T != NULL)
  {
    InOrder(T->lchild);
    visit(T); // 自定义一个访问函数
    InOrder(T->rchild);
  }
}
// 后序遍历
void PostOrder(BiTree T)
{
  if (T != NULL)
  {
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    visit(T); // 自定义一个访问函数
  }
}
// 树的深度
int TreeDepth(BiTree T)
{
  if (T == NULL)
  {
    return 0;
  }
  else
  {
    int l = TreeDepth(T->lchild);
    int r = TreeDepth(T->rchild);
    return (l > r) ? (l + 1) : (r + 1);
  }
}
// 链式队列结点
typedef struct LinkNode
{
  BiTNode *data;
  struct LinkNode *next;
} LinkNode;
typedef struct
{
  LinkNode *front, *rear; // 队头队尾
} LinkQueue;
// 层序遍历
void LevelOrder(BiTree T)
{
  LinkQueue Q;
  InitQueue(Q); // 初始化辅助队列
  BiTree p;
  EnQueue(Q, T);      // 将根结点入队
  while (!IsEmpty(Q)) // 队列不空则循环
  {
    DeQueue(Q, p); // 队头结点出队
    visit(p);
    if (p->lchild != NULL)
    {
      EnQueue(Q, p->lchild); // 左孩子入队
    }
    if (p->rchild != NULL)
    {
      EnQueue(Q, p->rchild);
    }
  }
}
// 只有一个子节点的节点
int onechild(BiTree T)
{
  int num1, num2;
  if (T == NULL)
    return 0;
  else if (T->lchild == NULL && T->rchild == NULL || T->lchild != NULL && T->rchild == NULL)
  {
    return 1 + onechild(T->lchild) + onechild(T->rchild);
  }
  else
  {
    num1 = onechild(T->lchild);
    num2 = onechild(T->rchild);
    return num1 + num2;
  }
}
// 有二个子节点的节点
int twochild(BiTree T)
{
  int num1, num2;
  if (T == NULL)
    return 0;
  else
  {
    num1 = twochild(T->lchild);
    num2 = twochild(T->rchild);
    if (T->lchild != NULL && T->rchild != NULL)
    {
      return (num1 + num2 + 1);
    }
    else
    {
      return num1 + num2;
    }
  }
}
// 二叉树的深度
int TreeDepth(BiTree T)
{
  if (T == NULL)
    return 0;
  else
  {
    int l = TreeDepth(T->lchild);
    int r = TreeDepth(T->rchild);
    return (l > r) ? (l + 1) : (r + 1);
  }
}
// 节点个数
int Nodes(BiTree T)
{
  int lNode, rNode;
  if (T == NULL)
    return 0;
  else
  {
    lNode = Nodes(T->lchild);
    rNode = Nodes(T->rchild);
    return (lNode + rNode + 1);
  }
}
// 以下考试好像不考
// 全局变量 pre 指向当前访问结点的前驱
ThreadNode *pre = NULL;
// 中序线索化二叉树T
void CreateTnThread(ThreadTree T)
{
  pre = NULL;
  if (T != NULL)
  {              // 非空二叉树才被线索化
    InThread(T); // 中序线索化二叉树
    if (pre->rchild == NULL)
    {
      pre->rtag = 1; // 处理遍历的最后一个结点
    }
  }
}
// 线索二叉树的结点
typedef struct ThreadNode
{
  ElemType data;
  struct ThreadNode *lchild, *rchild;
  int ltag, rtag; // 左右线索标志
} ThreadNode, *ThreadTree;
// // 中序遍历二叉树 一边遍历一边线索化
// void InThread(ThreadTree T)
// {
//   if (T != NULL)
//   {
//     InThread(T->lchild);
//     visit(T);
//     InThread(T->rchild);
//   }
// }
// void visit(ThreadNode *q)
// {
//   if (q->lchild == NULL)
//   { // 左子树为空，建立前驱线索
//     q->lchild = pre;
//     q->ltag = 1;
//   }
//   if (pre != NULL && pre->rchild == NULL)
//   { // 建立前驱结点的后继线索
//     pre->rchild = q;
//     pre->rtag = 1;
//   }
//   pre = q;
// }
// 简单写法：
void InThread(ThreadTree p, ThreadTree &pre) {
  if(p != NULL) {
    InThread(p->lchild, pre);
    if(p->lchild == NULL) {
      p->lchild = pre;
      p->ltag = 1;
    }
    if(pre != NULL && pre->rchild == NULL) {
      pre->rchild = p;
      pre->rtag = 1;
    }
    pre = q;
    InThread(p->rchild, pre);
  }
}
ThreadNode *pre = NULL;
// 先序线索化
void CreatePreThread(ThreadTree T)
{
  pre = NULL;
  if (T != NULL)
  {              // 非空二叉树才被线索化
    InThread(T); // 中序线索化二叉树
    if (pre->rchild == NULL)
    {
      pre->rtag = 1; // 处理遍历的最后一个结点
    }
  }
}
// 遍历二叉树 边遍历边线索化
void PreThread(ThreadTree T)
{
  if (T != NULL)
  {
    visit(T);
    if (T->ltag == 0)
    {
      PreThread(T->lchild);
    }
    PreThread(T->rchild);
  }
}
// 对上面线索二叉树的 visit
void visit(ThreadNode *q)
{
  if (q->lchild == NULL)
  { // 左子树为空，建立前驱线索
    q->lchild = pre;
    q->ltag = 1;
  }
  if (pre != NULL && pre->rchild == NULL)
  { // 建立前驱结点的后继线索
    pre->rchild = q;
    pre->rtag = 1;
  }
  pre = q;
}
int main()
{
  // 定义空树
  BiTree root = NULL;
  // 插入根节点
  root = (BiTree)malloc(sizeof(BiTNode));
  root->data = {1};
  root->lchild = NULL;
  root->rchild = NULL;
  // 插入新结点
  BiTree p = (BiTree)malloc(sizeof(BiTNode));
  p->data = {2};
  p->lchild = NULL;
  p->rchild = NULL;
  root->lchild = p;
  return 0;
}