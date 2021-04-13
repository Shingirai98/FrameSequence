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
void Gradient(int x_start, int x_end, int y_start, int y_end){
    // loop over x and find corresponding y on line

    float y = y_start;
    float frame_coord=(x_start + y_start); // starting frame coord
    //for (int x=x_start+1; x <= x_end; ++x)
    // { y += g;  =(x, std::round(y)); }

    //  OR loop over y and find corresponding x on line
    // NOTE: g here should be computed as (x2-x1)/(y2-y1) (because of variable swap) or you can use 1/g (using g computed above)

    int x = x_start;
    frame_coord=(x_start+y_start); // starting frame coord
    //for (int y = ystart+1; y <= yend; ++y)
    //{ x += g; frame_coord=(std::round(x), y) ;}
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
        int start = f_x1+f_y1;
        for (int i = 0; i < f_height; i++  ){
            for(int j = 0; j < f_width; j++){
                //add pixel to 2D array
                
                imSeq[i][j] =*(bufferedImage+(start));
                start++;
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
        //std::cout << imageSequence.size() << std::endl;
        if (operation == "invert" ){
            for (int d=0; d<f_height; d++){
                for (int e=0; e<f_width; e++){
                        //bo[d+e] = frame.imageSequence[0][d][e];
                        //outputFile.write((const char*)imageSequence[c], (f_height*f_width);
                        outputFile << (const char) (255-((float)imageSequence[k][d][e]) );
                        //std::cout <<(unsigned char)imageSequence[0][d][e];
                }
            }
        }
        else if(operation == "revinvert"){
            for (int d=0; d<f_height; d++){
                for (int e=0; e<f_width; e++){
                        //bo[d+e] = frame.imageSequence[0][d][e];
                        //outputFile.write((const char*)imageSequence[c], (f_height*f_width);
                        outputFile << (const char) (255-((float)imageSequence[imageSequence.size()-k][d][e]) );
                }
            }
        }
        else if(operation == "reverse"){
            for (int d=0; d<f_height; d++){
                for (int e=0; e<f_width; e++){
                                
                        outputFile << (const char) (((float)imageSequence[imageSequence.size()-k][d][e]) );
                }
            }
        }
        else{
            for (int d=0; d<f_height; d++){
                for (int e=0; e<f_width; e++){
                        //bo[d+e] = frame.imageSequence[0][d][e];
                        //outputFile.write((const char*)imageSequence[c], (f_height*f_width);
                    //std::cout << operation << std::endl;
                    outputFile << (const char)(float)imageSequence[k][d][e] ;
                        //std::cout <<(unsigned char)imageSequence[0][d][e];
                }
            }
        }
        
    }
    
   delete[]imSeq;
  
}



