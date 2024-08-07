#include<bits/stdc++.h>
#include"huffman.h"
#include<conio.h>
#include<filesystem>
#include"file_copy.h"

using namespace std;
namespace fs = std::filesystem;

void showMenuLandingPage(int dec){
    switch(dec){
        case 1 :    cout<<"\t\t>  Show your Files"<<endl;
                    cout<<"\t\t   Open Recycle Bin"<<endl;
                    cout<<"\t\t   Global search a string"<<endl;
                    cout<<"\t\t   Delete a file"<<endl;
                    cout<<"\t\t   Compress A file"<<endl;
                    cout<<"\t\t   Search By prefix"<<endl; 
                    cout<<"\t\t   Copy from File"<<endl;
                    break;
        case 2 :    cout<<"\t\t   Show your Files"<<endl;
                    cout<<"\t\t>  Open Recycle Bin"<<endl;
                    cout<<"\t\t   Global search a string"<<endl;
                    cout<<"\t\t   Delete a file"<<endl;
                    cout<<"\t\t   Compress A file"<<endl;
                    cout<<"\t\t   Search By prefix"<<endl;
                    cout<<"\t\t   Copy from File"<<endl;
                    break;
        case 3 :    cout<<"\t\t   Show your Files"<<endl;
                    cout<<"\t\t   Open Recycle Bin"<<endl;
                    cout<<"\t\t>  Global search a string"<<endl;
                    cout<<"\t\t   Delete a file"<<endl;
                    cout<<"\t\t   Compress A file"<<endl;
                    cout<<"\t\t   Search By prefix"<<endl;
                    cout<<"\t\t   Copy from File"<<endl;
                    break;
        case 4 :    cout<<"\t\t   Show your Files"<<endl;
                    cout<<"\t\t   Open Recycle Bin"<<endl;
                    cout<<"\t\t   Global search a string"<<endl;
                    cout<<"\t\t>  Delete a file"<<endl;
                    cout<<"\t\t   Compress A file"<<endl;
                    cout<<"\t\t   Search By prefix"<<endl;
                    cout<<"\t\t   Copy from File"<<endl;
                    break;
        case 5 :    cout<<"\t\t   Show your Files"<<endl;
                    cout<<"\t\t   Open Recycle Bin"<<endl;
                    cout<<"\t\t   Global search a string"<<endl;
                    cout<<"\t\t   Delete a file"<<endl;
                    cout<<"\t\t>  Compress A file"<<endl;
                    cout<<"\t\t   Search By prefix"<<endl;
                    cout<<"\t\t   Copy from File"<<endl;
                    break;
        case 6 :    cout<<"\t\t   Show your Files"<<endl;
                    cout<<"\t\t   Open Recycle Bin"<<endl;
                    cout<<"\t\t   Global search a string"<<endl;
                    cout<<"\t\t   Delete a file"<<endl;
                    cout<<"\t\t   Compress A file"<<endl;
                    cout<<"\t\t>  Search By prefix"<<endl;
                    cout<<"\t\t   Copy from File"<<endl;
                    break;
        case 7 :    cout<<"\t\t   Show your Files"<<endl;
                    cout<<"\t\t   Open Recycle Bin"<<endl;
                    cout<<"\t\t   Global search a string"<<endl;
                    cout<<"\t\t   Delete a file"<<endl;
                    cout<<"\t\t   Compress A file"<<endl;
                    cout<<"\t\t   Search By prefix"<<endl;
                    cout<<"\t\t>  Copy from File"<<endl;
                    break;
    }
}

void landingPage();

void showFiles(){
    system("cls");
    cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t  BACK [B]                                 FILES                                   EXIT [E]"<<endl;
    cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl;

    vector<string> filenames;
    //CHECKING IN THE CURRENT DIRECTORY
    for(const auto& itr : fs::directory_iterator(".")){
        // Check if the entry is a file and not a directory
        if (fs::is_regular_file(itr)) filenames.push_back(itr.path().string());
    }

    int len = filenames.size();
    int ind = 1; 
    for(auto str : filenames){
        if(str.find(".txt") != string::npos || str.find(".dat") != string::npos ){
            cout<<"\t\t  "<<ind++<<". "<<str.substr(2)<<endl;
            cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl;
        }
    }

    char keyPress = getch();
    if(keyPress == 'B' || keyPress=='b') landingPage();
    if(keyPress == 'E' || keyPress=='e') exit(0);
}

