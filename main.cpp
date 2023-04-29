#include "huffman.h"

using namespace std;
using namespace Huffman;


int main() {

    string input_file = "";
    string output_file = "";

    compress(input_file, output_file);

    string output_text_file = output_file.substr(0, output_file.find_last_of(".")) + ".txt";

    decompress(output_file, output_text_file);

    cout << "Compression and decompression completed successfully!\n";
    return 0;
}
