// Modified https://cp-algorithms.com/string/aho_corasick.html

#include <folly/small_vector.h>

namespace utils{
    
    class TrieVertex final {
        public: 
            folly::small_vector<int, 10> next;
            bool leaf = false;
            int p = -1;
            char pch;
            int link = -1;
            folly::small_vector<int, 10> go;

            TrieVertex(int K, int p=-1, char ch='$') : p(p), pch(ch) {
                next.resize(K);
                std::fill(next.begin(), next.end(), -1);

                go.resize(K);
                std::fill(go.begin(), go.end(), -1);
            }
    };

    
    class Trie final{
        private:
            folly::small_vector<TrieVertex, 10> trie; // TODO: convert TrieVector to ptr instead
            int go(int v, char ch);

        public:
            void add_string(const std::string &);
            int get_link(int v);
    };

    
    void Trie::add_string(std::string const& s) {
        int v = 0;
        for (const char & ch : s) {
            int c = ch - 'a';
            if (trie[v].next[c] == -1) {
                trie[v].next[c] = trie.size();
                trie.emplace_back(v, ch);
            }
            v = trie[v].next[c];
        }
        trie[v].leaf = true;
    }

    
    int Trie::get_link(int v) {
        if (trie[v].link == -1) {
            if (v == 0 || trie[v].p == 0)
                trie[v].link = 0;
            else
                trie[v].link = go(get_link(trie[v].p), trie[v].pch);
        }
        return trie[v].link;
    }

    
    int Trie::go(int v, char ch) {
        int c = ch - 'a';
        if (trie[v].go[c] == -1) {
            if (trie[v].next[c] != -1)
                trie[v].go[c] = trie[v].next[c];
            else
                trie[v].go[c] = v == 0 ? 0 : go(get_link(v), ch); // stack overflow problems?
        }
        return trie[v].go[c];
    } 

}

