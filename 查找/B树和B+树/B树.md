# B树的相关概念

## 树的特点

> B树，又称多路平衡查找树，B树中所被允许的孩子个数的最大值称为B树的阶，通常用m表示。一棵m阶B树或为空树，或为满足如下特性的m叉树：

1. 树中每个结点至多有$m$棵子树，即至多含有 $m-1$ 个关键字。
2. 若根结点不是终端结点，则至少有两棵子树（保证绝对平衡）。
3. 除根结点外的所有非叶结点至少有 $\lceil m / 2\rceil$ 棵子树，即至少含有$\lceil m / 2\rceil - 1$个关键字。
4. 所有的叶结点都出现在同一层次上，并且不带信息（可以视为外部结点或类似于折半查找判定树的查找失败结点，实际上这些结点不存在，指向这些结点的指针为空）。
5. B树节点的指针域的范围要求

## B树的高度

### 含n个关键字的m阶B树的最小高度

> 让其尽可能的满，即每一个B树节点都有$m$个分叉，$m-1$个关键字
> $\displaystyle n\leqslant(m-1)(1 + m + m^2 + m^3 +...+m^{h-1}) = (m-1)\frac{1-m^h}{1-m} = m^h-1$

所以$h\geqslant\log_m(n+1)$

### 含n个关键字的m阶B树的最大高度

>  让每一个尽可能的少分叉，即根节点有1个关键字，2个分叉，非根节点$\lceil m / 2\rceil - 1$个关键字，$\lceil m / 2\rceil$个孩子节点（分叉）

**注意**：$n$个关键字的B树必有$n+1$个叶子结点，因为$n$个关键字将数切分为$n+1$个区间

#### 解法一

|             |        最少节点数         |                 最少关键字数                  |
| :---------: | :-----------------------: | :-------------------------------------------: |
|  第 $1$ 层  |            $1$            |                      $1$                      |
|  第 $2$ 层  |            $2$            |            $2(\lceil m/2\rceil-1)$            |
|  第 $3$ 层  |    $2\lceil m/2\rceil$    |    $2\lceil m/2\rceil(\lceil m/2\rceil-1)$    |
|  第 $4$ 层  |   $2\lceil m/2\rceil^2$   |   $2\lceil m/2\rceil^2(\lceil m/2\rceil-1)$   |
|     ...     |            ...            |                      ...                      |
|  第 $h$ 层  | $2\lceil m/2\rceil^{h-2}$ | $2\lceil m/2\rceil^{h-2}(\lceil m/2\rceil-1)$ |
| 第 $h+1$ 层 | $2\lceil m/2\rceil^{h-1}$ | $2\lceil m/2\rceil^{h-1}(\lceil m/2\rceil-1)$ |

$h$层$m$阶B树至少包含关键字总数$\displaystyle1+2(k-1)(1 + k + k^2 + ... + k^{h-2}) = 1 + 2(k^{h-1}-1)$

若关键字总数少于这个值，则高度一定小于$h$，因此$n \geqslant 1+ 2(k^{h-1}-1)$

则$\displaystyle h \leqslant \log_k \frac{n+1}{2} + 1 = \log_{\lceil m / 2 \rceil}\frac{n+1}{2}+1$

#### 解法2

## B树的结构

```c
typedef int ElemType;
// 定义一个5阶B树
// 定义方法1：
typedef struct BTreeNode
{
    int key_num;
    struct BTreeNode* first_child;
    ElemType first_key;
    struct BTreeNode* second_child;
    ElemType second_key;
    struct BTreeNode* third_child;
    ElemType third_key;
    struct BTreeNode* forth_child;
    ElemType fourth_key;
    struct BTreeNode* fifth_child;
} BTreeNode, *BTree;

// 定义方法2：
typedef struct BTreeNode
{
    int key_num;
    ElemType key_array[4];
    struct BTreeNode child_array[5];
} BTreeNode, *BTree;
```

# B树的插入

查看PDF

# B树的删除

查看PDF
