/****************************************** 
 * imagePuzzles_A04034044.cpp
 *
 * Sarah Gibbons
 * 09/02/2015
 * CS2308-00X - Project #1.0
 *
 * This code takes three ppm images that 
 * have been distorted and makes them visable.
 * puzzle1: eifle tower 
 * puzzle2: statue of liberty
 * puzzle3: golden gate bridge 
 * ****************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

/* User-defined Structure to hold the RGB values of an individual pixel */
struct Pixel {
  int red;
  int green;
  int blue;
};

/* User-defined Constants */
/* This is the only allowed use of global variables */
const int NROWS = 300;  // Image # of rows
const int NCOLS = 400;  // Image # of columns
const int MAXVAL = 255; // Maximum pixel RGB value

/* Function Prototypes */
void recoverImage1(Pixel [][NCOLS]);
void recoverImage2(Pixel [][NCOLS]);
void recoverImage3(Pixel [][NCOLS]);
void readPPM(ifstream &, Pixel [][NCOLS]);
void writePPM(ofstream &, Pixel [][NCOLS]);

// ============================================================================
// main: Creates a 2-d array of pixels to hold each image, then iteratively
//       reads in each image, calls the image's recoverImage() function, and
//       writes the solution image to disk.
// returns 0 for success
// ============================================================================
int main() {
  Pixel image[NROWS][NCOLS];
  ifstream fIn;
  ofstream fOut;

  cout << "Processing puzzle1...";

  // Open puzze1.ppm and read pixel data into 2D array 'image'
  // Call recoverImage1() function to un-distort pixels
  // Write solution image to file as solution1.ppm
  fIn.open("puzzle1.ppm");
  if(!fIn) {
    cout << "Error opening puzzle1.ppm\n" << endl;
    exit(-1);
  }
  readPPM(fIn, image);
  fIn.close();
  fIn.clear();
  recoverImage1(image);
  fOut.open("solution1.ppm");
  writePPM(fOut, image);
  fOut.close();
  fOut.clear();

  cout << "done" << endl;
  cout << "Processing puzzle2...";

  // Open puzze2.ppm and read pixel data into 2D array 'image'
  // Call recoverImage2() function to un-distort pixels
  // Write solution image to file as solution2.ppm
  fIn.open("puzzle2.ppm");
  if(!fIn) {
    cout << "Error opening puzzle2.ppm\n" << endl;
    exit(-1);
  }
  readPPM(fIn, image);
  fIn.close();
  fIn.clear();
  recoverImage2(image);
  fOut.open("solution2.ppm");
  writePPM(fOut, image);
  fOut.close();
  fOut.clear();

  cout << "done" << endl;
  cout << "Processing puzzle3...";

  // Open puzze3.ppm and read pixel data into 2D array 'image'
  // Call recoverImage3() function to un-distort pixels
  // Write solution image to file as solution3.ppm
  fIn.open("puzzle3.ppm");
  if(!fIn) {
    cout << "Error opening puzzle3.ppm\n" << endl;
    exit(-1);
  }
  readPPM(fIn, image);
  fIn.close();
  fIn.clear();
  recoverImage3(image);
  fOut.open("solution3.ppm");
  writePPM(fOut, image);
  fOut.close();
  fOut.clear();

  cout << "done" << endl;
  return 0;
}
// ============================================================================
// recoverImage1: remove blue and green garbage values by setting to 0; bring 
// red back up to scale by factor of 10; 
// ============================================================================
void recoverImage1(Pixel image[][NCOLS]) {
   for(int r = 0; r< NROWS; r++)  { 
    for (int c = 0; c < NCOLS; c++) {
        image[r][c].red*=10; //factor back up by 10
        image[r][c].blue*=0; //remove garbage values
        image[r][c].green*=0; //removes garbage values
    }
  }
}
// ============================================================================
// recoverImage2: factor up blue and green pizels by 20 and set red pixels to 
// 0 to remove garbage values  
// ============================================================================
void recoverImage2(Pixel image[][NCOLS]) {
  for(int r = 0; r< NROWS; r++)  { 
    for (int c = 0; c < NCOLS; c++) {
       image[r][c].blue*=20; //scale back up to 20
       image[r][c].green*=20; //scale back up to 20
       image[r][c].red = 0;     
    }
  }
}
// ============================================================================
// recoverImage3: recovers hidden image by multiplying values less than 16 by
// 16 to scale it back up to proper value and removes random red and green
// garbage values by setting equal to 0. 
// ============================================================================
void recoverImage3(Pixel image[][NCOLS]) {
  for(int r = 0; r< NROWS; r++)  { 
    for (int c = 0; c < NCOLS; c++) {
       image[r][c].red = 0; //removes random garbage values
       image[r][c].green = 0; 
       if (image[r][c].blue < 16) //finds values less than 16 and scales back up
         image[r][c].blue *=16;
        else if (image[r][c].blue >= 16) //fins values greater than 16 and removes
          image[r][c].blue=0;        
     }
  }
}
// ============================================================================
// readPPM: from a file input stream, reads the header info and pixel table
//          of a PPM image and stores it in the 2-d Pixel array given as an
//          argument.
// fIn: a reference to a file input stream of the input image, which must be
//      a 300x400 PPM format image with a max pixel value of 255
// image: a 2-d array of Pixels with width NCOLS, to populate with the image
//        data
// ============================================================================
void readPPM(ifstream &fIn, Pixel image[][NCOLS]) {
  string temp;
  int cols, rows, max;
  // Make sure this is actually a PPM file
  fIn >> temp;
  if(temp != "P3") {
    cout << "Invalid PPM file format specifier: must be P3\n";
    exit(-1);
  }
  // Read in row and column count
  // This code is only intended to support 300x400 images
  fIn >> cols;
  fIn >> rows;
  if(cols != NCOLS) {
    cout << "Invalid image width: must be " << NCOLS << " columns\n";
    exit(-1);
  }
  if(rows != NROWS) {
    cout << "Invalid image height: must be " << NROWS << " rows\n";
    exit(-1);
  }
  // Read in maximum pixel value
  // This code is only intended to support images that use 0-255 for
  // pixel values
  fIn >> max;
  if(max != MAXVAL) {
    cout << "Invalid image pixel max value: must be " << MAXVAL << endl;
    exit(-1);
  }
  // Read pixel table into argument array
  for(int r = 0; r < NROWS; r++) {
    for(int c = 0; c < NCOLS; c++) {
      fIn >> image[r][c].red;
      fIn >> image[r][c].green;
      fIn >> image[r][c].blue;
    }
  }
}
// ============================================================================
// writePPM: writes a PPM image to the file output stream given as an argument,
//           using NROWS and NCOLS as the height and width, MAXVAL as the max
//           pixel value, and the 2-d Pixel array passed as an argument as the
//           pixel values.
// fOut: a reference to the file output stream where the output image is to be
//       written
// image: a 2-d array of Pixels with width NCOLS, holding the pixel values to
//        be written as a PPM image
// ============================================================================
void writePPM(ofstream &fOut, Pixel image[][NCOLS]) {
  // Output header information
  fOut << "P3" << endl;
  fOut << NCOLS << " " << NROWS << endl;
  fOut << MAXVAL << endl;
  // Output pixel table
  for(int r = 0; r < NROWS; r++) {
    for(int c = 0; c < NCOLS; c++) {
      fOut << image[r][c].red << endl;
      fOut << image[r][c].green << endl;
      fOut << image[r][c].blue << endl;
    }
  }
}
