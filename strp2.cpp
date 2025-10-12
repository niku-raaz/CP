#include <bits/stdc++.h>
using namespace std;

string normalize(string s) {
    // Lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Replace commas and ampersands with space
    for (char &c : s)
        if (c == ',' || c == '&') c = ' ';

    // Trim spaces
    auto trim = [&](string &str) {
        int i = 0, j = (int)str.size() - 1;
        while (i <= j && isspace(str[i])) i++;
        while (j >= i && isspace(str[j])) j--;
        str = str.substr(i, j - i + 1);
    };

    trim(s);

    // Split into words
    stringstream ss(s);
    vector<string> words;
    string word;
    while (ss >> word) words.push_back(word);

    if (words.empty()) return "";

    // Remove leading "the", "an", "a"
    if (words[0] == "the" || words[0] == "an" || words[0] == "a")
        words.erase(words.begin());

    if (words.empty()) return "";

    // Remove suffixes at end
    vector<string> suffixes = {"inc.", "corp.", "llc", "l.l.c.", "l.l.c", "llc."};
    while (!words.empty()) {
        string last = words.back();
        bool isSuffix = false;
        for (auto &suf : suffixes)
            if (last == suf) {
                isSuffix = true;
                break;
            }
        if (isSuffix)
            words.pop_back();
        else
            break;
    }

    if (words.empty()) return "";

    // Remove "and" unless it is the first word
    vector<string> cleaned;
    for (int i = 0; i < (int)words.size(); i++) {
        if (words[i] == "and" && i != 0) continue;
        cleaned.push_back(words[i]);
    }

    // Reconstruct name
    string res;
    for (int i = 0; i < (int)cleaned.size(); i++) {
        if (i) res += " ";
        res += cleaned[i];
    }

    trim(res);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    unordered_set<string> used;

    while (getline(cin, line)) {
        if (line.empty()) continue;

        size_t pos = line.find('|');
        if (pos == string::npos) continue;

        string acct_id = line.substr(0, pos);
        string name = line.substr(pos + 1);

        string norm = normalize(name);

        if (norm.empty()) {
            cout << acct_id << "|Name Not Available\n";
            continue;
        }

        if (used.find(norm) == used.end()) {
            cout << acct_id << "|Name Available\n";
            used.insert(norm);
        } else {
            cout << acct_id << "|Name Not Available\n";
        }
    }
    return 0;
}
