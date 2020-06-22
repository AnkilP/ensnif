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

        ~AhoCorasick();
};