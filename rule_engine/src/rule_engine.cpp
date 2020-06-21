/* 
* Encrypted rules prevent the attacker from identifying what 
* packet characteristics are being searched. As a result, we always
* expect encrypted rules. These rules will be sent to the 
* serverless unit to process by the owner of the serverless unit (client)
* The assumption is that the attacker has access to the source code
* and might also have access to the serverless unit itself. 
*  
*/

#include "BaseRuleEngine.hpp"
#include "utils/aho_corasick.hpp"
// #include "include/synchronization.hpp" // when we get to it

template <typename ruleList, typename packet>
class AhoCorasick final : public BaseRuleEngine<ruleList, packet> {

    private:
        packet p;
        utils::Trie rule_trie;

        bool construct_automaton();

    public:
        AhoCorasick(const IIngestor<ruleList> & ruleIngestor);    

        void runRules(const IIngestor<packet> &) override final;
};

template <typename ruleList, typename packet>
AhoCorasick<ruleList, packet>::AhoCorasick(const IIngestor<ruleList> & ruleIngestor) : BaseRuleEngine<ruleList, packet>("Aho-Corasick") {
    rule_trie = utils::Trie(26);
    this->setRules(ruleIngestor); // TODO: plan is to make this a service in the grpc sense
    construct_automaton();
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
void AhoCorasick<ruleList, packet>::runRules(const IIngestor<packet> & packetIngestor){
    while(!packetIngestor.isEmpty() && this->cancellation_token == false){
        p = packetIngestor.getElement();

    }
}
