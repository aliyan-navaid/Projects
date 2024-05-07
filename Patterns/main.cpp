#include "DP.h"

int main() {
    DP::Singleton::Container& instance {DP::Singleton::Container::getInstance()};
    instance.useInstance();

    return EXIT_SUCCESS;
}