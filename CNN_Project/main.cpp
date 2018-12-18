//
//  main.cpp
//  CNN_Project
//
//  Created by Yang on 2018/12/1.
//  Copyright © 2018 Yang. All rights reserved.
//

#include "cnn_header.hpp"

using namespace std;

void data_process(std::string buffer_input,std::string buffer_output);
void label_process();

int main() {
    int n;
    cout << "Please select data process or label process. If data, enter 1; if label, enter 2. " << endl;
    cin >> n;
    if (n == 1) {
        string inp, outp;
        string input_path, output_path;
        cout << "please enter the name of input file\n";
        cin >> inp;
        cout << "please enter the name of output file including the path\n";
        cin >> outp;
        input_path = input_folder_path + inp;
        output_path = output_data_process_path + outp;
        data_process(input_path, output_path);
    }
    
    if (n == 2){
       label_process();
    }

    return 0;
}
