#include "DP.h"

class Foo : public DP::Singleton<Foo> {
    public:
        void doSomething() {
            std::cout << "Did Something...\n";
        }
    private:
        Foo() {};
        Foo(const Foo&) = delete;
        Foo operator=(const Foo&) = delete;

        friend class DP::Singleton<Foo>;
};

int main() {
    Foo& ref {Foo::getInstance()};
    ref.doSomething();
    
    return EXIT_SUCCESS;
}