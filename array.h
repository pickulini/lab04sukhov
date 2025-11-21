#pragma once
#include <memory>
#include <stdexcept>

template<typename T>
class Array {
private:
    std::shared_ptr<T[]> data;
    size_t capacity_;
    size_t size_;
    
    void resize(size_t new_capacity) {
        std::shared_ptr<T[]> new_data(new T[new_capacity]);
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = std::move(data[i]);
        }
        data = new_data;
        capacity_ = new_capacity;
    }
public:
    Array() : data(new T[1]), capacity_(1), size_(0) {}
    
    void push_back(T value) {
        if (size_ >= capacity_) {
            resize(capacity_ * 2);
        }
        data[size_++] = std::move(value);
    }
    
    void erase(size_t index) {
        if (index >= size_) throw std::out_of_range("Index out of range");
        for (size_t i = index; i < size_ - 1; ++i) {
            data[i] = std::move(data[i + 1]);
        }
        --size_;
    }
    
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    
    class Iterator {
    private:
        T* ptr;
    public:
        Iterator(T* p) : ptr(p) {}
        T& operator*() { return *ptr; }
        Iterator& operator++() { ++ptr; return *this; }
        bool operator!=(const Iterator& other) { return ptr != other.ptr; }
    };
    
    Iterator begin() { return Iterator(data.get()); }
    Iterator end() { return Iterator(data.get() + size_); }
};
