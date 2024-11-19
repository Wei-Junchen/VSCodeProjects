#include <iostream>
#include <vector>
#include <string>

template<typename T1,typename T2>
class Map
{
public:
    Map();
    ~Map();
    Map(const Map<T1,T2>&);
    void insert(T1 key,T2 value);
    T2 at(T1 key);
private:
    std::vector<T1> key;
    std::vector<T2> value;
};

template<typename T1,typename T2>
Map<T1,T2>::Map()
{
    this->key.clear();
    this->value.clear();
}

template<typename T1,typename T2>
Map<T1,T2>::~Map()
{
    this->key.clear();
    this->value.clear();
}

template<typename T1,typename T2>
Map<T1,T2>::Map(const Map<T1,T2>& origin)
{
    for(int i=0;i<origin.key.size();++i)
    {
        this->key.push_back(origin.key[i]);
        this->value.push_back(origin.value[i]);
    }
}

template<typename T1,typename T2>
void Map<T1,T2>::insert(T1 key,T2 value)
{
    this->key.push_back(key);
    this->value.push_back(value);
}

template<typename T1,typename T2>
T2 Map<T1,T2>::at(T1 key)
{
    for(int i=0;i<this->key.size();++i)
    {
        if(this->key[i]==key)
            return this->value[i];
    }
    return this->value[0];
}

int main()
{
    Map<std::string,int> map;
    map.insert("apple",160);
    map.insert("banana",1990);
    map.insert("pink",100);
    std::cout<<map.at("pink");
    return 0;
}