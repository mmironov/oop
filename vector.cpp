//
//  vector.cpp
//  Vector
//
//  Created by Miroslav Mironov on 4/22/15.
//  Copyright (c) 2015 Miroslav Mironov. All rights reserved.
//

#include "vector.h"
#include <iostream>
using namespace std;

Vector::Vector()
{
    size = 0;
    capacity = 16;
    
    elements = new int[capacity];
}

void Vector::copy(const Vector& other)
{
    size = other.size;
    capacity = other.capacity;
    
    elements = new int[capacity];
    
    for(int i=0; i < size; ++i)
    {
        elements[i] = other.elements[i];
    }
}

void Vector::del()
{
    delete [] elements;
}

Vector::Vector(const Vector& other)
{
    copy(other);
}

Vector& Vector::operator=(Vector& vector)
{
    if (this != &vector)
    {
        del();
        copy(vector);
    }
    
    return *this;
}

Vector::~Vector()
{
    del();
}

void Vector::add(int element)
{
    if (size >= capacity)
    {
        //resizing + copying
        extend();
    }
    
    elements[size] = element;
    ++size;
}

void Vector::extend()
{
    resize(capacity * 2);
}

void Vector::resize(int capacity)
{
    int* resized = new int[capacity];
    
    this->capacity = capacity;
    
    for(int i=0; i < size; ++i)
    {
        resized[i] = elements[i];
    }
    
    delete [] elements;
    
    elements = resized;
}

int Vector::get(int index) const
{
    return elements[index];
}

void Vector::print() const
{
    cout << "[";
    
    for(int i=0; i < size; ++i)
    {
        cout << elements[i];
        
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    
    cout << "]";
}

void Vector::removeAt(int index)
{
    if (index < 0 || index >= size)
    {
        return;
    }
    
    for(int i=index; i < size - 1; ++i)
    {
        elements[i] = elements[i + 1];
    }
    
    --size;
    
    if (size < capacity / 4)
    {
        resize(capacity/2);
    }
}
