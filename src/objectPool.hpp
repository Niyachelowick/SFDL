#include<vector>
#include<iostream>

class poolableObject
{
private:
    int value =0;
public:
    virtual void init()=0;
    virtual void reset()=0;
    virtual void update()=0;
    virtual ~poolableObject()= default;
};

template<typename T>
class objectPool
{
private:
    std::vector<T*> availableObj;
public:
    objectPool(size_t initialSize) {
        for (size_t i = 0; i < initialSize; ++i) {
            T* obj = new T();
            obj->initialize();
            availableObjects.push_back(obj);
        }
    }
    T* getObject() {
        if (!availableObjects.empty()) {
            T* obj = availableObj.front();
            availableObj.pop_front();
            return obj;
        }
        T* obj = new T();
        obj->initialize();
        return obj;
    }
    void returnObject(T* object) {
        object->reset();
        availableObj.push_back(object);
    }
    ~objectPool();
};


