#include <iostream>

namespace DP
{
    template <typename T>
    class Singleton {
    public:
        /* Static method to allow call without object */
        static T& getInstance() {
            /* Static Object to prevent re-initialization */
            static T instance;
            return instance;
        }

    protected:
        /* 
            Not allow user to create object
            No Object i.e, no need to disable CConstructor
            and / or Operator=() 
        */
        Singleton() {}
    };
}