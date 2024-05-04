#pragma once

#include "iostream"

template <typename T> class Vector{
public:
    Vector() : capacity{initialCapacity}, size{0}, vector{new T[capacity]} {}

    Vector(const Vector& toCopy) {
        vector = new T[capacity];
        *this = toCopy;
    }

    void operator=(const Vector& toCopy) {
        for (size_t i=0; i<toCopy.getSize(); i++)
            vector[i] = toCopy[i];
        size = toCopy.getSize();
    }

    ~Vector() {
        delete[] vector;
    }

    void add(const T &item) {
        if (size==capacity+1) {
            resize(capacity*2);
        }
        vector[size++] = item;
    }

    void remove(const T &item) {
        T *temp = new T[size-1];
        for (size_t i=0, j=0; i<getSize(); i++) {
            if (vector[i]!=item) {
                temp[j++] = vector[i];
            }
        }

        size--;

        delete []vector;
        vector = temp;
    }

    void print() const {
        for (size_t i=0; i<getSize(); i++) {
            std::cout << vector[i] << " ";
        }
        std::cout << std::endl;
    }

    int getCapacity() const {
        return capacity;
    }
    int getSize() const {
        return size;
    }

    const T& operator[](size_t index) const {
        return vector[index];
    }

    /* To Access and Update Elements */
    T& operator[](size_t index) {
        return vector[index];
    }


private:
    size_t size;
    size_t capacity;
    static size_t initialCapacity;

    T* vector;

    void resize(size_t newCapcity)
    {
        T* temp = new T[capacity=newCapcity];
        for (size_t i =0; i<getSize(); ++i) {
            temp[i] = vector[i];
        }
        delete[] vector;
        vector = temp;
    }
};

template <typename T> size_t Vector<T>::initialCapacity = 20;