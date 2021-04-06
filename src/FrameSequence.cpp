#include <iostream>
#include "FrameSequence.h"

//Frame Seq constructor
FrameSequence::FrameSequence(void){
    f_height = 0;
    f_width = 0;
    f_x1 = 0;
    f_y1 = 0;
    f_x2 = 0;
    f_y2 = 0;
    f_bufferedImage = nullptr;
    std::vector<unsigned char **> imageSequence;
    //TODO:Set up class variables and states here
}

//Frame Seq Destructor
FrameSequence::~FrameSequence();
 
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
    f_bufferedImage = bufferedImage;
    int max = x2-x1;
    if ((x2-x1)<(y2-y1)){
        max = y2-y1;
    }
    for (int k = 0; k <= max ; k++ ){
        for (int i = 0; i <= height; i++  ){
            for(int j = 0; j <= width; j++){
                //add pixel to 2D array
            }
        }
        //push back 2D array to vector
    }
}


//	public:
//		//std::vector<unsigned char **> imageSequence;
//		FrameSequence(void){
//		    	//constructor
//        }
//};
