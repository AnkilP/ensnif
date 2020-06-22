#include "IRuleEngine.hpp"
#include "BaseRuleEngine.hpp"
#include "aho_corasick.hpp"
#include "data_ingestion.hpp"

int main(){
    Data_Ingestor<int> xy;
    AhoCorasick<int, char> ye(xy);
    return 0;    
}