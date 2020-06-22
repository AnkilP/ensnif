#ifndef IRULEENGINE_H
#define IRULEENGINE_H

#include "Ingestion/IIngestor.hpp"

template <typename ruleList, typename packet>
class IRuleEngine{
    public:
        virtual void setRules(IIngestor<ruleList> & ) = 0;

        virtual void runRules(IIngestor<packet> &) = 0;

        virtual ~IRuleEngine() {};
};

#endif