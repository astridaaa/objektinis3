
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp" 
#include "vector.h"
#include "iostream"

TEST_CASE("Constructor", "[Constructor]"){
    Vector<int> v, v2;
    CHECK(v.Data() == nullptr);
    REQUIRE(v.Capacity()==0);
    REQUIRE(v.Size()==0);
    REQUIRE(v==v2);
}

TEST_CASE("Copy constructor", "[Copy][constructor]"){
    Vector<int> v{1,1,1};
    Vector<int>v2(v); 
    REQUIRE(v2==v);
}

TEST_CASE("Copy assignment", "[Copy][assignment]"){
    Vector<int> v{1,1,1};
    Vector<int> v2=v;
    REQUIRE(v==v2);
}

TEST_CASE("Move constructor", "[Move][constructor]"){
    Vector<int> v{1,1,1};
    Vector<int> v2(std::move(v)); 
    REQUIRE_FALSE(v==v2);
    REQUIRE(v2==Vector<int>{1,1,1});
}

TEST_CASE("Move assignment", "[Move][assignment]"){
    Vector<int> v{1,1,1}, v2;
    v2= std::move(v);
    REQUIRE_FALSE(v==v2);
    REQUIRE(v2==Vector<int>{1,1,1}); 

}

TEST_CASE("push back", "[push][back]"){
    Vector<int> v{1,1,1};
    v.push_back(7);
    v.push_back(8);
    REQUIRE(v[3]==7);
    REQUIRE(v.at(4)==8);
}

TEST_CASE("pop back", "[pop][back]"){
    Vector<int> v{1,1,1,7,8};
    v.pop_back();
    v.pop_back();
    REQUIRE(v==Vector<int>{1,1,1});
    REQUIRE(v.Size()==3);
}

TEST_CASE("front back", "[front][back]"){
    Vector<int> v{7, 1, 9};
    REQUIRE(v.front()==7);
    REQUIRE(v.back()==9);
}

TEST_CASE("append range", "[append][range]"){
    Vector<int> v{1,1,1};
    v.append_range({7,7});
    REQUIRE(v==Vector<int>{1,1,1,7,7});
    REQUIRE(v.Size()==5);
}

TEST_CASE("swap", "[swap]"){
    Vector<int> v{1,1,1};
    Vector<int> v2{2,3,4};
    v.swap(v2);
    REQUIRE(v[0]==2);
    REQUIRE(v[1]==3);
    REQUIRE(v[2]==4);
    REQUIRE(v2.at(0)==1);
    REQUIRE(v2.at(1)==1);
    REQUIRE(v2.at(2)==1);
    REQUIRE(v2.Size()==v.Size());
    v2.clear();
    REQUIRE(v2.Size()==0);
    REQUIRE(v2.Capacity()==0);
    REQUIRE(v2.Data()==nullptr);
}

TEST_CASE("erase", "[erase]"){
    Vector<int> v{1,1,1,2,3,4,5,9};
    v.erase(v.begin()+7); 
    REQUIRE(v == Vector<int>{1,1,1,2,3,4,5});
    v.erase(v.begin() + 3, v.end()); 
    REQUIRE(v == Vector<int>{1, 1, 1});
}

TEST_CASE("empty", "[empty]"){
    Vector<int> v{1,1};
    v.pop_back();
    v.pop_back();
    REQUIRE(v.empty());
}

TEST_CASE("shrink to fit","[shrink][fit]"){
    Vector<int> v{1, 2, 3};
    v.reserve(10);  
    REQUIRE(v.Capacity() == 10);
    v.shrink_to_fit(); 
    REQUIRE(v.Capacity() == v.Size());
    REQUIRE(v == Vector<int>{1, 2, 3});
}

TEST_CASE("assign","[assign]"){
    Vector<int> v{1,2,3};
    int value=9;
    v.assign(5,value);
    REQUIRE(v==Vector<int>{9,9,9,9,9});
    REQUIRE(v.Size()==5);
}

TEST_CASE("assign range","[assign][range]") {
    Vector<int> v;
    int ar[] = {1,1,1,1};
    v.assign(ar, ar+4);
    REQUIRE(v==Vector<int>{1,1,1,1});
    REQUIRE(v.Size()==4);
}

TEST_CASE("assign from list", "[assign][list]") {
    Vector<int> v{1,2,3};
    v.assign({8,8,8});
    REQUIRE(v==Vector<int>{8,8,8});
    REQUIRE(v.Size()==3);
}

TEST_CASE("insert element", "[insert][element]") {
    Vector<int> v{1,2,4};
    int value=3;
    v.insert(v.begin()+2, value);  
    REQUIRE(v==Vector<int>{1,2,3,4});
    REQUIRE(v.Size()==4);
}

TEST_CASE("operators", "[operators]"){
    Vector<int> v1{1,2,3};
    Vector<int> v2{1,2,4};
    Vector<int> v3{1,2,3,0};
    Vector<int> v4{1,2,3};

    REQUIRE(v1<v2);       
    REQUIRE(v1<v3);       
    REQUIRE_FALSE(v2<v1);
    
    REQUIRE(v1<=v2);
    REQUIRE(v1<=v3);
    REQUIRE_FALSE(v2<=v1);

    REQUIRE(v2>v1);
    REQUIRE(v3>v1);
    REQUIRE_FALSE(v1>v2);

    REQUIRE(v2>=v1);
    REQUIRE(v3>=v1);
    REQUIRE_FALSE(v1 >= v2);
}

TEST_CASE("rbegin rend", "[rbegin][rend]") {
    Vector<int> v{10,20,30};
    REQUIRE(*v.rbegin()==30);
    REQUIRE(v.rend()==v.begin()-1);
    int ar[]={30,20,10};
    int index=0;
    for (auto it=v.rbegin(); it!=v.rend(); --it) {
        REQUIRE(*it==ar[index++]);}
    Vector<int> empty{};
    REQUIRE(empty.rbegin() == nullptr);
    REQUIRE(empty.rend() == nullptr);
}


TEST_CASE("resize", "[resize]") {
    Vector<int> v{1,2,3};
    size_t old = v.Capacity();
    v.reserve(10);
    REQUIRE_FALSE(v.Capacity() == old); 
    v.resize(2); 
    REQUIRE(v.Size()==2);

    v.resize(5);
    REQUIRE(v.Capacity()>=5);

    v.resize(7, 7);
    REQUIRE(v.Size()==7);
    REQUIRE(v.Capacity()>=7);
    REQUIRE(v[6]==7);
}
