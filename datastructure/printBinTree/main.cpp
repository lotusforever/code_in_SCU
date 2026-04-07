#include <iostream>
#include <string>
using namespace std;

template <class ElemType>
class LinkStack; // 声明有一个LIKNstack模板类

template <class ElemType>
class Node
{
    friend class LinkStack<ElemType>;

protected:
    Node<ElemType> *next;
    ElemType data;

public:
    Node();                                        // 默认构造函数
    Node(const ElemType &e, Node<ElemType> *next); // 有参构造函数
    virtual ~Node();                               // 析构函数
};

template <class ElemType>
Node<ElemType>::Node()
{
    next = NULL;
}

template <class ElemType>
Node<ElemType>::Node(const ElemType &e, Node<ElemType> *next)
{
    data = e;
    this->next = next;
}

template <class ElemType>
Node<ElemType>::~Node() = default;
//声明NOde

template <class ElemType>
class LinkStack
{
protected:
    Node<ElemType> *top;
    int count;

public:
    LinkStack();           // 默认构造函数；
    virtual ~LinkStack();  // 虚析构函数
    int Length() const;    // 获取链式栈的长度
    bool Empty() const;    // 判断链式栈是否为空
    void Clear();          // 清空链式栈
    void Traverse() const; // 遍历打印链式栈
    // void Print() const;//打印链式栈
    bool Push(const ElemType &e);                                      // 将元素e压入栈
    bool Pop(ElemType &e);                                             // 栈顶元素出栈传入e
    bool Pop();                                                        // 删除栈顶元素
    bool Top(ElemType &e) const;                                       // 获取栈顶元素传入e
    LinkStack(const LinkStack<ElemType> &source);                      // 复制构造函数模板
    LinkStack<ElemType> &operator=(const LinkStack<ElemType> &source); // 赋值符运算重载模板
};

template <class ElemType>
LinkStack<ElemType>::LinkStack()
{
    top = NULL;
    count = 0;
}

template <class ElemType>
LinkStack<ElemType>::~LinkStack()
{
    Clear();
}

template <class ElemType>
int LinkStack<ElemType>::Length() const
{
    return count;
}

template <class ElemType>
bool LinkStack<ElemType>::Empty() const
{
    return count == 0; // 编译器通过判断count是否为0来返回对应的布尔值
}

template <class ElemType>
void LinkStack<ElemType>::Clear()
{
    while (!Empty())
    {
        Pop();
    }
}

template <class ElemType>
void LinkStack<ElemType>::Traverse() const
{
    // 从栈底向栈顶遍历；
    if (!Empty())
    {
        LinkStack<ElemType> temp;     // 提供一个临时的链式栈通过出栈操作来将目标栈逆序
        Node<ElemType> *temPtr = top; // 创建一个新的指针和原来top指向同一块内存，但是是两个指针变量
        while (temPtr != NULL)
        {
            temp.Push(temPtr->data);
            temPtr = temPtr->next; // 修改的是temptr，不影响top（符合const定义）
        }
        cout << "此时栈中的情况为（从栈底向栈顶）：";
        ElemType e;
        while (!temp.Empty())
        {
            temp.Pop(e); // 输出e时顺便删除该节点；
            cout << e << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "该栈为空！" << endl;
    }
}

template <class ElemType>
bool LinkStack<ElemType>::Push(const ElemType &e)
{
    Node<ElemType> *newTop = new Node<ElemType>(e, top);
    top = newTop;
    count++;
    return true;
}

template <class ElemType>
bool LinkStack<ElemType>::Pop(ElemType &e)
{
    if (!Empty())
    {
        Node<ElemType> *temPtr = top->next; // 临时存放新的top值，防止被提前释放掉
        Node<ElemType> *oldTop = top;       // 保存现在的top，方便释放内存
        e = top->data;
        top = temPtr; // 更新top值
        delete oldTop;
        count--;
        return true;
    }
    else
        return false;
}

template <class ElemType>
bool LinkStack<ElemType>::Pop()
{
    // 删除栈顶元素，不要求保存；
    if (!Empty())
    {
        Node<ElemType> *temPtr = top->next; // 临时存放新的top值，防止被提前释放掉
        Node<ElemType> *oldTop = top;       // 保存现在的top，方便释放内存
        top = temPtr;                       // 更新top值
        delete oldTop;
        count--;
        return true;
    }
    else
        return false;
}

template <class ElemType>
bool LinkStack<ElemType>::Top(ElemType &e) const
{
    if (!Empty())
    {
        e = top->data;
        return true;
    }
    else
        return false;
}

template <class ElemType>
LinkStack<ElemType>::LinkStack(const LinkStack<ElemType> &source)
{
    top = nullptr;
    count = 0;
    ElemType *arr = new ElemType[source.count];
    Node<ElemType> *current = source.top;
    for (int i = source.count - 1; i >= 0; i--)
    {
        arr[i] = current->data;
        current = current->next;
    }
    for (int i = 0; i < source.count; i++)
    {
        Push(arr[i]);
    }
    delete[] arr;
}

template <class ElemType>
LinkStack<ElemType> &LinkStack<ElemType>::operator=(const LinkStack<ElemType> &source)
{
    if (this != &source)
    {            // 防止自己给自己赋值
        Clear(); // 清空当前栈；
        top = nullptr;
        count = 0;
        ElemType *arr = new ElemType[source.count];
        Node<ElemType> *current = source.top;
        for (int i = source.count - 1; i >= 0; i--)
        {
            arr[i] = current->data;
            current = current->next;
        }
        for (int i = 0; i < source.count; i++)
        {
            Push(arr[i]);
        }
        delete[] arr;
    }
    return *this;
}
//声明链式栈；

struct TreeNode{
    char data;
    TreeNode *left;
    TreeNode *right;
    int level;

    TreeNode(char str,int val) : data(str), left(nullptr), right(nullptr), level(val) {}
};

LinkStack<TreeNode *> ls;

void InOrderInStack(TreeNode* root){
    if(root==nullptr)
        return;
    InOrderInStack(root->left);
    ls.Push(root);
    InOrderInStack(root->right);
}

void printBinTree(LinkStack<TreeNode*>& ls){
    TreeNode *str;
    ls.Pop(str);
    while(str!=nullptr){
    for (int i = 0; i < str->level;i++){
        cout <<' ';
    }
    cout << str->data << endl;
    ls.Pop(str);
}
}

int main(){
    TreeNode* root=new TreeNode('a',0);
    root->left = new TreeNode('b',1);
    root->right = new TreeNode('c',1);
    root->left->right = new TreeNode('d',2);
    root->right->left = new TreeNode('e',2);
    //构造图示二叉树

    //向左旋转90°打印，按照中序将二叉树压入栈中，达到最右子树在第一行输出，根节点在中间输出，最左子树在最下面输出的效果；再根据层数确定需要输出空格的数量；

    InOrderInStack(root);
    printBinTree(ls);

    return 0;
}