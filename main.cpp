#include "IRuleEngine.hpp"
#include "BaseRuleEngine.hpp"
#include "aho_corasick.hpp"
#include "data_ingestion.hpp"

int main(){
    Data_Ingestor<int> xy;
    xy.setElement(22);
    xy.setElement(23);
    xy.setElement(24);
    AhoCorasick<int, char> ye(xy);
    return 0;    
}