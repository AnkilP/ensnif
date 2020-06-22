#include "Rule_Engine/aho_corasick.hpp"

template <typename ruleList, typename packet>
AhoCorasick<ruleList, packet>::AhoCorasick(IIngestor<ruleList> & ruleIngestor) : BaseRuleEngine<ruleList, packet>("Aho-Corasick") {
    rule_trie = utils::Trie(26);
    this->setRules(ruleIngestor); // TODO: plan is to make this a service in the grpc sense
    // construct_automaton();
    this->cancellation_token = false;
}

template <typename ruleList, typename packet>
bool AhoCorasick<ruleList, packet>::construct_automaton(){
    for(const auto &rule_list: this->ruleContainer){
        for(const auto & rule: rule_list.rules){
            rule_trie.add_string(rule);
        }
    }
    return false;
}

template <typename ruleList, typename packet>
void AhoCorasick<ruleList, packet>::runRules(IIngestor<packet> & packetIngestor){
    while(!packetIngestor.isEmpty() && this->cancellation_token == false){
        p = packetIngestor.getElement();

    }
}