//
//  split_data.cpp
//  CNN_Project
//
//  Created by Yang on 2018/12/6.
//  Copyright © 2018 Yang. All rights reserved.
//

#include "cnn_header.hpp"
using namespace std;
void conv(string conv_input,string conv_output_folder, int c);
void data_joint(string input_folder,int number_files);

void split(string input_datafile_path){
    string folder_path;
    cout << "Please enter in which folder you want output, including / at the end "<<endl;
    cin >> folder_path;
    string output_folder_path = output_data_process_path + folder_path;
    string output_file_path, temp;
    string conv_input_file;
    string conv_ouptut;
    ifstream input_data(input_datafile_path); // input flow
    ofstream os; //output flow
    int i = 0;
    int j = 0; //indice for counting the input flow reading
    int c;
    int k; // return value
    string n = std::to_string(i);
    if(!input_data.is_open()){
        cout << "Unable to open the file for splitting" << endl;
    }
    while (!input_data.eof()) {
        input_data >> temp;
        n = std::to_string(i/90); // Every sample has 90 data number.
        output_file_path = output_folder_path + n + ".txt"; // initialize the first output file path
        os.open(output_file_path,ios::app);
        os << temp << " ";
        j++;
        if (j%6 == 0) {
            os << endl;
        }
        os.close();
        i++;
    }
    cout << "The data has been splited to " << n << " files, please check the sub data sets." << endl;
    
    k = i/90;
    
    //joint orginal data
    cout << "Data fusion for orginal data" <<endl;
    data_joint(output_folder_path,k);
    
    //Convolution process
    cout << "Please choose the type of convlution kernel, type 1 is the default value."<< endl;
    cin >> c;
    int l = 0;
    for(l=0;l<k;l++){
        conv_input_file = output_folder_path + std::to_string(l) + ".txt";
        conv_ouptut = output_conv_path + folder_path + std::to_string(l) + ".txt";;
        conv(conv_input_file,conv_ouptut, c); //Call Convolution function
    }
   
    // joint data for later matlab process
    
    conv_ouptut = output_conv_path + folder_path;
    cout << "Data fusion for convoluted data" <<endl;
    data_joint(conv_ouptut,k);
    
    
}
