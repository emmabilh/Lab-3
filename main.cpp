// Emma Bilhimer
// Lab 3 User and File I/O
// FA2023
/* Description: Write an interactive C++ program that computes and outputs the mean and
population standard deviation of a set of four integers that are inputted by a file called
“inMeanStd.dat” and the user (should handle both). Although the individual values are
integers, the results are floating-point values. Be sure to use proper formatting and
appropriate comments in your code. Provide appropriate prompts to the user. The
output should be to the screen for the user inputted values and to a file called
“outMeanStd.dat”. The programs output should be labeled clearly and formatted
neatly. You must calculate the mean and standard deviation in separate methods within
a class.
*/

#include <iostream>
#include <fstream>

using namespace std;

class StdCalculator {
public:
    // Method to compute the mean
    float calculateMean(int a, int b, int c, int d) {
        return (a + b + c + d) / 4.0;
    }

    // Method to compute the population standard deviation
    float calculateStdDev(int a, int b, int c, int d, float mean) {
        float variance = ((a - mean) * (a - mean) + (b - mean) * (b - mean) +
                         (c - mean) * (c - mean) + (d - mean) * (d - mean)) / 4.0;
        return sqrt(variance);
    }
};

int main() {
    int x, y, z, w;
    
    // read input from a file "inMeanStd.dat"
    ifstream inFile("inMeanStd.dat");
    if (inFile.is_open()) {
        inFile >> x >> y >> z >> w;
        
        // create an instance of MeanStdCalculator
        StdCalculator calculator;
        
        // calculate the mean
        float mean = calculator.calculateMean(x, y, z, w);
        
        // output the mean
        cout << "Mean of data from file: " << mean << endl;
        
        // open the output file
        ofstream outFile("outMeanStd.dat");
        if (outFile.is_open()) {
            // Output the mean to the file
            outFile << "Mean of data from file: " << mean << endl;
            
            
            //  user for input
            cout << "Input four integers: ";
            cin >> x >> y >> z >> w;
            
            // calculate the mean for user input
            mean = calculator.calculateMean(x, y, z, w);

                
                // calculate the population standard deviation
                float stdDev = calculator.calculateStdDev(x, y, z, w, mean);
                
                // output the standard deviation to the console and file
                cout << "Population Standard Deviation: " << stdDev << endl;
                
                // Close the output file
                outFile.close();
                
                
                // Close the input file
                inFile.close();
                
                
                return 0;
            }
        }}
