#ifndef VECTOR_H
#define VECTOR_H

template <typename T> class Vector{

    private:
    T* vec; 
    size_t capacity; 
    size_t size;

    public:
    Vector() = vec(nullptr), capacity(0), size(0) {} //constructor
    Vector(size_t Size): size(Size), capacity(Size){ //with initial size
        vec = new T[capacity];
    }
    //vector initialization dar galimai testavimui reikes bet siaip visur puchbacka naudoju

    ~Vector(){capacity=0; size=0; delete[] vec;}

    //copy constructor
    Vector(const Vector& v): vec(v.vec), capacity(v.capacity), size(v.vec) {
        vec = new T[capacity];
        std::copy(v.vec, v.vec+size, vec);}
    
    //copy assignment operator 
    Vector &operator=(const Vector& v){
        if(this!=&v){
            delete[] vec;
            size=v.size;
            capacity=v.capacity;
            vec=new T[capacity];
            std::copy(v.vec, v.vec+size, vec);
        }return *this;}
    
    //move constructor
    Vector(Vector &&v) : vec(std::move(v.vec)), capacity(std::move(v.capacity)), size(std::move(v.size)){~Vector();}

    //move assignment operator
    Vector &operator=(Vector &&v){
        if(this!=v){
            delete[] vec;
            vec=std::move(v.vec);
            capacity=std::move(v.capacity);
            size=std::move(v.size);
        }return *this;
        ~Vector();}

    size_t size()const{return this->size;}

    size_t capacity()const{return this->capacity;}

    bool empty(){return size==0;}

    bool operator==(const Vector &vv){
        if(size != vv.size()){return false;}
        for(auto i : size){
            if(vec[i] != vv[i]){
                return false;}}
        return true;
    }
    
    bool operator!=(const Vector& vv)const{
        return !(*this == vv);
    }

    void push_back(size_t &ent){
        if(size>=capacity){
            size_t* Nvec = new size_t[capacity*2];
            std::copy(vec, vec+size, Nvec);
            delete[] vec;
            vec = Nvec;
            capacity*=2;
        }
        vec[size++]=ent;
    }
    //gal gerai kiek yra netikrinau
    
};

#endif
