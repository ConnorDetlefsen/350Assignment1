#include <iostream> //preprocessor directive
#include <fstream> //file streams
#include <cctype> //used for to lower
#include <cmath> //used for sqrt
#include <cstdlib> //rand
#include <math.h> //cos sin

using namespace std;  //namespace=collection of classes

int main(int argc, char** argv){
  ifstream fin; //creation of ifstream class object
  ofstream fout;  //creates ofstream object

  string line = "";
  int A = 0, G = 0, T = 0, C = 0;
  float AA = 0, AG = 0, AC = 0, AT = 0, GG = 0, GA = 0, GT = 0, GC = 0, TT = 0, TA = 0, TG = 0, TC = 0, CC = 0, CA = 0, CG = 0, CT = 0;
  float LineCount = -1; //needs to be -1 to take into account blank line
  float bigramCount = 0;
  int sum = 0;

  string info = "Connor Detlefsen \n2312185 \nCPSC 350-02 \nAssignment 1";      //this bit adds my info to the top of the file
  fout.open("connordetlefsen.out");   //automatically deletes content of file
  fout << info << endl;
  fout.close();

  bool running = true;
  while(running){ //loop to check for good input from user

    string fileName;
    string yesNo;

    cout << "do you want to process a file? \nenter YES or NO, in all capitals\n";
    cin >> yesNo;
      if(yesNo == "NO")
        break;
      else if(yesNo == "YES"){
        cout << "enter file name: " << endl;  //this bit gets filename from user that reads in info
        cin >> fileName;
      }
      else{
        cout << "please enter valid input" << endl;
        continue;
      }

        fin.open(fileName);
          while (fin) {     //reads in input from text file given from user
            getline(fin, line);
            ++LineCount;
            for(int i = 0; i < line.length(); ++i){   //finds count of each letter
              char c = toupper(line[i]);
              if(c == 'A'){
                A++;
              }
              else if(c == 'G')
                G++;
              else if(c == 'T')
                T++;
              else if(c == 'C')
                C++;
            }
            sum = A+G+T+C;

            for(int i = 0; i < line.length(); i = i + 2){ //finds the pairs of DNA nucleotides
              bigramCount++;
              char c = toupper(line[i]);
              char d = toupper(line[i+1]);
              string putTogether;
              putTogether += c;
              putTogether += d;
              if (putTogether == "AA"){   //counts pairs of DNA
                  AA++;
              }
              else if (putTogether == "AG")
                AG++;
              else if (putTogether == "AC")
                AC++;
              else if (putTogether == "AT")
                AT++;
              else if (putTogether == "GG")
                GG++;
              else if (putTogether == "GA")
                GA++;
              else if (putTogether == "GC")
                GC++;
              else if (putTogether == "GT")
                GT++;
              else if (putTogether == "CC")
                CC++;
              else if (putTogether == "CG")
                CG++;
              else if (putTogether == "CA")
                CA++;
              else if (putTogether == "CT")
                CT++;
              else if (putTogether == "TT")
                TT++;
              else if (putTogether == "TG")
                TG++;
              else if (putTogether == "TA")
                TA++;
              else if (putTogether == "TC")
                TC++;
            }
        }
        fin.close();

        float mean = float(sum) / float(LineCount); //calculates probability of each DNA nucleotide
        float AProb = float(A) / float(sum);
        float GProb = float(G) / float(sum);
        float CProb = float(C) / float(sum);
        float TProb = float(T) / float(sum);

        //variance
        float variance = 0;
        float stdev = 0;
        fin.open(fileName);
          for(int i = 0; i < LineCount; i++){     //reads in input from text file given from user
            getline(fin, line);
            variance = variance + pow((line.length() - mean),2);
          }
        fin.close(); //close file reader after done
         variance = variance / LineCount;
         stdev = sqrt(variance);

        cout << "Calculations output to connordetlefsen.out" << endl;
        fout.open("connordetlefsen.out", ios::app); // allows us to append to contents of file instead of erasing it
        fout << "Calculations for: " << fileName << endl;
        fout << "A probability: " << AProb << endl;  // write the count to the "connordetlefsen.out" file
        fout << "G probability " << GProb << endl;
        fout << "T probability: " << TProb << endl;
        fout << "C probability: " << CProb  << endl;
        fout << "Sum of the length of the DNA strings: " << sum << endl;
        fout << "Mean of the length of the DNA strings: " << mean << endl;
        fout << "Variance of the length of the DNA strings: " << variance << endl;
        fout << "Standard deviation of the length of the DNA strings: " << stdev << endl;
        fout << "AA: " << AA/bigramCount << "\nAG: " << AG/bigramCount << "\nAC: " << AC/bigramCount << "\nAT: " << AT/bigramCount << endl;
        fout << "GG: " << GG/bigramCount << "\nGA: " << GA/bigramCount << "\nGC: " << GC/bigramCount << "\nGT: " << GT/bigramCount << endl;
        fout << "CC: " << CC/bigramCount << "\nCG: " << CG/bigramCount << "\nCA: " << CA/bigramCount << "\nCT: " << CT/bigramCount << endl;
        fout << "TT: " << TT/bigramCount << "\nTG: " << TG/bigramCount << "\nTC: " << TC/bigramCount << "\nTA: " << TA/bigramCount << endl;

        float pi = atan(1)*4; //pi
        float CnAProb = (float(C) + float(A))/ float(sum);  //used in calculation for gaussian
        float CnAnGProb = (float(C) + float(A) + float(G))/ float(sum);

        string GaussianOutput = "";
        fout << "Gaussian output for: " << fileName << endl;
        for(int i = 0; i < 1000; ++i){

          float a = (float) rand() / (double)RAND_MAX; //generates random decimal 0 - 1
          float b = (float) rand() / (double)RAND_MAX;

          float c = sqrt(-2 * log(a)) * (cos(2* pi * b));
          float d =  (sqrt(variance) * c) + mean;  //how long length of line is

          for(int i = 0; i < d; ++i){
            float random = rand() / (double)RAND_MAX; //makes new random int 0 - .99
            if(random < AProb) {    //these if statements use the random integer to run through and append nucleotides
              GaussianOutput += "A";
            }
            else if(random < CnAProb && random >= AProb) {
              GaussianOutput += "C";
            }
            else if(random < CnAnGProb && random >= CnAProb){
              GaussianOutput += "T";
            }
            else if(random <= 1 && random >= CnAnGProb){
              GaussianOutput += "G";
            }
          }
        GaussianOutput += "\n";
    }
    fout << GaussianOutput << endl;
    fout.close();
  }
  return 0;
}
