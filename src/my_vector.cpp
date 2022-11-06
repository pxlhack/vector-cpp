#include "../lib/my_vector.h"

template<typename T>
MyVector<T>::MyVector() {
    this->capacity = 0;
}

template<typename T>
MyVector<T>::MyVector(int capacity) {
    this->capacity = capacity;
    this->array = new T[capacity];
}

template<typename T>
MyVector<T>::MyVector(MyVector &vector) {
    this->capacity = vector.size;
    this->array = new T[vector.size];

    for (int i = 0; i < vector.getSize(); ++i) {
        this->pushBack(vector.getValue(i));
    }
}

template<typename T>
MyVector<T>::~MyVector() {
    if (this->array != nullptr) delete[] this->array;
}

template<typename T>
int MyVector<T>::getSize() const {
    return this->size;
}

template<typename T>
int MyVector<T>::getCapacity() const {
    return this->capacity;
}

template<typename T>
void MyVector<T>::clear() {
    delete[] this->array;
    this->capacity = 0;
    this->size = 0;
    this->array = nullptr;
}

template<typename T>
bool MyVector<T>::isEmpty() {
    return this->size == 0;
}

template<typename T>
T MyVector<T>::getValue(int pos) const {
    if (pos >= this->size || pos < 0) {
        throw "Error: Out of range\n";
    }
    return this->array[pos];
}

template<typename T>
void MyVector<T>::setValue(T val, int pos) {
    if (pos >= this->size || pos < 0) {
        throw "Error: Out of range\n";
    }
    this->array[pos] = val;
}

template<typename T>
void MyVector<T>::pushBack(T val) {
    this->insert(val, this->size);
}

template<typename T>
void MyVector<T>::increaseCapacity() {
    this->capacity++;

    if (this->array == nullptr) {
        this->array = new T[this->capacity];
    } else {
        T *newArray = new T[this->capacity];

        for (int i = 0; i < this->size; ++i) {
            this->previousOperationValuesCount++;
            newArray[i] = array[i];
        }

        delete[] this->array;
        this->array = newArray;
    }
}

template<typename T>
bool MyVector<T>::contains(T val) {
    this->previousOperationValuesCount = 0;
    if (indexOf(val) == -1) return false;
    return true;
}

template<typename T>
int MyVector<T>::indexOf(T val) {
    for (int i = 0; i < this->size; ++i) {
        this->previousOperationValuesCount++;
        if (this->array[i] == val) {
            return i;
        }
    }
    return -1;
}

template<typename T>
void MyVector<T>::insert(T val, int pos) {
    if (pos > this->size || pos < 0) {
        throw "Error: Out of range\n";
    }

    this->previousOperationValuesCount = 0;

    if (this->size >= this->capacity) {
        this->increaseCapacity();
    }

    if (pos < this->size) {
        for (int i = this->size; i > pos; --i) {
            this->previousOperationValuesCount++;
            this->array[i] = this->array[i - 1];
        }
    }

    this->array[pos] = val;
    this->size++;
    this->previousOperationValuesCount++;
}

template<typename T>
void MyVector<T>::removeByValue(T val) {
    int pos = indexOf(val);
    if (pos != -1) {
        erase(pos);
    }
}

template<typename T>
void MyVector<T>::erase(int pos) {
    if (pos >= this->size || pos < 0) {
        throw "Error: Out of range\n";
    }

    this->previousOperationValuesCount = 0;

    for (int i = pos; i < this->size; ++i) {
        this->previousOperationValuesCount++;
        this->array[i] = this->array[i + 1];
    }

    this->size--;
}

template<typename T>
std::string MyVector<T>::toString() {
    std::string string;
    for (int i = 0; i < this->size; ++i) {
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

    int newSize = myVector.getSize();
    delete[] this->array;
    this->array = new T[newSize];
    for (int i = 0; i < newSize; ++i) {
        this->array[i] = myVector.getValue(i);
    }
    this->capacity = newSize;
    this->size = newSize;
    return *this;
}

template<typename T>
int MyVector<T>::getPreviousOperationValuesCount() const {
    return previousOperationValuesCount;
}

template
class MyVector<int>;