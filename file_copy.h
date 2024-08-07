#ifndef FILE_COPY_H
#define FILE_COPY_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void copy_word(const string& source_file, const string& target_file, const string& word) {
    ifstream source(source_file);
    ofstream target(target_file);
    string buffer="";
    while (source >> buffer) {
        if (buffer == word) {
            target << buffer << " ";
        }
    }
    source.close();
    target.close();
}


void copy_line(const string& source_file, const string& target_file, int line_number) {
    ifstream source(source_file);
    ofstream target(target_file);
    string buffer;
    int current_line = 1;
    while (getline(source, buffer)) {
        if (current_line == line_number) {
            target << buffer;
            break;
        }
       current_line++;
    }
    source.close();
    target.close();
}


void copy_file(const string& source_file, const string& target_file) {
    ifstream source(source_file);
    ofstream target(target_file);
    string buffer;
    while (getline(source, buffer)) {
        target << buffer << endl;
    }
    source.close();
    target.close();
}
void copy_pointer(const char* source_filename, const char* dest_filename, int start_pos, int end_pos) {
    std::ifstream source_file(source_filename);
    std::ofstream dest_file(dest_filename);

    source_file.seekg(start_pos);
    char* buffer = new char[end_pos - start_pos + 1];
    source_file.read(buffer, end_pos - start_pos + 1);
    buffer[end_pos - start_pos] = '\0';
    dest_file << buffer;

    delete[] buffer;
    source_file.close();
    dest_file.close();
}


#endif