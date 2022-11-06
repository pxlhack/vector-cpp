
#ifndef MY_VECTOR_MY_VECTOR_H
#define MY_VECTOR_MY_VECTOR_H

#include <iostream>
#include "my_iterator.h"
#include <exception>

using namespace std;

template<typename T>
class MyVector {
public:
    MyVector();

    MyVector(int capacity);

    MyVector(MyVector &vector);

    ~MyVector();

    int getCapacity() const;

    int getSize() const;

    T getValue(int pos) const;

    void pushBack(T val);

    void insert(T val, int pos);

    void erase(int pos);

    void clear();

    bool contains(T val);

    bool isEmpty();

    int indexOf(T val);

    void setValue(T val, int pos);

    void removeByValue(T val);

    MyIterator<T> begin() { return array; }

    MyIterator<T> end() { return array + size; }

    MyReverseIterator<T> rbegin() { return array + size - 1; }

    MyReverseIterator<T> rend() { return array - 1; }

    MyVector<T> &operator=(const MyVector<T> &myVector);

    friend bool operator==(MyVector<T> &x, MyVector<T> &y) {
        if (x.getSize() != y.getSize())
            return false;

        for (int i = 0; i < x.getSize(); ++i) {
            if (x.getValue(i) != y.getValue(i))
                return false;
        }
        return true;
    }

    friend std::ostream &operator<<(std::ostream &out, MyVector<T> &myVector) {
        out << myVector.toString();
        return out;
    };

    int getPreviousOperationValuesCount() const;

private:
    int capacity;
    int size = 0;
    T *array = nullptr;
    int previousOperationValuesCount;

    std::string toString();

    void increaseCapacity();
};


#endif //MY_VECTOR_MY_VECTOR_H
