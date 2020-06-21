#include "IIngestor.hpp"
#include "folly/ProducerConsumerQueue.h"

template <typename T>
class BaseIngestor : public IIngestor<T> {

    protected:
        folly::ProducerConsumerQueue<T> IngestionQueue;
        T temp_variable;

    public:
        void setElement(const T & elem) override {};

        T getElement() override {};

};

template <typename T>
void BaseIngestor<T>::setElement(const T & elem) {
    if(!IngestionQueue.write(elem)){
        std::cout << "not able to write" << std::endl;
        //TODO: log not able to write
        //fatal
    }
}

template <typename T>
T BaseIngestor<T>::getElement() {
    if(!IngestionQueue.read(temp_variable)){
        //TODO: log not able to read
        // fatal
    }
    else{
        return temp_variable;
    }
}