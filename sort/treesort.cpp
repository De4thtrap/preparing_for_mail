#include <assert.h>
#include <iostream>

template <typename T = int>
class node
{
public:
    node(T val = 0);
   ~node();
    T data_;
    node *left_;
    node *right_;
    node *parent_;
    void print();
};

template <typename T>
node<T>::node(T val):
    data_(val),
    left_(nullptr),
    right_(nullptr),
    parent_(nullptr)
    {}

template <typename T>
node<T>::~node()
{
    if (this->left_)
        delete this->left_;
    if (this->right_)
        delete this->right_;
}

template <typename T>
void node<T>::print()
{
    if (this->left_)
        this->left_->print();
    std::cout << this->data_ << " ";
    if (this->right_)
        this->right_->print();
}


template <typename T = int>
class tree
{
public:
    tree(T *arr, int count);
    tree();
   ~tree();
    node<T> *root_;
    void add(node<T> *new_node);
    void print();
};

template <typename T>
tree<T>::tree(T *arr, int count)
{
    assert(count > 0);
    assert(arr);
    this->root_ = new node<T>(*arr);
    for (int i = 1; i < count; ++i)
    {
        node<T> *new_node = new node<T>(arr[i]);
        this->add(new_node);
    }
}

template <typename T>
tree<T>::tree():
    root_(nullptr)
    {}

template <typename T>
tree<T>::~tree()
{
    if (this->root_)
        delete this->root_;
}

template <typename T>
void tree<T>::print()
{
    if (this->root_)
    {
        this->root_->print();
        std::cout << "\n";
    }
}

template <typename T>
void tree<T>::add(node<T> *new_node)
{
    assert(new_node);
    if (!this->root_)
    {
        this->root_ = new_node;
        return;
    }

    T data = new_node->data_;
    node<T> *cur_node = this->root_;
    node<T> *prev_node = nullptr;

    while (cur_node)
    {
        prev_node = cur_node;
        if (data < cur_node->data_)
            cur_node = cur_node->left_;
        else
            cur_node = cur_node->right_;
    }

    if (data < prev_node->data_)
        prev_node->left_ = new_node;
    else
        prev_node->right_ = new_node;
    new_node->parent_ = prev_node;
}


int main(int argc, char const *argv[])
{
    assert(argc > 1);
    int count = atoi(argv[1]);
    int arr[count] = {};

    FILE *file = fopen("rand.txt", "r");
    for (int i = 0; i < count; ++i)
        fscanf(file, "%d", &arr[i]);

    tree<> tr(arr, count);
    //tr.print();

    fclose(file);
    return 0;
}