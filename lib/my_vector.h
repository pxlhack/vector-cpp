
#ifndef MY_VECTOR_MY_VECTOR_H
#define MY_VECTOR_MY_VECTOR_H

#include <iostream>
#include "my_iterator.h"

using namespace std;

template<typename T>
class MyVector {
public:
    MyVector();

    MyVector(int capacity);

    MyVector(MyVector &vector);

    ~MyVector();

    void init_vector(int init_capacity);

    int size() const;

    int capacity();

    void clear();

    bool is_empty();

    bool contains(T const &elem);

    int index_of(T const &elem);

    T get(int index) const;

    void push_back(T const &elem);

    void set(const T &elem, int index);

    void insert(T elem, int index);

    void remove(T const &elem);

    void erase(int index);

    std::string toString();

    friend bool operator==(MyVector<T> &x, MyVector<T> &y) {
        if (x.size() != y.size())
            return false;

        for (int i = 0; i < x.size(); ++i) {
            if (x.get(i) != y.get(i))
                return false;
        }
        return true;
    }

    friend bool operator!=(MyVector<T> &x, MyVector<T> &y) {
        return !(x == y);
    }

    friend std::ostream &operator<<(std::ostream &out, MyVector<T> &myVector) {
        out << myVector.toString() << std::endl;
        return out;
    };

    friend std::istream &operator>>(std::istream &in, MyVector<T> &myVector) {
        T *obj = new T;
        in >> *obj;
        myVector.pushBack(*obj);
        delete obj;
        return in;
    }

    MyIterator<T> begin() { return array; }

    MyIterator<T> end() { return array + size_; }

    MyReverseIterator<T> rbegin() { return array + size_ - 1; }

    MyReverseIterator<T> rend() { return array - 1; }


private:
    int capacity_;
    int size_;
    T *array;

    void resize();
};


#endif //MY_VECTOR_MY_VECTOR_H
