#include<huffman.h>
#include <Lempel.h>
#include<file_copy.h>

using namespace std;
using namespace Huffman;


int main() {

    string input_file = "test.txt";
    string output_file = "test12.dat";

    compress( input_file,output_file );

    string output_text_file = output_file.substr(0, output_file.find_last_of(".")) + ".txt";

    // decompress("test.txt", "test12.");

    cout << "Compression and decompression completed successfully!\n";
    return 0;
}
