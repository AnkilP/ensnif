#include "IIngestor.hpp"
#include "BaseRuleEngine.hpp"
#include "aho_corasick.hpp"
#include "data_ingestion.hpp"

int main(int argc, char *argv[]){
    Data_Ingestor<int> xy;
    xy.setElement(22);
    xy.setElement(23);
    xy.setElement(24);
    // xy.getLabel();
    AhoCorasick<int, char> ye(xy);
    return 0;    
}