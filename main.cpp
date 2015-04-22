//
//  main.cpp
//  Vector
//
//  Created by Miroslav Mironov on 4/22/15.
//  Copyright (c) 2015 Miroslav Mironov. All rights reserved.
//

#include <iostream>
#include "vector.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    Vector v;
    v.add(1);
    v.add(50);
    v.add(100);
    
    for(int i=0; i < 5; ++i)
    {
        v.add(i * i + 20);
    }
    
    v.print();
    cout << endl;
    
    int index = 3;
    cout << "Element at index " << index << ": " << v.get(index) << endl;
    
    v.removeAt(index);
    
    v.print();
    cout << endl;
    
    return 0;
}
