#include <iostream> //preprocessor directive
#include <fstream> //file streams
#include <cctype> //used for to lower


using namespace std;  //namespace=collection of classes

int main(int argc, char** argv){

  string fileName;        //this bit gets filename from user that reads in info
  cout << "enter file name: " << endl;
  cin >> fileName;



  ifstream fin; //creation of ifstream class object
  string line = "";
  int A = 0;
  int G = 0;
  int T = 0;
  int C = 0;
  fin.open(fileName);
    while (fin) {     //reads in input from text file given from user
      getline(fin, line);
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
  }
  fin.close();




  string info = "Connor Detlefsen \n2312185 \nCPSC 350-02 \nAssignment 1";      //this bit adds my info to the top of the file
  ofstream fout;  //creates ofstream object
  fout.open("connordetlefsen.out");   //automatically deletes content of file
  fout << info << endl;
  fout.close();


  fout.open("connordetlefsen.out", ios::app); // allows us to append to contents of file instead of erasing it
  fout << "A count: " << A << endl;  // write the count to the "connordetlefsen.out" file
  fout << "G count: " << G << endl;
  fout << "T count: " << T << endl;
  fout << "C count: " << C << endl;
  fout.close();


  return 0;
}
