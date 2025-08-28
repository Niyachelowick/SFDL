#include<vector>
#include<iostream>
#include<memory>

class poolableObject
{
private:

public:
    virtual void init()=0;
    virtual void reset()=0;
    virtual void update()=0;
    virtual ~poolableObject()= default;
};


// class objectPool
// {
// private:
//     std::vector<poolableObject*> availableObj;
// public:
//     objectPool(size_t initialSize) {
//         for (size_t i = 0; i < initialSize; ++i) {
//             poolableObject obj = new ;
//             obj->initialize();
//             availableObjects.push_back(obj);
//         }
//     }
//     T* getObject() {
//         if (!availableObjects.empty()) {
//             T* obj = availableObj.front();
//             availableObj.pop_front();
//             return obj;
//         }
//         T* obj = new T();
//         obj->initialize();
//         return obj;
//     }
//     void returnObject(T* object) {
//         object->reset();
//         availableObj.push_back(object);
//     }
//     ~objectPool();
// };


