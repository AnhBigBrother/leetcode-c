#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

namespace solution14 {
class Trie {
public:
  char val;
  unordered_map<char, Trie *> next;

  Trie() {}
  Trie(char c) { this->val = c; }
  void Insert(string str) {
    Trie *t = this;
    for (auto c : str) {
      if (t->next[c] == NULL) {
        t->next[c] = new Trie(c);
      }
      t = t->next[c];
    }
  }
};

string longestCommonPrefix(vector<string> &strs) {
  Trie root = Trie();
  int len = strs[0].length();
  for (auto str : strs) {
    if (str.length() < len) {
      len = str.length();
    }
    root.Insert(str);
  }
  Trie *t = &root;
  string ans = "";
  while (t != NULL) {
    if (t->next.size() != 1 || ans.length() == len) {
      break;
    }
    for (auto pair : t->next) {
      ans += pair.first;
      t = pair.second;
    }
  }
  return ans;
}
} // namespace prob14
