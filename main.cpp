#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>

using namespace std;

//argc - number of arguments in command
//argv - each argument word, stored in an array
int main(int argc, char* argv[])
{
  if(argc == 2 )
  {
    string filename = argv[1];
    vector<vector<Pixel> >imagePixels; 

    Bitmap image;
    image.open(filename);
    if(image.isImage())
    {
      imagePixels = image.toPixelMatrix();
      cout<<filename<<" is "<<imagePixels.size()<<" high and "
        <<imagePixels[0].size()<<" pixels wide"<<endl;
    
      
      for(int row = 0; row < imagePixels.size(); row++)
      {
        for(int col= 0; col < imagePixels[row].size(); col++)
        {
          Pixel color;
          color = imagePixels[row][col];
          color.green = 0;
          color.blue = 0;
          imagePixels[row][col] = color;
        }
      }
      image.fromPixelMatrix( imagePixels );
      image.save("redness.bmp");
    }
    else
    {
      cout<<"Image file must be a bitmap with 24-bit color depth.\n";
    }
  }
  else
  {
    cout<<"Please specify one image file!\n";
  }
  return 0;
}
