//
// Created by micha on 12/1/2023.
//
#include <iostream>
#include <string>
#include "Window.h"

int main() {
    std::cout << "hello world";
    Window test = Window();
    vector<string> output;
    output = test.start();
    for(int i = 0; i < output.size(); i++){
        std::cout << output[i] << std::endl;
    }
}