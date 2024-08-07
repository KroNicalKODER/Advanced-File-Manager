#include"history.h"
#include<sstream>
#include<bits/stdc++.h>



using namespace std;

void History :: addRecord(string filename,int frmPointer, int toPointer, string action){
   
   ifstream file1(filename, ios::binary);
    stringstream buffer;
    buffer << file1.rdbuf();
    string originalContents = buffer.str();
    file1.close();
    
    HistoryStruct record = {action, filename,frmPointer, toPointer};
    fstream file;
    file.open("record.dat",ios::binary|ios::in|ios::out|ios::app);
      file.seekp(0, ios::beg);
    file.seekg(0, ios::beg);
    file.write((char*)&record, sizeof(record));
    file.seekp(0, ios::end);
    file.seekg(0, ios::end);
   file.close();

}

void History::undo() {
{
    // Open the file in read/write mode
    std::fstream file("record.dat", std::ios::in | std::ios::out | std::ios::binary);

    // Calculate the position of the last record
    file.seekg(0, std::ios::end);
    int endPosition = file.tellg();
    int recordPosition = endPosition - sizeof(HistoryStruct);

    // Move the file pointer to the last record
    file.seekg(recordPosition, std::ios::beg);

    // Read the last record from the file
    HistoryStruct record;
    file.read((char*)&record, sizeof(record));

    // Move the file pointer back to the beginning of the last record
    file.seekp(recordPosition, std::ios::beg);

    // Overwrite the last record with zeros
    char zeroBuffer[sizeof(HistoryStruct)] = {0};
    file.write(zeroBuffer, sizeof(zeroBuffer));

    // Close the file
    file.close();

    // If the last record was a paste operation, remove the pasted content
    if (record.operation == "paste"||record.operation == "copy") {
        std::fstream inFile(record.file.c_str(), std::ios::in | std::ios::out | std::ios::binary);
        inFile.seekg(record.toPtr, std::ios::beg);
        int length = record.toPtr - record.fromPtr;
        std::vector<char> buffer(length, ' ');
        inFile.write(buffer.data(), length);
        inFile.close();
    }
}

}


void copy_word(string filename, int line){
    ofstream output("copy.txt",ios::binary);
}


void copy_pointer(string filename, void* frmPointer, void* toPointer){
    ofstream output("copy.txt",ios::binary);
    //READ FILE FROMPOINTER TO TOPOINTER AND COPY IT TO A FILE NAMED COPY.TXT
}

void paste(string filename, void* frmPointer){
    //WRITE THE FILE FROM COPY.TXT to filename.TXT
}

vector<HistoryStruct> History :: getRecords() const {
    vector<HistoryStruct> records = {};
    ifstream input("history.dat",ios::binary);
    if(!input){
        cout << "Error opening the file" << endl;
        return {};
    }
    HistoryStruct readRecord;

    while(!input.eof()) {
        input.read(reinterpret_cast<char *>(&readRecord), sizeof(readRecord));
        records.push_back(readRecord);
    }
    return records;
}


