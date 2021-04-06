#ifndef _FRAMESEQUENCE
#define _FRAMESEQUENCE
//namespace MBRSHI002{
class FrameSequence{
private:
    int f_height;
    int f_width;
    int f_x1 ;
    int f_y1 ;
    int f_x2 ;
    int f_y2 ;
    char * f_bufferedImage;
    std::vector<unsigned char **> imageSequence;
    
public :
    FrameSequence(void);
    ~FrameSequence();
    setFrameSize(int height, int width);
    setFrames(char * bufferedImage);
    setStartnEnd(int x1, int y1, int x2, int y2);
};

#endif
    
//    //		std::vector<unsigned char **> imageSequence;
//            FrameSequence(void);
//    };
//}
//#endif
