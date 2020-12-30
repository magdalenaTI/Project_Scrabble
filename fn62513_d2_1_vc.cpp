/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Magdalena Ivanova
* @idnumber 62513
* @task 1
* @compiler VC
*
*/

#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;

int Abs(int N) {         //function for absolute value
    if (N < 0)
    {  N = (-1) * N; } 
    return N;
}

//function for checking if the array is triangle
bool isTriangle(int N, int arrNum[])   
{
    for (int i = 0; i < N / 2; i++)
    {

        if (Abs(arrNum[i] - arrNum[i + 1]) != Abs(arrNum[N - i - 2] - arrNum[N - i - 1]))
        {
            return false;
        }
    }
    return true;
}

int main() {
    // N- number of elements
    int N;
    std::cin >> N;

    //the elements in array
    int arrNum[100];

   // the user inputs the elements in the array
    int userInput;
    for (int i = 0; i < N; i++) {
        cin >> userInput;

        //validation
        if (userInput < 3 || userInput > 100) { 
            cout << "Wrong input!";
            return -1;
        }
        arrNum[i] = userInput;
    }
    if (isTriangle(N, arrNum))
    {
      cout << "Array is triangle!";
    }
    else cout << "Array is not triangle!";
}


