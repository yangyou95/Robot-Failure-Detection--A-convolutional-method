//
//  convolution.cpp
//  CNN_Project
//
//  Created by Yang on 2018/12/5.
//  Copyright © 2018 Yang. All rights reserved.
//

#include "cnn_header.hpp"
using namespace std;

void conv(string conv_input,string conv_output, int c){
    int col = 6;
    int row = 90/col; // Every sample has 90 data number.
    int i_row,
        j_col,
        q = 0; // Counter for input reading
    string temp;
    
    int a[row][col]; // Initilize input data matrix
    double M[row- 2 ][col- 2]; // store the convoluted data
    // define the convolition kernel
//    double ck1[3][3] = {0.1111,0.1111,0.1111,
//        0.1111,0.1111,0.1111,
//        0.1111,0.1111,0.1111
//    };
    
    // Gaussian kernel
    double ck2[3][3] = {0.0751136, 0.123841, 0.0751136,
                        0.123841, 0.20418, 0.123841,
                        0.0751136, 0.123841, 0.0751136
    };
    
    ifstream conv_in(conv_input); //input flow
    ofstream conv_out(conv_output, ios::app); // output flow
 
// read the data
    while (!conv_in.eof())
    {
        conv_in >> temp;
        int int_temp = atof(temp.c_str()); // string to int
        i_row = q/col;
        j_col = q%col;
        a[i_row][j_col] = int_temp;
        q++;
        
    }
    
   
    //convolution compute
    for (int i = 0; i<= row - 3 ; i ++) {
        for (int j =0; j <= col - 3; j++){
            double sum =0;
            //conv process
            for (int k = 0; k < 3 ; k++) {
                for (int l = 0; l < 3; l ++) {
                    double tem = ck2[k][l] * a[i + k][j + l];
                    sum = sum + tem;
                    double f_val = sum/9;
                    M[i][j] = f_val;
                    
                }
            }
            
        }
    }
    
    // write the convoluted result to the output file
    for (int indice_row = 0; indice_row < row - 3 + 1 ; indice_row++) {
        for (int indice_col = 0; indice_col < col - 3 + 1; indice_col++) {
            conv_out << M[indice_row][indice_col] << " ";
        }
        conv_out << endl;
    }
    
}
