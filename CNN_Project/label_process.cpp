//
//  label_process.cpp
//  CNN_Project
//
//  Created by Yang on 2018/12/17.
//  Copyright © 2018 Yang. All rights reserved.
//

//
//  label_process.cpp
//  CNN_Project
//
//  Created by Yang on 2018/12/17.
//  Copyright © 2018 Yang. All rights reserved.
//

#include "cnn_header.hpp"
using namespace std;


void label_process(){
    
    string label_file;
    cout << "please input the file path of the label file" << endl;
    cin >> label_file;
    
    string temp;
    
    int n_var;
    cout << "How many labels do you want deal with?"<< endl;
    cin >> n_var;
    string A[n_var];
    int B[n_var];
    
    for(int i=0;i<n_var;i++){
        cout << "Please enter the label"<<endl;
        cin >> A[i];
        cout << "Please enter the value for label " << A[n_var] <<endl;
        cin >> B[i];
    }
    string label_file_name;
    cout << "Please input the outpur label file name"<< endl;
    cin >> label_file_name;
    string label_output = matlab_process_path + label_file_name;
    
    
    ifstream myfile(label_file); //input flow
    ofstream outfile(label_output, ios::app); // output flow
    
    if (!myfile.is_open()) {
        cout << "Unable to open this file" << endl;
    }
    
    while (!myfile.eof())
    {
        myfile >> temp;
        for(int i=0;i<n_var;i++){
            if (temp == A[i]) {
                outfile << B[i];
            }
        }
    }
    myfile.close();
    
    
}
