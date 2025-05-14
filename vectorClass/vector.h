#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef> 
#include <utility>    
#include <algorithm>  
#include <stdexcept>  



template <typename T> class Vector{

    private:
    T* vec; 
    size_t capacity; 
    size_t size;

    public:
    Vector() = vec(nullptr), capacity(0), size(0) {} 
    Vector(size_t Size): size(Size), capacity(Size){ 
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

    //max size 

    bool empty(){return size==0;}

    bool operator==(const Vector &vv){
        if(size != vv.size()){return false;}
        for (auto i = 0; i < size; ++i){
            if(vec[i] != vv[i]){
                return false;}}
        return true;
    }

    //assign

    //assign range 

    //front

    //back
    
    bool operator!=(const Vector& vv)const{
        return !(*this == vv);
    }

    T &operator[](size_t index){
        if(index>size){
            throw std::exception("index out of range");
        }
        return vec[index];
    }

    T* end(){return vec+size;}

    T* begin(){return vec;}

    //cbegin - iterator cannot modify the value of the element it is pointing to (c)

    //cend

    void push_back(const T &ent){
        if(size>=capacity){
            T* Nvec = new T[capacity*2];
            std::copy(vec, vec+size, Nvec);
            delete[] vec;
            vec = Nvec;
            capacity*=2;
        }
        vec[size++]=ent;
    }
    
    void pop_back(const T &ent){
        if(size==0){throw std::exception("nothing to remove");}
        --size;
    }

    size_t at(const size_t index){
        if(index>=size || index<0){throw std::exception("index out of range");}
        return vec[index];
    }

    void clear(){
        delete[] vec;
        vec=nullptr;
        size=0;
        capacity=0;
    }

    void shrink_to_fit(){ // siaip su resize galejau
        if(size==capacity) {return;}
        T* Nvec= new T[size];
        std::move(vec, vec+size, Nvec);
        delete[] vec;
        vec=Nvec;
        capacity=size;
    }
    //reserve
    
    //insert

    //insert range

    //erase

    //append range

    //resize

    //swap


};

#endif
