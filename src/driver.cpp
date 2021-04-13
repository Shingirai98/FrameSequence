#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include "FrameSequence.h"
//#include <bits/stdc++.h>

// extractor declaration
void extractor(std::string filename, int x1, int y1, int x2, int y2, int width, int height, std::vector<std::string> operation, std::vector<std::string> name);



int main(int argc, char* argv[]) {

    int operations = 0;
    
    //if user doesnt put the other parameters
    if (argc==1){
        std::cerr << "Please specify the parameters ie....." << std::endl;
    }
    //else assign the values to variables
    else{
       //fileName variable
        std::string fileName = argv[1];
        //values for start and end points
        int x1 = atoi(argv[3]);
        int y1 = atoi(argv[4]);
        int x2 = atoi(argv[5]);
        int y2 = atoi(argv[6]);
        
        //width and height of frames
        int width = atoi(argv[8]);
        int height = atoi(argv[9]);
        
        //vectors storing operations and names
        std::vector<std::string> op;
        std::vector<std::string> na;
        
        //number storing the number of operations and names
        int cont=0;
        while(cont < argc-11){

            op.push_back(argv[11+cont]);
            na.push_back(argv[12+cont]);
            cont = cont+3;
        }
        std::cout<<op[0]<<std::endl;
        //call the extractor function
        extractor(fileName, x1, y1, x2, y2, width, height, op, na);
       
        
    }

    return 0;
}

void extractor(std::string filename, int x1, int y1, int x2, int y2, int width, int height, std::vector<std::string> operation, std::vector<std::string> name){
    // read in the image file
    std::ifstream imageFile(filename, std::ios::binary);
    
    // condition if file is not read
    if(!imageFile){
        std::cerr << "Could not open file" << std::endl;
    }
    
    
    else{
        std::string format;// first line in PGM file
        std::string comment;// comment in file
        std::string c; // the dimensions
        std::string bins;
        int rows; // y dim
        int cols; // x dim
        std::getline(imageFile , format); //ignore format
        std::getline(imageFile , comment); // ignore comment TODO: loop through if there are multiple comments
        std::getline(imageFile,c); // store dimensions in c
        std::getline(imageFile, bins); // store range of BnW value
        std::istringstream ss(c);
        std::string X;
        std::string Y;
         // assign x dimension
        ss >> X; // assign x dimension
        ss >> Y;
        // convert to integers
        cols = stoi(X);
        rows = stoi(Y);
        
        // read the file and point to it using the buffer pointer
        char * buffer = new char [rows*cols];
    
        imageFile.read(buffer, (rows*cols));
        FrameSequence frame;
        imageFile.close();
        frame.setFrameSize(width, height);
        frame.setStartnEnd(x1, y1, x2, y2);

        frame.setFrames(buffer, operation[0], name[0]);
       
        
        //outputFile.write(bo, (width*height));
        //std::cout<<(int)(*buffer)<<std::endl;
        
        //delete[] buffer;
    
    }
}
