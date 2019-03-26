/*@Author
 * Student Name: Esin Ece Aydın
 * Student ID: 150160151
 * Date: 23.03.2019
*/

#include"Vectors.h"
#include<iostream> //standard input output
#include<fstream> //for file operations

using namespace std;


//function definitions here

//constructor to create an object corresponding line in the .txt
Vectors::Vectors(int linenumber){
    ifstream file;
    file.open("Vector.txt");
    if(file){
        file >> sizeV; //first element read from .txt is assigned to sizeV
    }
    string line;

    for(int i = 0; i < linenumber; i++){//to skip not used lines
        getline(file, line);
    }

    file >> numberV; //first element of line is assigned to numberV
    value = new int[numberV+1];//dynamic memory allocation for value[]
    for(int i = 0; i < numberV+1; i++){
        file >> value[i]; //reading values of vectors from .txt
    }

    file.close();
}
//constructor with parameters
Vectors::Vectors(int n, int val[]){
    numberV = n;
    value = new int[n+1];//dynamic memory allocation for value array
    for(int i = 0; i< n+1; i++){
        value[i] = val[i];
    }
}

//operator Overloading on + sign
void Vectors::operator+(const Vectors& v) const{
    int num = numberV;
    int arr[num]; //static array Decleration

    if(numberV == v.numberV){ //to check size of vectors
        for(int i = 0; i< numberV + 1; i++){
            arr[i] = value[i] + v.value[i]; //corresponding values are added and assigned to another array
        }
        Vectors temp(num, arr); //constructor with parameters is invoked
        cout << temp; //thanks to operator Overloading it prints temp object properly
    }
    else{ //error messages:
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "You selected wrong vectors." << endl;
        cout << "Addition operation cannot do with these vectors" << endl;
    }
    cout << endl;
}

//operator Overloading on * sign for the purpose of doing scalar multiplication operation
void Vectors::operator*(const Vectors& v) const{
    int sum = 0; // sum is initiliazed as 0
    int i = numberV;
    if(numberV == v.numberV){//if sizes are not the same, it gives error messages
        for(int i = 0; i< numberV; i++){
            sum += value[i] * v.value[i]; //added 1.1 + 2.2 + 3.3 ...
        }
        cout << sum;
    }
    else{//error messages
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "You selected wrong vectors." << endl;
        cout << "Multiplication operation cannot do with these vectors" << endl;
    }
    cout << endl;
}
//operator Overloading on * sign for the purpose of doing dot product operation
void Vectors::operator*(const int k) const{
    int num = numberV;
    int arr[num];//static Decleration
    for(int i = 0; i< numberV + 1; i++){
        arr[i] = value[i] * k; //all values of value array multiply with k
    }
    Vectors temp(num, arr); //constructor with parameters is invoked
    cout << temp; // temp object is printed with << operator Overloading
    cout << endl;
}
//operator Overloading on << sign to print object
std::ostream &operator << (std::ostream &out, const Vectors &v){
  int number = v.numberV;

  for(int i = 0; i< number; i++){
    if(i != 0 &&  i!=number-1)
      out << v.value[i] << ", ";

    if(i==0 && i==number-1){ //if value[] has only 1 element
      out << "(" << v.value[i] << ")";
      break;
    }
    if(i == 0){ //first element of value[]
      out << "(" << v.value[i] << ", ";
    }
    if(i==number-1){ //last element of value[]
      out << v.value[i]<< ")";
    }
  }

  return out;
}

//destructor
Vectors::~Vectors(){
    delete[] value;
}
