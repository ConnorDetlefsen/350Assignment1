#include <iostream> //preprocessor directive
#include <fstream> //file streams
#include <cctype> //used for to lower

using namespace std;  //namespace=collection of classes

int main(int argc, char** argv){

  string fileName;        //this bit gets filename from user that reads in info
  cout << "enter file name: " << endl;
  cin >> fileName;

  ifstream fin; //creation of ifstream class object
  ofstream fout;  //creates ofstream object
  
  string line = "";
  int A = 0, G = 0, T = 0, C = 0;
  int AA = 0, AG = 0, AC = 0, AT = 0, GG = 0, GA = 0, GT = 0, GC = 0, TT = 0, TA = 0, TG = 0, TC = 0, CC = 0, CA = 0, CG = 0, CT = 0;
  int LineCount = -1; //figure this out
  fin.open(fileName);
    while (fin) {     //reads in input from text file given from user
      getline(fin, line);
      ++LineCount;
      //cout << line << endl;
      for(int i = 0; i < line.length(); ++i){   //finds count of each letter
        char c = line[i];
        //putchar(toupper(c));
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
      for(int i = 0; i < line.length(); i = i + 2){ //finds the pairs of DNA nucleotides
        char c = line[i];
        char d = line[i+1];
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
  //fin.close();

  int sum = A+G+T+C;

  string info = "Connor Detlefsen \n2312185 \nCPSC 350-02 \nAssignment 1";      //this bit adds my info to the top of the file
//  ofstream fout;  //creates ofstream object
  fout.open("connordetlefsen.out");   //automatically deletes content of file
  fout << info << endl;
  fout.close();

  fout.open("connordetlefsen.out", ios::app); // allows us to append to contents of file instead of erasing it
  fout << "A count: " << A << endl;  // write the count to the "connordetlefsen.out" file
  fout << "G count: " << G << endl;
  fout << "T count: " << T << endl;
  fout << "C count: " << C << endl;
  fout << "Sum: " << sum << endl;
  fout << "Number of Lines: " << LineCount << endl;
  fout << "AA: " << AA << "\nAG: " << AG << "\nAC: " << AC << "\nAT: " << AT << endl;
  fout << "GG: " << GG << "\nGA: " << GA << "\nGC: " << GC << "\nGT: " << GT << endl;
  fout << "CC: " << CC << "\nCG: " << CG << "\nCA: " << CA << "\nCT: " << CT << endl;
  fout << "TT: " << TT << "\nTG: " << TG << "\nTC: " << TC << "\nTA: " << TA << endl;

  fin.close();
  fout.close();

  return 0;
}