void showRecycleBin(){
    vector<string> filenames;
    for (const auto& entry : fs::directory_iterator("recycle")) {
        // Check if the entry is a file and not a directory
        if (fs::is_regular_file(entry)) {
            // Add the filename to the vector
            filenames.push_back(entry.path().string());
        }
    }
    int s = 0;

    system("cls");
    cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t  BACK [B]                                 FILES                                   EXIT [E]"<<endl;
    cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl<<endl;
    int ind = 1;

    for(auto str : filenames){
        cout<<"\t\t  "<<ind++<<". "<<str.substr(8)<<endl;
        cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl;
    }

    cout<<"\n\t\tRESTORE[NUM]";

    char keyPress = getch();
    if(keyPress == 'B' || keyPress=='b') landingPage();
    if(keyPress == 'E' || keyPress=='e') exit(0);    
    
    if(keyPress <= '9' && keyPress >= '0') {
        string fileToDecompress = filenames[keyPress-'0'-1];
        string afterFile = fileToDecompress.substr(8);
        afterFile.replace(afterFile.end()-4,afterFile.end(),".txt");
        Huffman::decompress(fileToDecompress,afterFile);
        auto dnn = remove(fileToDecompress.c_str());
        if(dnn == 0){
            cout<<"\nFile Restored Successfully"<<endl;
        }
        else cout<<"Error Occured"<<endl;
        cout<<"Press any key to continue"<<endl;
    }
    getch();
    landingPage();
}

void showCompressFile(){
    system("cls");
    cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t  BACK [B]                                 FILES                                   EXIT [E]"<<endl;
    cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl;

    vector<string> filenames;
    //CHECKING IN THE CURRENT DIRECTORY
    for(const auto& itr : fs::directory_iterator(".")){
        // Check if the entry is a file and not a directory
        if (fs::is_regular_file(itr)) filenames.push_back(itr.path().string());
    }

    int len = filenames.size();
    int ind = 1;
    vector<string> canCompress; 
    for(auto str : filenames){
        if(str.find(".txt") != string::npos){
            canCompress.push_back(str);
            cout<<"\t\t  "<<ind++<<". "<<str.substr(2)<<endl;
            cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl;
        }
    }
    cout<<endl<<"\t\tCOMPRESS[NUM]"<<endl;
    char keyPress = getch();
    if(keyPress == 'B' || keyPress=='b') landingPage();
    if(keyPress == 'E' || keyPress=='e') exit(0);
    if(keyPress <= '9' && keyPress >= '0') {
        string fileToCompress = canCompress[keyPress-'0'-1];
        string datFileCompress = fileToCompress;
        datFileCompress.replace(datFileCompress.end()-4,datFileCompress.end(),".dat");
        Huffman::compress(fileToCompress,datFileCompress);
        cout<<"\n\t\tFile Compressed Successfully"<<endl;

    }
    cout<<"Press any key to continue"<<endl;
    getch();
    landingPage();
}

