// Modified https://cp-algorithms.com/string/aho_corasick.html

#include <folly/small_vector.h>

namespace utils{
    template <int K>
    class TrieVertex final {
        public: 
            folly::small_vector<int, 10> next(K, -1);
            bool leaf = false;
            int p = -1;
            char pch;
            int link = -1;
            folly::small_vector<int, 10> go(K, -1);

            TrieVertex(int p=-1, char ch='$') : p(p), pch(ch) {}
    };

    template <int K>
    class Trie final{
        private:
            folly::small_vector<TrieVertex<K>, 10> trie; // TODO: convert TrieVector to ptr instead
            int go(int v, char ch);

        public:
            void add_string(const std::string &);
            int get_link(int v);
    };

    template <int K>
    void Trie<K>::add_string(std::string const& s) {
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

    template <int K>
    int Trie<K>::get_link(int v) {
        if (t[v].link == -1) {
            if (v == 0 || t[v].p == 0)
                t[v].link = 0;
            else
                t[v].link = go(get_link(t[v].p), t[v].pch);
        }
        return t[v].link;
    }

    template <int K>
    int Trie<K>::go(int v, char ch) {
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

