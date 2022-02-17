#pragma once

template <class T> 
class Singleton
{
   public:
     static T* get_instance()
     {
       if(p == nullptr)
         p = new T;
       return p;
     }
     
     void delete_instance()
     {
        if (p)
        {
            delete p;
            p = nullptr;
        }
     }
   protected:
     static T* p;
};

template <class T>
T* Singleton<T>::p = nullptr;
