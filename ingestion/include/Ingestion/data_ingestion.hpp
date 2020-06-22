#include "BaseIngestor.hpp"
#include <string>
#include <iostream>

template <typename T>
class Data_Ingestor final : public BaseIngestor<T> {

    private:
        std::string x;

    public:
        Data_Ingestor(): BaseIngestor<T>("Data") {
            x = "hello";
        }

        ~Data_Ingestor() {};

        void getLabel();
};

template <typename T>
void Data_Ingestor<T>::getLabel(){
    std::cout << this->_label << std::endl;
}