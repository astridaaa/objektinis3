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

    // TODO: vector initialization dar galimai testavimui reikes bet siaip visur puchbacka naudoju

    ~Vector(){capacity=0; size=0; delete[] vec;}

    //copy constructor | rule of 5
    Vector(const Vector& v): vec(v.vec), capacity(v.capacity), size(v.vec) {}
    
    //copy assignment operator | rule of 5
    Vector &operator=(const Vector& v){
        if(this!=&v){
            vec=v.vec;
            capacity=v.capacity;
            size=v.size;
        }return *this;
    }
    
    //move constructor | rule of 5 (galimai neveiks destruktorius ir reikes clear nes pointes involved)
    Vector(Vector &&v) : vec(std::move(v.vec)), capacity(std::move(v.capacity)), size(std::move(v.size)){~Vector();}

    //move assignment operator | rule of 5
    Vector &operator=(Vector &&v){
        if(this!=v){
            vec=std::move(v.vec);
            capacity=std::move(v.capacity);
            size=std::move(v.size);
        }return *this;
        ~Vector();
    }


}

#endif


bool empty(){
    return size == 0;
}