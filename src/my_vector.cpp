#include "../lib/my_vector.h"


template<typename T>
MyVector<T>::MyVector(int capacity) {
    init_vector(capacity);
}

template<typename T>
MyVector<T>::MyVector(MyVector &vector) {
    init_vector(vector.size());
    for (int i = 0; i < vector.size(); ++i) {
        push_back(vector.get(i));
    }
}

template<typename T>
MyVector<T>::~MyVector() {
    delete[] this->array;
}

template<typename T>
void MyVector<T>::init_vector(int init_capacity) {
    this->size_ = 0;
    this->capacity_ = init_capacity;
    this->array = new T[init_capacity];
}

template<typename T>
int MyVector<T>::size() const {
    return this->size_;
}

template<typename T>
int MyVector<T>::capacity() {
    return this->capacity_;
}

template<typename T>
void MyVector<T>::clear() {
    this->capacity_ = 0;
    this->size_ = 0;
}

template<typename T>
bool MyVector<T>::is_empty() {
    return this->size_ == 0;
}

template<typename T>
T MyVector<T>::get(int index) const {
    if (index >= this->size_)
        throw "Error!\nOut of range\n";
    return this->array[index];
}

template<typename T>
void MyVector<T>::set(T const &item, int index) {

    if (index > this->size_)
        throw "Error!\nOut of range\n";
    this->array[index] = item;
}

template<typename T>
void MyVector<T>::push_back(T const &item) {
    count = 1;
    if (this->size_ >= this->capacity_) {
        resize();
        count += size();
    }

    set(item, this->size_);
    this->size_++;
}

template<typename T>
void MyVector<T>::resize() {
    T *newArray = new T[this->capacity_ + 1];
    for (int i = 0; i < this->size_; ++i) {
        newArray[i] = array[i];
    }

    this->capacity_++;

    delete[] this->array;
    this->array = newArray;
}

template<typename T>
MyVector<T>::MyVector() {
    init_vector(1);
}

template<typename T>
bool MyVector<T>::contains(const T &item) {
    if (index_of(item) == -1) return false;
    return true;
}

template<typename T>
int MyVector<T>::index_of(T const &item) {
    for (int i = 0; i < this->size_; ++i) {
        if (this->array[i] == item) {
            count = i + 1;
            return i;
        }
    }
    count = size();
    return -1;
}

template<typename T>
void MyVector<T>::insert(T item, int index) {
    count = 0;
    if (index > this->size_) {
        throw "Error!\nOut of range\n";
    }


    if (index < this->size_) {
        if (this->size_ >= this->capacity_) {
            count = size();
            resize();
        }
        cout << count << endl;
        for (int i = this->size_; i > index; --i) {
            this->array[i] = this->array[i - 1];
        }
        set(item, index);
        count += size() - index + 1;
        // 7 = 10 - 4 + 1
        cout << count << endl;
        this->size_++;
    }

    if (index == this->size_) {
        push_back(item);
    }
}

template<typename T>
void MyVector<T>::remove(const T &item) {
    int index = index_of(item);
    erase(index);
}

template<typename T>
void MyVector<T>::erase(int index) {
    if (index > this->size_) {
        throw "Error!\nOut of range\n";
    }

    for (int i = index; i < this->size_; ++i) {
        this->array[i] = this->array[i + 1];
    }
    this->size_--;
}

template<typename T>
std::string MyVector<T>::toString() {
    std::string string;
    for (int i = 0; i < this->size_; ++i) {
        string += std::to_string(this->array[i]);
        string += " ";
    }
    return string;
}

template<typename T>
MyVector<T> &MyVector<T>::operator=(const MyVector<T> &myVector) {
    if (this == &myVector) {
        return *this;
    }

    int newSize = myVector.size();
    delete[] this->array;
    this->array = new T[newSize];
    for (int i = 0; i < newSize; ++i) {
        this->array[i] = myVector.get(i);
    }
    this->capacity_ = newSize;
    this->size_ = newSize;
    return *this;
}

template<typename T>
int MyVector<T>::getCount() const {
    return count;
}

template<typename T>
void MyVector<T>::setCount(int count) {
    MyVector::count = count;
}


template
class MyVector<int>;