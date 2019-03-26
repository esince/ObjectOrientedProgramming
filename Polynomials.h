/*@Author
 * Student Name: Esin Ece Aydın
 * Student ID: 150160151
 * Date: 23.03.2019
*/

//Decleration of Polynomials
#ifndef _polynomials_
#define _polynomials_
#include<iostream>


class Polynomials{

    int degree;
    int *coeff;
    int sizeP;

public:

    Polynomials(int=0); // defaul constructor
    Polynomials(int, int *);
    ~Polynomials(); //destructor
    int getsize() const { //getter method to get sizeP
        return sizeP;
    }
    void operator+(const Polynomials&) const;
    void operator*(const Polynomials&) const;
    friend std::ostream & operator << (std::ostream &out, const Polynomials &p); //friend function for Polynomials class
                                                                                //it can access all members of this class.
    };

#endif
