#ifndef IINGESTOR_H
#define IINGESTOR_H

template <typename T>
class IIngestor {
    public:
        virtual void setElement(const T & elem) = 0;
        virtual T getElement() = 0;
        virtual bool isEmpty() = 0;
};

#endif