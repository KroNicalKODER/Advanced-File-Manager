#ifndef LEMPEL_H
#define LEMPEL_H

#include <bits/stdc++.h>

using namespace std;

class Lempel {
    private:
        unordered_map<string, int> dictionary;
        int next_code;
        int max_code_length;
        vector<int> compressed_data;

    public:
        Lempel(int max_code_length);

        void compressRecycle(const string& input_file, const string& output_file);
        void decompressRecycle(const string& input_file, const string& output_file);

    private:
        void initializeDictionary();
        void resetDictionary();
        void addCodeToDictionary(const string& code);
};

#endif
