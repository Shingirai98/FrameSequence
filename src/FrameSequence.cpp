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

void FrameSequence::setFrames(char * bufferedImage, std::string operation, std::string name){
    
    unsigned char** imSeq = new unsigned char*[f_height];
    for(int i=0; i < f_height; i++){
        imSeq[i] = new unsigned char[f_width];
    }
    
    int max = f_x2-f_x1;
    if ((f_x2-f_x1)<(f_y2-f_y1)){
        max = f_y2-f_y1;
    }
    
    int fy =f_y1;
    int fx =f_x1;
    
    while(fy<f_y2 || fx<f_x2){
        for (int i = 0; i < f_height; i++  ){
            for(int j = 0; j < f_width; j++){
                //add pixel to 2D array
                
                imSeq[i][j] =(unsigned char) bufferedImage[f_y1+i+f_x1+j];
               
            }
        }
        fy= fy + 1;
        fx= fx + 1;
        //push back 2D array to vector
        imageSequence.push_back(imSeq);
        
    }
    for (int k= 0; k<imageSequence.size(); k++){
    
        //std:: string fN = k;
        std::string path = "./img/";
        //if (
        std::string value = std::to_string(k);
        
        if (k <10){
            value = "000" + value;
        }
        else if (k<100){
            value = "00" +value;
        }
        else if (k<1000){
            value = "0" + value;
        }

        std::string extension = ".pgm";
        std::string fileN = path+name+"-"+value+extension;
        std::ofstream outputFile(fileN, std::ios::binary);

        outputFile << "P5\n" << f_width << " " << f_height <<  "\n"<< 255 << std::endl;
        //outputFile << (frame.imageSequence[1]);
        //char * bo = new char [f_width*f_height];
        //for (int c=0; c<imageSequence.size(); c++){
        //outputFile.write((const char*)imageSequence[0], (f_height*f_width));
       // }
        //for (int c=0; c<imageSequence.size(); c++){
        float m =0;
        //std::cout << imageSequence.size() << std::endl;
        if (operation == "invert" || operation == "revinvert"){
            for (int d=0; d<f_height; d++){
                for (int e=0; e<f_width; e++){
                        //bo[d+e] = frame.imageSequence[0][d][e];
                        //outputFile.write((const char*)imageSequence[c], (f_height*f_width);
                   // m = (float)imageSequence[k][d][e] ;
                    //std::cout << "you here" << std::endl;
                    if (operation == "revinvert")
                    outputFile << (unsigned char) (255-((float)imageSequence[k][d][e]) );
                        //std::cout <<(unsigned char)imageSequence[0][d][e];
                }
            }
        }
        else{
            for (int d=0; d<f_height; d++){
                for (int e=0; e<f_width; e++){
                        //bo[d+e] = frame.imageSequence[0][d][e];
                        //outputFile.write((const char*)imageSequence[c], (f_height*f_width);
                    //std::cout << operation << std::endl;
                    outputFile << (float)imageSequence[k][d][e] ;
                        //std::cout <<(unsigned char)imageSequence[0][d][e];
                }
            }
        }
        
    }
//    for (int h=0; h< f_width ; h++){
//        delete[]imSeq[h];
//    }
   delete[]imSeq;
  
}



