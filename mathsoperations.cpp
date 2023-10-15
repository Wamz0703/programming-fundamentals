#include <iostream>
#include <cmath>

using namespace std;
void performNumberoperations(){
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    double sum = num1 + num2;
    double product = num1 * num2;
    double qoutient = num1 / num2;
    double difference = num1 - num2;
    double exponent = pow(num1, num2);
    int remainder = static_cast<int>(num1)% static_cast<int>(num2);
    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << qoutient << endl;
    cout << "Remainder: " << remainder << endl;
    cout << "Exponent: " << exponent << endl;


}

void performMatrixoperations(){
    int numRows, numCols;
    cout << "Enter the dimentions of them matrices(rows columns): ";
    cin >> numRows >> numCols;
    
    int matrix1[numRows][numCols], matrix2[numRows][numCols], resultmatrix[numRows][numCols];
    cout << "Enter the elements of the first matrix:\n";
    for(int i =0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            cout << "Enter Elements" << i + 1 <<", "<< j + 1 <<", ";
            cin >> matrix1[i][j];

        }
    }
    cout << "Enter the elements of the second matrix:\n";
    for(int i = 0; i < numRows; i++){
       for(int j = 0; j < numCols; j++){
        cout << "Enter Elements" << i + 1 << ", " << j + 1 <<", ";
        cin >> matrix2[i][j];
       }
    }

    /*addition*/
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            resultmatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    cout << "\nAddition of the matrices:\n";
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            cout << resultmatrix[i][j] << "";
        } 
        cout << endl;
    }
    //subtractiom
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            resultmatrix[i][j] = matrix1[i][j] - matrix2[i][j];

        }
    }
    cout << "\nsubtraction of the matrices:\n";
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            cout << resultmatrix[i][j] << "";
        }
        cout<< endl;
    }
}
    int main(){
        int choice;
        cout << "Enter 1 for number operations or 2 for matrix operations:";
        cin >> choice;
        

        if(choice == 1){
            performNumberoperations();
        }
        else if(choice == 2){
            performMatrixoperations();
        }
        else{
            cout << "invalid choice!\n";
        }
    return 0;
}
   