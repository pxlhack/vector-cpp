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
        throw "Error!\nOut of range";
    return this->array[index];
}

template<typename T>
void MyVector<T>::set(T const &elem, int index) {

    if (index > this->size_)
        throw "Error!\nOut of range";
    this->array[index] = elem;
}

template<typename T>
void MyVector<T>::push_back(T const &elem) {
    if (this->size_ >= this->capacity_) {
        resize();
    }

    set(elem, this->size_);
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
bool MyVector<T>::contains(const T &elem) {
    if (index_of(elem) == -1) return false;
    return true;
}

template<typename T>
int MyVector<T>::index_of(T const &elem) {
    for (int i = 0; i < this->size_; ++i) {
        if (this->array[i] == elem) return i;
    }
    return -1;
}

template<typename T>
void MyVector<T>::insert(T elem, int index) {
    if (index > this->size_) {
        throw "Error!\nOut of range";
    }

    if (this->size_ >= this->capacity_) {
        resize();
    }

    if (index < this->size_) {
        for (int i = this->size_; i > index; --i) {
            this->array[i] = this->array[i - 1];
        }
        set(elem, index);
        this->size_++;
    }

    if (index == this->size_) {
        push_back(elem);
    }
}

template<typename T>
void MyVector<T>::remove(const T &elem) {
    int index;

    for (index = 0; this->array[index] != elem && index < this->size_; ++index);

    if (this->array[index] == elem) {
        erase(index);
    }
}

template<typename T>
void MyVector<T>::erase(int index) {
    if (index > this->size_) {
        throw "Error!\nOut of range";
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

template
class MyVector<int>;