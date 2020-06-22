#ifndef BASEINGESTOR_H
#define BASEINGESTOR_H

#include "IIngestor.hpp"
#include "folly/ProducerConsumerQueue.h"
#include <iostream>

template <typename T>
class BaseIngestor : public IIngestor<T> {

    protected:
        folly::ProducerConsumerQueue<T> IngestionQueue;
        T temp_variable;
        std::string _label;

        BaseIngestor(const std::string & label): IngestionQueue(2048), _label(label) {}

    public:
        void setElement(const T & elem) override;
        bool isEmpty() const override;
        T getElement() override;

        virtual ~BaseIngestor();

};

template <typename T>
bool BaseIngestor<T>::isEmpty() const {
    return IngestionQueue.isEmpty();
}

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
        std::cout << "not able to read" << std::endl;
        //TODO: log not able to read
    }
    else{
        return temp_variable;
    }
    return temp_variable;
}

#endif