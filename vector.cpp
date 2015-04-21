//
//  vector.cpp
//  Vector
//
//  Created by Miroslav Mironov on 4/22/15.
//  Copyright (c) 2015 Miroslav Mironov. All rights reserved.
//

#include "vector.h"

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