#include <iostream>

namespace DP
{
    namespace Singleton
    {
        class Container {
        public:
            /* Static method to allow call without object */
            static Container& getInstance() {
                /* Static Object to prevent re-initialization */
                static Container instance;
                return instance;
            }

            void useInstance() {
                std::cout << "Method Called\n";
            }

        private:
            /* Not allow user to create object */
            Container() {
                std::cout << "Object Created\n";
            }

            /* Disable Copy Constructor, Assignment */
            Container(const Container&) = delete;
            Container operator=(const Container&) = delete;
        };

    }
}