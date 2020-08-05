// identification comments code block
// Programmer: Iziren Okhamafe
// Programmer's ID: 0997910

/*Pre-Processors C++*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <iomanip> //can also be used to set-precision
#include "pShapes.h"
using namespace std;

//C Preprocessors
#include <cmath>
#include <cstring>

vector<string> parseString(string str)
{
    stringstream s(str);
    istream_iterator<string> begin(s), end;
    return vector<string>(begin, end);
}

//main function
int main() {
    // identification output code block
    cout << "Programmer: Iziren Okhamafe\n";
    cout << "Programmer's ID: 0997910\n";
    cout << "File: " << __FILE__ << endl;
    cout << endl;
    //Open File and Parse Data to a vector data classure
    vector<string> parseString(string);
    string lineToParse;
    vector<string> parsedData;
    vector<const Shape*> bagOfShapes;
    
    ifstream shapeInputFile;

    //Open File
    shapeInputFile.open("Shapes.input.txt");

    if (!shapeInputFile) {
        cerr << "Unable to open file Shapes.input.txt\n"; //Output error
        exit(1); //Make system call to stop program
    }

    //Parse Data and Store in bag
    while (getline(shapeInputFile, lineToParse) && lineToParse != "EOF") {
        parsedData = parseString(lineToParse); //Grab data from file and store in Vector
        if (parsedData.size() == 0) {
            continue;
        }
        if (strcmp(parsedData[0].c_str(), "SQUARE") == 0) {
                const Square* const aSquare = new Square(parsedData);
                bagOfShapes.push_back(aSquare);
                
        } else if (strcmp(parsedData[0].c_str(), "RECTANGLE") == 0) {
                const Rectangle* const aRectangle = new Rectangle(parsedData);
                bagOfShapes.push_back(aRectangle);          
                       
        } else if (strcmp(parsedData[0].c_str(), "CIRCLE") == 0) {
                const Circle* const aCircle = new Circle(parsedData);
                bagOfShapes.push_back(aCircle);
                
        } else if (strcmp(parsedData[0].c_str(),"TRIANGLE") == 0) {
                const Triangle* const aTriangle = new Triangle(parsedData);
                bagOfShapes.push_back(aTriangle);
                
        } else if (strcmp(parsedData[0].c_str(), "CUBE") == 0) {
                const Cube* const aCube = new Cube(parsedData);
                bagOfShapes.push_back(aCube);
               
        } else if (strcmp(parsedData[0].c_str(),"BOX") == 0) {
                const Box* const aBox = new Box(parsedData);
                bagOfShapes.push_back(aBox);
                
        } else if (strcmp(parsedData[0].c_str(),"CYLINDER") == 0) {
                const Cylinder* const aCylinder = new Cylinder(parsedData);
                bagOfShapes.push_back(aCylinder);
                
        } else if (strcmp(parsedData[0].c_str(),"PRISM") == 0) {
                const Prism* const aPrism = new Prism(parsedData);
                bagOfShapes.push_back(aPrism);
                
        } else {
            cout << parsedData[0] << " invalid object!\n";
        }
        
    } //File Processing Complete
   
       //Output Data from bags (Console Output)
    for (unsigned int i = 0; i < bagOfShapes.size(); i++) { 
        bagOfShapes[i]->output(cout);
    }

    //Output Data from bags To .txt file
    ofstream fout;
    fout.open("Shapes.6.Output.txt", ios::out | ios::app);
        
    //Print
    for (unsigned int i = 0; i < bagOfShapes.size(); i++) { 
        bagOfShapes[i]->output(fout);
    }
    fout.close();

    /*De-Allocation of Objects*/
    for (unsigned int i = 0; i < bagOfShapes.size(); i++) {

        delete bagOfShapes[i];
    }
    return 0;
}