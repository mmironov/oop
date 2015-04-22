//
//  vectkr.h
//  Vector
//
//  Created by Miroslav Mironov on 4/22/15.
//  Copyright (c) 2015 Miroslav Mironov. All rights reserved.
//

#ifndef VECTOR_H
#define VECTOR_H

class Vector {
    int* elements;
    int size;
    int capacity;
    
    void copy(const Vector& other);
    void del();
    void extend();
    void resize(int capacity);
public:
    Vector();
    Vector(const Vector& other);
    ~Vector();
    Vector& operator=(Vector& vector);
    
    void add(int element);
    int get(int index) const;
    void removeAt(int index);
    void print() const;
};

#endif
