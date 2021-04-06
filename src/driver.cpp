#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
//#include "FrameSequence.h"
//#include <bits/stdc++.h>

// extractor declaration
void extractor(std::string filename, int x1, int y1, int x2, int y2, int width, int height, std::string operation, std::string name);



int main(int argc, char* argv[]) {

    int operations = 0;

    if (argc==1){
        std::cout << "Please specify the parameters ie....." << std::endl;
    }
    else{
       
        std::string fileName = argv[1];
        int x1 = atoi(argv[3]);
        int y1 = atoi(argv[4]);
        int x2 = atoi(argv[5]);
        int y2 = atoi(argv[6]);
        
        int width = atoi(argv[8]);
        int height = atoi(argv[9]);
        
        std::string operation = argv[11];
        std::string name = argv[12];
        
//        cout << fileName <<endl;
//        cout << x1 <<endl;
//        cout << y1 <<endl;
//        cout << x2 <<endl;
//        cout << y2 <<endl;
//        cout << width <<endl;
//        cout << height <<endl;
//        cout << operation <<endl;
//        cout << name << endl;
        
        //TODO: add a loop for multiple operations
        
        extractor(fileName, x1, y1, x2, y2, width, height, operation, name);
        //FrameSequence FS;
        
    }

    return 0;
}

void extractor(std::string filename, int x1, int y1, int x2, int y2, int width, int height, std::string operation, std::string name){
    std::ifstream imageFile(filename, std::ios::binary);
    if(!imageFile){
        std::cerr << "Could not open file" << std::endl;
    }
    else{
        std::string format;
        std::string comment;
        std::string c;
        std::string bins;
        int rows;
        int cols;
        //std::vector<int> RnC; //Rows and columns
        std::getline(imageFile , format);
        std::getline(imageFile , comment);
//        std::cout << format <<std::endl;
//        std::cout << comment <<std::endl;
        int i = 0;
        std::getline(imageFile,c);
        std::getline(imageFile, bins);
        std::istringstream ss(c);
        std::string X;
        std::string Y;
        ss >> X;
        ss >> Y;
        
        rows = stoi(X);
        cols = stoi(Y);
        
        //std::cout << rows << " & " << cols << ". The number of characters are: " << rows*cols<<std::endl;
        char * buffer = new char [rows*cols];
        imageFile.read(buffer,( (rows*cols)));
//        FrameSequence frame;
//        frame.setSize(width, height);
//        frame.setStartnEnd(x1, y1, x2, y2);
//
//        frame.setFrames(buffer);
        std::cout<<buffer<<std::endl;
//        while ( std::getline (imageFile,bins) ){
//              //std::cout << bins << std::endl;
//        }
        imageFile.close();
        delete[] buffer;
    
    }
}//,std::string operation,std::string name){
//    ifstream imageFile(filename, ios::binary);
//    if(!imageFile){
//        cerr << "Could not open file" ;
//    }
//    else{
//        string format;
//        string comment;
//        getline(imageFile , format);
//
//        getline(imageFile,  comment);
//
//        int cols, rows, intensity;
//        imageFile >> cols >> std::ws;
//        imageFile >> rows >> std::ws;
//        imageFile >> intensity>> std::ws;
//        const int ARRAY_SZ = rows*cols;
//        char *array = new char [ARRAY_SZ];
//        char arrayPGM[cols][rows];
//
//        /*while(!imageFile.eof()){
//            imageFile.read(array, ARRAY_SZ);
//            for(int i=0; i<ARRAY_SZ; ++i){
//                std::cout <<array[i];
//            }
//            cout << endl;
//        }*/
//
//    }
//    //outfile.write(array, ARRAY_SZ);
//}
//
