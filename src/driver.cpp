// Driver file
#include <iostream>
#include <sstream>
#include <fstream>
#include "FrameSequence.h"
//#include "extractor.h"/Users/duge/Desktop/4th year/EEE4120/EEE4120F/Prac2
using namespace std;
int main(int argc, char *argv[]){
	
	if (argc==1){
		std::cout << "Please specify the parameters ie....." << std::endl;
	}
	else{
		string fileName = argv[1];
		//if (argv[2] == "-t"){
		int x1 = atoi(argv[3]);
		int y1 = atoi(argv[4]);
		int x2 = atoi(argv[5]);
        int y2 = atoi(argv[6]);
        cout << fileName << endl;
		//}
		//if(argv[7] =="-s"){
		int width = atoi(argv[8]);
		int height = atoi(argv[9]);

		//}
		//if(argv[10] =="-w"{
		//	std::string operation = *argv[11];
		//	std::string name = *argv[12];
		//	}

		//extractor(fileName, x1, y1, x2, y2, width, height);//, operation, name);
	}	
	return 0;
}

void MBRSHI002::extractor(string filename, int x1, int y1, int x2, int y2, int width, int height){//,std::string operation,std::string name){
    ifstream imageFile(filename, ios::binary);
    if(!imageFile){
        cerr << "Could not open file" ;
    }
    else{
        string format;
        string comment;
        getline(imageFile , format);

        getline(imageFile,  comment);
        
        int cols, rows, intensity;
        imageFile >> cols >> std::ws;
        imageFile >> rows >> std::ws;
        imageFile >> intensity>> std::ws;
        const int ARRAY_SZ = rows*cols;
        char *array = new char [ARRAY_SZ];
        char arrayPGM[cols][rows];

        /*while(!imageFile.eof()){
            imageFile.read(array, ARRAY_SZ);
            for(int i=0; i<ARRAY_SZ; ++i){
                std::cout <<array[i];
            }
            cout << endl;
        }*/
        
    }
    //outfile.write(array, ARRAY_SZ);
}
