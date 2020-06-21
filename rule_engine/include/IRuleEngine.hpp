#ifndef IRULEENGINE_H
#define IRULEENGINE_H

#include "IIngestor.hpp"

template <typename ruleList, typename packet>
class IRuleEngine{
    public:
        virtual void setRules(const IIngestor<ruleList> & ) = 0;

        virtual void runRules(const IIngestor<packet> &) = 0;
};

#endif