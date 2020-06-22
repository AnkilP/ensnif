#include "BaseIngestor.hpp"
#include <string>

template <typename T>
class Data_Ingestor final : public BaseIngestor<T> {

    private:
        std::string x;

    public:
        Data_Ingestor(): BaseIngestor<T>("Data") {
            x = "hello";
        }

        ~Data_Ingestor() {};
};