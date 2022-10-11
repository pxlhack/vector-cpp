
#ifndef MY_VECTOR_MY_VECTOR_H
#define MY_VECTOR_MY_VECTOR_H

#include <iostream>

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


    friend bool operator []()

    friend bool operator==(MyVector<T> &x, MyVector<T> &y);

    friend bool operator!=(MyVector<T> &x, MyVector<T> &y);

    class Iterator {
    public:
        Iterator(T *first) : cur(first) {}

        T &operator+(int n) { return *(cur + n); }

        T &operator-(int n) { return *(cur - n); }

        T operator++(int) { return *cur++; }

        T &operator--(int) { return *cur--; }

        T &operator++() { return *++cur; }

        T &operator--() { return *--cur; }


        bool operator!=(const Iterator &it) { return cur != it.cur; }

        bool operator==(const Iterator &it) { return cur == it.cur; }

        T &operator*() { return *cur; }

    private:
        T *cur;
    };

private:
    int capacity_;
    int size_;
    T *array;

    void resize();
};


#endif //MY_VECTOR_MY_VECTOR_H
