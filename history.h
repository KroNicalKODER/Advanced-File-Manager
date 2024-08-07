#ifndef HISTORY_H
#define HISTORY_H

#include<bits/stdc++.h>
#include<ctime>
#include<chrono>
using namespace std;

class HistoryStruct{
    public:
        string operation;
        string file;
       // chrono::system_clock::time_point timestamp;
       int fromPtr;
       int toPtr;
        string originalContents;
        
};

class History{
    public: 
        void addRecord(string filename,int frmPointer, int toPointer, string action);
        vector<HistoryStruct> getRecords() const;
        void undo();
        void redo();
        void saveToFileHistory(string filename) const;
        void loadFromFileHistory(string filename);
        vector<HistoryStruct> records_;
        int currentRecordIndex_ = -1;
};

#endif