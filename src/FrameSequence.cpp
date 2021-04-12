#include <iostream>
#include "FrameSequence.h"
#include <fstream>
//Frame Seq constructor
FrameSequence::FrameSequence(void){
    f_height = 0;
    f_width = 0;
    f_x1 = 0;
    f_y1 = 0;
    f_x2 = 0;
    f_y2 = 0;
    //f_bufferedImage = nullptr;
    //std::vector<unsigned char **> imageSequence;
    
    //TODO:Set up class variables and states here
}

//Frame Seq Destructor
FrameSequence::~FrameSequence(){
   
};
 
void FrameSequence::setFrameSize(int width,int height){
    f_height = height;
    f_width = width;
}

void FrameSequence::setStartnEnd(int x1, int y1, int x2,int y2){
    f_x1 = x1;
    f_x2 = x2;
    f_y1 = y1;
    f_y2 = y2;
}

void FrameSequence::setFrames(char * bufferedImage){
    
    unsigned char** imSeq = new unsigned char*[f_height];
    for(int i=0; i < f_height; i++){
        imSeq[i] = new unsigned char[f_width];
    }
    int max = f_x2-f_x1;
    if ((f_x2-f_x1)<(f_y2-f_y1)){
        max = f_y2-f_y1;
    }
    for (int k = 0; k < max ; k++ ){
        for (int i = 0; i < f_height; i++  ){
            for(int j = 0; j < f_width; j++){
                //add pixel to 2D array
                
                imSeq[i][j] =(unsigned char) bufferedImage[f_y1+i+f_x1+j];
               
            }
        }
        
        //push back 2D array to vector
        imageSequence.push_back(imSeq);
        
    }
    //for (int k= 0; k<imageSequence.size(), k++);
    
    //std:: string fN = k;
    std::ofstream outputFile("0000.pgm", std::ios::binary);
    outputFile << "P5\n" << f_width << " " << f_height <<  "\n"<< 255 << std::endl;
    //outputFile << (frame.imageSequence[1]);
    //char * bo = new char [f_width*f_height];
    
    for (int d=0; d<f_height; d++){
        for (int e=0; e<f_width; e++){
            //bo[d+e] = frame.imageSequence[0][d][e];
            outputFile << (unsigned char)imageSequence[0][d][e] ;
            //std::cout <<(unsigned char)imageSequence[0][d][e];
        }
    }
//    for (int h=0; h< f_width ; h++){
//        delete[]imSeq[h];
//    }
   delete[]imSeq;
  
}



