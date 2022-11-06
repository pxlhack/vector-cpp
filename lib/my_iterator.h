#ifndef MY_VECTOR_MY_ITERATOR_H
#define MY_VECTOR_MY_ITERATOR_H

template<typename T>
class MyIterator {
public:
    MyIterator() {}

    MyIterator(T *first) : cur(first) {}

    T &operator+(int n) { return *(cur + n); }

    T &operator-(int n) { return *(cur - n); }

    T operator++(int) { return *cur++; }

    T &operator--(int) { return *cur--; }

    T &operator++() { return *++cur; }

    T &operator--() { return *--cur; }

    bool operator==(const MyIterator &it) { return cur == it.cur; }

    bool operator!=(const MyIterator &it) { return !(cur == it.cur); }

    T &operator*() { return *cur; }

private:
    T *cur;
};

template<typename T>
class MyReverseIterator {
public:
    MyReverseIterator(T *last) : cur(last) {}

    T &operator+(int n) { return *(cur - n); }

    T &operator-(int n) { return *(cur + n); }

    T operator++(int) { return *cur--; }

    T &operator--(int) { return *cur++; }

    T &operator++() { return *--cur; }

    T &operator--() { return *++cur; }


    bool operator!=(const MyReverseIterator &it) { return cur != it.cur; }

    bool operator==(const MyReverseIterator &it) { return cur == it.cur; }

    T &operator*() { return *cur; }

private:
    T *cur;
};


#endif //MY_VECTOR_MY_ITERATOR_H
