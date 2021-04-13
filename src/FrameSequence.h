#include <vector>
#ifndef _FRAMESEQUENCE
#define _FRAMESEQUENCE
//namespace MBRSHI002{

class FrameSequence{
    //private variables
private:
    int f_height;
    int f_width;
    int f_x1 ;
    int f_y1 ;
    int f_x2 ;
    int f_y2 ;
    //char * f_bufferedImage;
    //std::vector<unsigned char **> imageSequence;
    
public :
    //publci variables and functions
    FrameSequence(void);
    ~FrameSequence();
    void setFrameSize(int height, int width);
    void setFrames(char * bufferedImage, std::string operation, std::string name );
    void setStartnEnd(int x1, int y1, int x2, int y2);
    std::vector<unsigned char **> imageSequence;
};

#endif
    
