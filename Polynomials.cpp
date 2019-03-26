/*@Author
 * Student Name: Esin Ece Aydın
 * Student ID: 150160151
 * Date: 23.03.2019
*/

#include "Polynomials.h"
#include<iostream>
#include<fstream>

using namespace std;
//function definitions here

//constructor to create an object corresponding line in the .txt
Polynomials::Polynomials(int linenumber){
    ifstream file;
    file.open("Polynomial.txt");
    if(file){
        file >> sizeP; //first element read from .txt is assigned to sizeP
    }
    string line;

    for(int i = 0; i < linenumber; i++){//to skip not used lines
        getline(file, line);
    }
    file >> degree; //first element of line is assigned to degree
    coeff = new int[degree+1];//dynamic memory allocation for coeff[]
    for(int i = 0; i < degree+1; i++){
        file >> coeff[i]; //reading coefficients of polynomials from .txt
    }

    file.close();
}
//constructor with parameters
Polynomials::Polynomials(int d, int arr[]){
    degree = d;
    coeff = new int[d + 1];//dynamic memory allocation for coeff array
    for(int i = 0; i< d+1; i++ ){
        coeff[i] = arr[i];
    }
}

//operator Overloading on + sign
void Polynomials::operator+(const Polynomials& p) const{
    int d_max = p.degree;
    int d_min = degree;
    if(degree > p.degree){
        d_max = degree;
        d_min = p.degree;
    }
    int difference; //it used used for obtaining differences between these two object's degrees.

    int arr[d_max]; //static array Decleration
    for(int i = 0; i< d_max+1; i++){
        arr[i] = 0; // array initiliazed with zeros
    }

    if(degree == p.degree){ //if these two objects' degrees are equal
        for(int i = 0; i < degree + 1; i++){
            arr[i] = coeff[i] + p.coeff[i];
        }
    }
    if(degree > p.degree){ //if these two objects' degrees are not equal
        difference = degree - p.degree;
        for(int j = 0; j < difference; j++){
            arr[j] = coeff[j];
        }
        for(int i = difference; i < degree + 1; i++){
            arr[i] = coeff[i] + p.coeff[i-difference];
        }
    }
    if(degree < p.degree){ //if these two objects' degrees are not equal
        difference = p.degree - degree;
        for(int j = 0; j < difference; j++){
            arr[j] = p.coeff[j];
        }
        for(int i = difference; i < p.degree + 1; i++){
            arr[i] = p.coeff[i] + coeff[i-difference];
        }
    }

    Polynomials temp(d_max, arr); //constructor with parameters is invoked
    cout << temp; //thanks to operator Overloading it prints temp object properly
    cout << endl;

}

//operator Overloading on *
void Polynomials::operator*(const Polynomials& p) const{
    int max_degree; //product of multiplication operation object's degree
    max_degree = degree + p.degree;
    int arr[max_degree]; //static array Decleration

    for(int i = 0; i< max_degree+1; i++){
        arr[i] = 0; // firstly array initiliazed with zeros
    }

    for(int i = 0; i < degree+1; i++){
        for(int j = 0; j < p.degree+1; j++){
            arr[i + j] += coeff[i] * p.coeff[j];
        }
    }
    Polynomials temp(max_degree, arr); //constructor with parameters is invoked
    cout << temp; // temp object is printed.
    cout << endl;
}

//operator Overloading on << sign to print object
std::ostream &operator << (std::ostream &out, const Polynomials &p){
    int d = p.degree;
    int sum = p.degree;

    //firstly it looks at coefficients then check their degree to print properly.
    while(d != -1){
        if(p.coeff[sum-d] == 1){
            if(d == p.degree){
                out << "x^" << d;
                d--;
            }
            else if(d == 0){
                out  <<" + "<< p.coeff[sum-d];
                d--;
            }
            else if(d == 1){
                out<< " + " << "x" ;
                d--;
            }
            else if(d > 1){
                out<< " + " << "x^" << d ;
                d--;
            }
        }//coeff == 1

        else if(p.coeff[sum-d] > 1){
            if(d == p.degree && d != 1){
                out << p.coeff[sum-d] << "x^" << d;
                d--;
            }
            else if(d == p.degree && d == 1){
                out << p.coeff[sum-d] << "x";
                d--;
            }
            else if(d == 0){
                out<<" + " << p.coeff[sum-d];
                d--;
            }
            else if(d == 1){
                out<<" + " << p.coeff[sum-d] << "x" ;
                d--;
            }
            else if(d > 1){
                out <<" + " << p.coeff[sum-d] << "x^" << d ;
                d--;
            }
        }//coeff > 1

        else if(p.coeff[sum-d] == -1){
            p.coeff[sum-d] *= -1;
            if(d == 0){
                out << " - " << "1";
                d--;
            }
            else if(d == 1){
                out << " - " << "x";
                d--;
            }
            else if(d > 1){
                out << " - " << "x^"<< d;            }
        }//coeff == -1

        else if(p.coeff[sum-d] < -1){
            p.coeff[sum-d] *= -1;
            if(d == 0){
                out << " - " << p.coeff[sum-d];
                d--;
            }
            else if(d == 1){
                out << " - " << p.coeff[sum-d] << "x";
                d--;
            }
            else if(d > 1){
                out << " - "<< p.coeff[sum-d] << "x^" << d ;
                d--;
            }
        }//coeff < -1

        else if(p.coeff[sum-d] == 0){
            d--;
            continue;
        }//coeff == 0
    }//while

    return out;
}

//destructor
Polynomials::~Polynomials(){
    delete[] coeff;
}
