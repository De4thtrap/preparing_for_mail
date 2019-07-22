#include <iostream>
#include <assert.h>

template <typename T = int>
class heap
{
public:
    heap(T *arr, int count);
   ~heap();
    void sift_down(int index);
    void sift_up(int index);
    int count_;
    T *arr_;  
    void sort();
    void print();
};

template <typename T>
heap<T>::heap(T *arr, int count)
{
    assert(count > 0);
    assert(arr);
    this->count_ = count;
    this->arr_ = arr;
    for (int i = count / 2; i >= 0; --i)
        this->sift_down(i);
}

template <typename T>
heap<T>::~heap()
{
    this->count_ = -1;
    this->arr_ = nullptr;
}

template <typename T>
void heap<T>::sift_up(int index)
{
    int parent = (index + 1) / 2 - 1;
    while(index && this->arr_[parent] < this->arr_[index])
    {
        std::swap(this->arr_[parent], this->arr_[index]);
        index = parent;
    }
}

template <typename T>
void heap<T>::sift_down(int index)
{
    int left  = index * 2 + 1;
    if (left >= this->count_)
        left = index;
    int right = index * 2 + 2;
    if (right >= this->count_)
        right = index;
    int change = index;
    
    if (this->arr_[left] > this->arr_[right])
        change = left;
    else
        change = right;

    if (this->arr_[change] > this->arr_[index])
    {
        std::swap(this->arr_[change], this->arr_[index]);
        this->sift_down(change);
    }
}

template <typename T>
void heap<T>::sort()
{
    int tmp_count = this->count_;
    while(this->count_)
    {
        std::swap(this->arr_[0], this->arr_[this->count_ - 1]);
        this->count_--;
        this->sift_down(0);
    }
    this->count_ = tmp_count;
}

template <typename T>
void heap<T>::print()
{
    for (int i = 0; i < this->count_; ++i)
        std::cout << this->arr_[i] << " ";
    std::cout << "\n";
}

template <typename T>
void sort(T *arr, int count)
{
    heap<T> h(arr, count);
    //h.print();
    h.sort();
    //h.print();
}


int main(int argc, char const *argv[])
{
    
    assert(argc > 1);
    int count = atoi(argv[1]);
    int arr[count] = {};

    FILE *file = fopen("rand.txt", "r");
    for (int i = 0; i < count; ++i)
        fscanf(file, "%d", &arr[i]);

    sort(arr, count);

    fclose(file);
    return 0;
}