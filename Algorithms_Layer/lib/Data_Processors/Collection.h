#include<iostream>
#include<map>
#include<iterator>
using namespace std;
//Collection class
//update: update data of the key name
//push: insert a new container
//pop: delete a container
//privide an iterator to visit all containers in a Collection object
template<class container>
class Collection{
    typedef map<string,container> collection;
    typedef typename collection::iterator iterator;
    
public:
    collection sets;
    Collection();
    ~Collection();
    void update(string name,container Input);
    void push(string name,container Input);
    void pop(string name);
    container operator[](string name){
        return sets.at(name);
    }
    iterator begin(){
        return sets.begin();
    }
    iterator end(){
        return sets.end();
    }
};
