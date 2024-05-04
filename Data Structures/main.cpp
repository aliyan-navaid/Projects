#include "vector.h"

int main()
{
    Vector<int> first;
    first.add(10);

    Vector<int> second;
    second = first;
    second.add(11);
    second[1]=21;
    second.print();
}