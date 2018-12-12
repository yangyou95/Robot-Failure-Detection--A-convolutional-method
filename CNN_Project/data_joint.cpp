//
//  data_joint.cpp
//  CNN_Project
//
//  Created by Yang on 2018/12/9.
//  Copyright © 2018 Yang. All rights reserved.
//

#include "cnn_header.hpp"
using namespace std;

void data_joint(string input_folder,int number_files){
    string file_name ;
    string temp;
    cout << "Please enter the output file name, end with .txt" << endl;
    cin >> file_name;
    string output_file_path = matlab_process_path + file_name;
    ifstream input_data; // input flow
    ofstream os(output_file_path,ios::app); //output flow

    for (int i=0; i<number_files; i++) {
        string input_file = input_folder + std::to_string(i) + ".txt";
        input_data.open(input_file);
        while (!input_data.eof()) {
            input_data >> temp;
            os << temp << " ";
        }
        os << endl;
        input_data.close();
    }
    
    
}
