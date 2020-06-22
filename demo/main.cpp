#include "Ingestion/IIngestor.hpp"
#include "Rule_Engine/BaseRuleEngine.hpp"
#include "Rule_Engine/aho_corasick.hpp"
#include "Ingestion/data_ingestion.hpp"

int main(int argc, char *argv[]){
    Data_Ingestor<int> xy;
    xy.setElement(22);
    xy.setElement(23);
    xy.setElement(24);
    xy.getLabel();
    AhoCorasick<int, char> ye(xy);
    return 0;    
}