void sendRecycleBin(){
    system("cls");
    cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t  BACK [B]                                 FILES                                   EXIT [E]"<<endl;
    cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl;

    vector<string> filenames;
    //CHECKING IN THE CURRENT DIRECTORY
    for(const auto& itr : fs::directory_iterator(".")){
        // Check if the entry is a file and not a directory
        if (fs::is_regular_file(itr)) filenames.push_back(itr.path().string());
    }

    int len = filenames.size();
    vector<string> canDelete;
    int ind = 1; 
    for(auto str : filenames){
        if(str.find(".txt") != string::npos || str.find(".dat") != string::npos ){
            canDelete.push_back(str.substr(2));
            cout<<"\t\t  "<<ind++<<". "<<str.substr(2)<<endl;
            cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl;
        }
    }

    char keyPress = getch();
    if(keyPress == 'B' || keyPress=='b') landingPage();
    if(keyPress == 'E' || keyPress=='e') exit(0);
    if(keyPress <= '9' && keyPress >= '0') {
        string fileToDelete = canDelete[keyPress-'0'-1];
        string datFileCompress = "recycle\\"+fileToDelete;
        datFileCompress.replace(datFileCompress.end()-4,datFileCompress.end(),".dat");
        Huffman::compress(fileToDelete,datFileCompress);
        int n = remove(fileToDelete.c_str());
        if(n==0) cout<<"File Deleted Successfully"<<endl;
        else cout<<"Error Occured"<<endl;
    }
    cout<<"Press any key to continue"<<endl;
    getch();
    landingPage();

}

int copyFiles(){
    system("cls");
    string source_Files,Destination_files;
    
     cout<<"Enter the Source file Name";
    cin>>source_Files;

     cout<<"Enter the Destination file Name";
    cin>>Destination_files;
    cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl;
    cout<<"\t\t  BACK [B]                                 FILES                                   EXIT [E]"<<endl;
    cout<<"\t\t---------------------------------------------------------------------------------------------"<<endl;
 cout << "Enter the option to copy:\n";
    cout << "1. A specific word\n";
    cout << "2. A specific line\n";
    cout << "3. The complete file\n";
    cout << "4. From one to another pointer\n";
    int option;
    cin >> option;
 switch (option) {
        case 1: 
         {cout<<"Enter the Source file Name";
         cin>>source_Files;
         cout<<"Enter the Destination file Name";
         cin>>Destination_files;
         cout << "Enter the word to copy: ";
         string word;
         cin >> word;
         copy_word(source_Files,Destination_files,word);
         }break;
        case 2:
        {cout << "Enter the line number to copy: ";
         cout<<"Enter the Source file Name";
         cin>>source_Files;
         cout<<"Enter the Destination file Name";
         cin>>Destination_files;
        int line_number;
        cin >> line_number;
        copy_line(source_Files,Destination_files,line_number);
        }
        break;

 case 3:
        {cout << "Enter the line number to copy: ";
         cout<<"Enter the Source file Name";
         cin>>source_Files;
         cout<<"Enter the Destination file Name";
         cin>>Destination_files;
        copy_file(source_Files,Destination_files);
        }
        break;

 case 4:
        {cout << "Enter the line number to copy: ";
         cout<<"Enter the Source file Name";
         cin>>source_Files;
         cout<<"Enter the Destination file Name";
         cin>>Destination_files;
         cout<<"Enter the starting Pointer";
         int frmPtr;
         cin>>frmPtr;
          cout<<"Enter the ending Pointer";
         int toPtr;
         cin>>toPtr;
         copy_pointer(source_Files.c_str(),Destination_files.c_str(),frmPtr,toPtr);
        }
        break;
          default: 
            cout << "Invalid option.\n";          
}
 cout<<"Press any key to continue"<<endl;
    getch();
    landingPage();
}

void landingPage(){
    int dec = 1;
    char keyPress='.';
    while(keyPress!='c'){
        system("cls");
        cout<<"\n\n\n\t\tWELCOME TO ADVANCED FILE MANAGER\n";
        cout<<"\n\t\tUse 'w' and 's' to navigate and 'c' to select a file"<<endl;
        cout<<"\t\tSelect from the following options\n\n\n";
        if(keyPress=='w'||keyPress=='W') dec--;
        else if(keyPress=='s'||keyPress=='S') dec++;
        if(dec==0) dec=6;
        else if(dec==7) dec=1;
        showMenuLandingPage(dec);
        keyPress = getch();
    }
    switch(dec){
        case 1 : showFiles();break;
        case 2 : showRecycleBin();break;
        case 4 : sendRecycleBin();break;
        case 5 : showCompressFile();break;
    }
    
}

int main(){
    landingPage();
    return 0;
}