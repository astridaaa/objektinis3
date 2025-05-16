#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef> 
#include <limits>
#include <utility>    
#include <algorithm>  
#include <stdexcept>  

//VISUR KUR CAPACITY DEJAU *= TAI REIKES I RESIZE PAKEISTI

//realizintos visos 39 funckijos bet ten kur su resize reikes greiciausiai tikrai kazka pakeisti

template <typename T> class Vector{
    private:
    T* vec; 
    size_t capacity; 
    size_t size;

    public:
    Vector(): vec(nullptr), capacity(0), size(0) {} 
    Vector(size_t Size): size(Size), capacity(Size){ 
        vec = new T[capacity];
    }

    Vector(std::initializer_list<T> list): size(list.size()), capacity(list.size()){
        vec=new T[size];
        std::copy(list.begin(), list.end(), vec);}

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

    size_t Size()const{return this->size;}

    T* Data() const {return vec;}

    size_t Capacity()const{return this->capacity;}

    size_t max_size(){return std::numeric_limits<T>::std::max()/sizeof(T);}

    bool empty(){return size==0;}

    bool operator==(const Vector &vv){
        if(size != vv.size()){return false;}
        for (auto i = 0; i < size; ++i){
            if(vec[i] != vv[i]){
                return false;}}
        return true;
    }

    void assign(size_t amount, T& value){
        if(amount>capacity){
            resize(amount);
        }
        std::fill_n(vec, amount, value);
        size=amount; 
    } 

    void assign(T* begin, T* end){
        size_t amount= begin-end; //std::distance alternative
        if(amount>capacity){
            resize(amount);
        };   
        std::copy(begin, end, vec);
        size=amount;
    }

    void assign(std::initializer_list<T> list){
        size=list.size();
        if(size>capacity){resize(size);}
        std::copy(list.begin(), list.end(), vec);
    }

    void append_range(std::initializer_list<T> list){//PAKEIST
        if(size+list.size()>capacity){
            reserve(size+list.size());
        }
        std::copy(list.begin(), list.end(), vec+size);
        size += list.size();
    }

    T& front(){return vec[0];}

    T& back(){return vec[size-1];}
    
    bool operator!=(const Vector& vv)const{
        return !(*this == vv);}

    T &operator[](size_t index){
        if(index>size){
            throw std::out_of_range("index out of range");
        }
        return vec[index];
    }

    T* end(){return vec+size;}
    T* begin(){return vec;}

    const T* cbegin()const{return vec;}
    const T* cend()const{return vec+size;}

    T* rbegin(){return size==0 ? nullptr : vec+size-1;}
    T* rend(){return size==0 ? nullptr: vec-1;}

    const T* crbegin()const{return size==0 ? nullptr : vec+size-1;}
    const T* crend()const{return size==0 ? nullptr: vec-1;}

    void push_back(const T &value){
        if(size>=capacity){
            reserve(capacity==0 ? 1 : capacity*2);
        }
        vec[size++]=value;
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
    
    void swap(Vector &v){
        std::swap(size, v.size);
        std::swap(capacity, v.capacity);
        std::swap(vec, v.vec);}

    void reserve(size_t Ncap){
    if(size>capacity){
        T* Nvec=new T[capacity];
        std::copy(vec, vec+size, Nvec);
        delete[] vec;
        vec=Nvec;
        capacity=Ncap;}
    }
    
    //insert single element
    void insert(T* index, T& element){
        if(index<vec || index>vec+size){
            throw std::exception("out of range");
        }
        if(size>capacity){
            resize(size);
        }
        size_t position=index-vec;
        std::copy_backward(vec+position, vec+size, vec+size+1);
        vec[position]=element;
        size++;
    }
    //GAL GERAI
    void insert(T* index, size_t times, T& element){ 
        if(index<vec || index>vec+size){
            throw std::out_of_range("position out of range");
        }
        if(size+times>capacity){
            resize(times+size);
        }
        size_t position = index-vec;
        //std::copy_backward(vec+position, vec+size);
        std::copy_backward(vec+position, vec+size, vec+size+times);
        std::fill(vec + position, vec + position + times, element);

        size+=times;
    }

    void erase(T* index){
        size_t position=index-vec;
        if(index>vec+size || position<0){throw std::out_of_range("out of range");}
        for(size_t i=position; i+1<size; i++){
            vec[i]=std::move(vec[i+1]);
        }
        size--;
    }

    void erase(T* begin, T* end){
        size_t amount= end-begin; //gali ir neveikt tai distance reikes naudoti
        size_t index=begin-vec;
        for(size_t i=index; i+amount<size; i++){
            vec[i]=std::move(vec[i+amount]);
        }
        size-=amount;
    }

    void resize(size_t newCap){
        if(newCap<size){size=newCap;}
        else
        capacity=newCap;
        T* Nvec= new T[capacity];
        std::copy(vec, vec+size, Nvec);
        delete[] vec;
        vec=Nvec;
    }

    void resize(size_t newCap, const T& element){
        if(newCap<size){size=newCap;}
        capacity=newCap;
        T* Nvec= new T[capacity];
        std::copy(vec, vec+size, Nvec);
        for(size_t i=size; i<capacity; ++i){
            Nvec[i]=element;
        }
        delete[] vec;
        vec=Nvec;
        size=newCap;
    }

    bool operator<(const Vector& v)const{
        size_t minSize = std::min(size, v.size);
        for(size_t i=0; i<minSize; ++i) {
            if(vec[i]<v.vec[i]) return true;
            if(vec[i]> v.vec[i]) return false;
        }
        return size < v.size;
    }

    bool operator<=(const Vector& v)const{
        return !(*this>v);}

    bool operator>(const Vector& v)const{
        return v<*this;}

    bool operator>=(const Vector& v)const{
        return !(*this<v);}

};

#endif
