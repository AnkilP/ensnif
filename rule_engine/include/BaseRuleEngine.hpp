#ifndef BASERULEENGINE_H
#define BASERULEENGINE_H

#include "IRuleEngine.hpp"
#include <folly/small_vector.h>
#include <string>

template <typename ruleList, typename packet>
class BaseRuleEngine : public IRuleEngine<ruleList, packet> {

    protected:
        folly::small_vector<ruleList, 10> ruleContainer;
        std::string label;
        bool cancellation_token; // TODO: converted to sync 

        BaseRuleEngine(const std::string & name);

    public:

        void setRules(IIngestor<ruleList> & ruleIngestor) override;

        void runRules(IIngestor<packet> & packetIngestor) override;

        virtual ~BaseRuleEngine();

};

template <typename ruleList, typename packet>
BaseRuleEngine<ruleList, packet>::BaseRuleEngine(const std::string & name){
    label = name;
    ruleContainer.reserve(2048);
}

template <typename ruleList, typename packet>
void BaseRuleEngine<ruleList, packet>::setRules(IIngestor<ruleList> & ruleIngestor) {
    while(!ruleIngestor.isEmpty()){
        // we expect this to terminate as rule assignment should normally be done 
        ruleContainer.emplace_back(ruleIngestor.getElement());
    }
}

template <typename ruleList, typename packet>
void BaseRuleEngine<ruleList, packet>::runRules(IIngestor<packet> & packetIngestor) { // TODO: 
    while(!packetIngestor.isEmpty() && cancellation_token == false){
        // auto p = packetIngestor.getElement();
        cancellation_token = true;
    }
}

#endif