#include <iostream> //preprocessor directive
#include <fstream> //file streams

using namespace std;  //namespace=collection of classes

int main(int argc, char** argv){

  string fileName;        //gets filename from user
  cout << "enter file name: " << endl;
  cin >> fileName;

  ifstream fin; //creation of ifstream class object
  string line = "";

  fin.open(fileName);

  while (fin) {     //reads in input from text file given from user
    getline(fin, line);
    cout << line << endl;
  }
  fin.close();





  string test = "abc";

  ofstream fout;  //creates ofstream object

  fout.open("connordetlefsen.out");   //automatically deletes content of file
  fout << test << endl;
  fout.close();


  return 0;
}
