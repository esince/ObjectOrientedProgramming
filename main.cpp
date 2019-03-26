/*@Author
 * Student Name: Esin Ece Aydın
 * Student ID: 150160151
 * Date: 23.03.2019
*/

#include<iostream>
#include<fstream> //for ifstream
#include"Vectors.h" //my library <3
#include"Polynomials.h" //my library <3

using namespace std;

int main(){
    //temporary objects to get sizeV and sizeP
    Polynomials p;
    int sizeP = p.getsize() +1;

    Vectors v;
    int sizeV = v.getsize() +1;

    //user interface begin:
    cout <<  "Polynomial and Vector List Program!" << endl;
    cout << "Polynomials and Vectors are read from text files!" << endl;
    cout << endl;
    bool exit_condition = false; // if 0. option is selected it becomes true
    int option; //user's option

    cout << "Possible Actions:" << endl;
    cout << "1. Print Polynomial and Vector lists" << endl;
    cout << "2. Do a polynomial operation" << endl;
    cout << "3. Do a vector operation" << endl;
    cout << "4. Help: Print possible actions" << endl;
    cout << "0. Exit the program" << endl;

    cout << endl;

    while(!exit_condition ){
        cout <<  "Enter an option: ";
        cin >> option;

        switch (option) {
            case 1:
            {
                cout << "Vectors:" << endl;
                for(int i = 1; i < sizeV; i++){
                    cout << i << ". ";
                    Vectors objV(i); // create new Vectors objects according to linenumber
                    cout << objV; // << operator Overloading
                    cout << endl;
                }//destructor is invoked
                cout << endl;
                cout << "Polynomials:" << endl;

                for(int i = 1; i < sizeV; i++){
                    cout << i << ". ";
                    Polynomials objP(i); // create new Polynomials objects according to linenumber
                    cout << objP; // << operator Overloading
                    cout << endl;
                }//destructor is invoked
                break;
            }//case 1
            case 2:
            {
                cout << "Which polynomial operation would you like to do? (+:addition, *:multiplication):" << endl;
                int secondOperand, firstOperand;
                char op;
                //get inputs from user
                cin >> firstOperand >> op >> secondOperand;

                //create Polynomials objects according to user's selection
                Polynomials obj1(firstOperand);
                Polynomials obj2(secondOperand);

                if(op == '*'){
                    cout << "(" << obj1 << ")" << " * " << "(" << obj2 << ")";
                    cout << " = ";
                    obj1 * obj2; // * operator Overloading
                }
                else if(op == '+'){
                    cout << "(" << obj1 << ")" << " + " << "(" << obj2 << ")";
                    cout << " = ";
                    obj1 + obj2; // + operator Overloading
                }
                break;
            }//case 2
            case 3:
            {
                cout << "3. selected" << endl;
                cout << "Which vector operation would you like to do? (+:addition, *:scalar multiplication, .:dot product):" << endl;
                int secondOperand, firstOperand;
                char op;
                //get inputs from user
                cin >> firstOperand >> op >> secondOperand;

                //create Vectors objects according to user's selection
                Vectors obj1(firstOperand);
                Vectors obj2(secondOperand);

                if(op == '.'){
                    cout << obj1  << " . " << obj2;
                    cout << " = ";
                    obj1 * obj2; // * operator Overloading
                }
                else if(op == '+'){
                    cout << obj1  << " + " << obj2;
                    cout << " = ";
                    obj1 + obj2; // + operator Overloading
                }
                else if(op == '*'){
                    cout << obj1  << " * " << secondOperand;
                    cout << " = ";
                    obj1 * secondOperand; // * operator Overloading
                }
                break;
            }//case 3
            case 4:
            {
                cout << "Possible Actions:" << endl;
                cout << "1. Print Polynomial and Vector lists" << endl;
                cout << "2. Do a polynomial operation" << endl;
                cout << "3. Do a vector operation" << endl;
                cout << "4. Help: Print possible actions" << endl;
                cout << "0. Exit the program" << endl;

                cout << endl;
                break;
            }//case 4
            case 0:
            {
                exit_condition = true;
                break;
            }//case 0
            default:
                cout << "There is no option like you have just selected!" << endl;
                break;
        }//switch end

        cout << endl;
    }//while(!exit_condition)

  return 0;
}
