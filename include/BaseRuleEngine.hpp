#include "IRuleEngine.hpp"
#include <folly/small_vector.h>
#include <string>

template <typename ruleList, typename packet>
class BaseRuleEngine : public IRuleEngine<ruleList, packet> {

    protected:
        folly::small_vector<ruleList, 10> ruleContainer;
        std::string label;

    public:

        BaseRuleEngine(const std::string & name);

        void setRules(const IIngestor<ruleList> &) override {};

        virtual void runRules(const IIngestor<packet> &) = 0;

};

template <typename ruleList, typename packet>
BaseRuleEngine<ruleList, packet>::BaseRuleEngine(const std::string & name){
    label = name;
}

template <typename ruleList, typename packet>
void BaseRuleEngine<ruleList, packet>::setRules(const IIngestor<ruleList> & ruleIngestor) {
    while(!ruleIngestor.isEmpty()){
        // we expect this to terminate as rule assignment should normally be done 
        ruleContainer<ruleList, 10>.emplace_back(ruleIngestor.getElement());
    }
}