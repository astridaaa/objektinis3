#ifndef VECTOR_H
#define VECTOR_H

template <typename T> class Vector{

    private:
    T* vec; // saugo adresa vektoriaus 
    size_t capacity; // size_t - unsigned integer type
    size_t size;

    public:

    //constructor
    Vector() = vec(nullptr), capacity(0), size(0) {}

    //with initial size
    Vector(size_t Size): size(Size), capacity(Size){
        vec = new T[capacity];
    }
    //vector initialization dar galimai testavimui reikes bet siaip visur puchbacka naudoju

    //destructor
    ~Vector(){}

}

#endif