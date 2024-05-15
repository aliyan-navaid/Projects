#include "DP.h"

class Foo : public DP::Singleton<Foo> {
    public:
        void doSomething() {
            std::cout << "Foo Something...\n";
        }
    private:
        Foo() {
            std::cout << "Foo Created...\n";
        };

        Foo(const Foo&) = delete;
        Foo(Foo&&) = delete;    
        void operator=(const Foo&) = delete;
        void operator=(Foo&&) = delete;

        friend class DP::Singleton<Foo>;
};

int main() {
    Foo& ref {Foo::getInstance()};
    ref.doSomething();
    
    return EXIT_SUCCESS;
}