#include "proc.h"

class InputParser {
    vector <string> m_tokens;
public:
    InputParser(int& argc, char** argv) {
        for (int i = 1; i < argc; ++i) {
            m_tokens.push_back(string(argv[i]));
        }
    }
    const string& getCmdOption(const string& option) const {
        vector<string>::const_iterator itr;
        itr = find(m_tokens.begin(), m_tokens.end(), option);
        if (itr != m_tokens.end() && ++itr != m_tokens.end()) {
            return *itr;
        }
        static const string empty_string("");
        return empty_string;
    }
    bool cmdOptionExists(const string& option) const {
        return find(m_tokens.begin(), m_tokens.end(), option)
            != m_tokens.end();
    }
};


int main(int argc, char** argv) {
    InputParser input(argc, argv);
    const string& filename = input.getCmdOption("-f");
    if (filename.empty()) {
        cout << "スクリプトファイルが指定されていません。" << endl;
        return 1;
    }
    errno_t err;
    FILE* fp;
    if ((err = fopen_s(&fp, filename.c_str(), "r")) != 0) {
        cout << "スクリプトファイルの読み込みに失敗しました。" << endl;
        return 1;
    }
    auto tntp = clg::StackMachine::get();
    if (tntp->compile(fp)) {
        return 1;
    }
    tntp->execute();
    tntp->destroy();
    return 0;
}