#include <iostream>
#include <vector>

class Trie {
public:
    static const int TABLE_SIZE = 26;

    Trie() : isEndOfWord(false), children({TABLE_SIZE, NULL}) {
    }

    ~Trie() {
        for (auto i : children) {
            delete i;
        }
    }

    void insert(std::string word) {
        Trie *node = this;

        for (auto c : word) {
            if (node) {
                if (!node->children[c - 'a']) {
                    node->children[c - 'a'] = new Trie();
                }
                node = node->children[c - 'a'];
            }
        }

        node->isEndOfWord = true;
    }

    bool search(std::string word) {
        Trie *node = this;

        for (auto c : word) {
            if (node) {
                node = node->children[c - 'a'];
                if (!node) {
                    return false;
                }
            }
        }

        return node->isEndOfWord;
    }

    bool startsWith(std::string prefix) {
        Trie *node = this;

        for (auto c : prefix) {
            if (node) {
                node = node->children[c - 'a'];
                if (!node) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool isEndOfWord;
    std::vector<Trie*> children;
};

int main(int argc, char const *argv[])
{
    Trie trie;

    trie.insert("apple");

    std::cout << "search: " << trie.search("apple") << std::endl;
    std::cout << "startsWith " << trie.startsWith("app") << std::endl;
    std::cout << "search " << trie.search("app") << std::endl;

    trie.insert("app");

    std::cout << "search: " << trie.search("apple") << std::endl;
    std::cout << "startsWith " << trie.startsWith("apple") << std::endl;
    std::cout << "search " << trie.search("app") << std::endl;

    return 0;
}
