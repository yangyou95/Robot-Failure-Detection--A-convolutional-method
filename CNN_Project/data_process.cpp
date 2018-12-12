//
//  data_process.cpp
//  CNN_Project
//
//  Created by Yang on 2018/12/5.
//  Copyright © 2018 Yang. All rights reserved.
//

#include "cnn_header.hpp"
using namespace std;


void split(string input_datafile_path);
void data_process(std::string buffer_input,std::string buffer_output){
    ifstream myfile(buffer_input); //input flow
    ofstream outfile(buffer_output, ios::app); // output flow
    string temp1,temp_name,buffer_label;
    buffer_label = buffer_output + "_label.txt";
    ofstream outfilelabel(buffer_label,ios::app);
    
    int i = 0; //Indice used for counting the numbers of read at input flow
    int k = 0; //Indice used for counting the matrix value
    if (!myfile.is_open()) {
        cout << "Unable to open this file" << endl;
    }
    
    while (!myfile.eof())
    {
        myfile >> temp1;
        if(i!=0&&i%91!=0){ // Store the matrix data
            outfile << temp1 << " ";
            k++;
            if (k % 6 == 0) {
                outfile << endl;
            }
        }else{  // Store the label information
            outfilelabel << temp1 <<endl;
        }
       i++;
    }
    myfile.close();
    
    // Split data process
    split(buffer_output);//Call split function
 
}

