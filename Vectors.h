/*@Author
 * Student Name: Esin Ece Aydın
 * Student ID: 150160151
 * Date: 23.03.2019
*/

//Decleration of Vectors
#ifndef _vectors_
#define _vectors_
#include<iostream>

class Vectors{

    int numberV;
    int *value;
    int sizeV;

public:

    Vectors(int = 0); // constructor with default parameters
    Vectors(int, int *); //constructor with parameters
    ~Vectors(); //destructor
    int getsize() const { // getter method to get sizeV
        return sizeV;
    }
    void operator+(const Vectors&) const;
    void operator*(const Vectors&) const;
    void operator*(const int) const;
    friend std::ostream & operator << (std::ostream &out, const Vectors &v);//friend function for Vectors class
                                                                             //it can access all members of this class.

};

#endif
