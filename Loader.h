//
// Created by erik on 18.06.17.
//

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Loader {
public:
    Loader(string filename);
    ~Loader();


    string load();
    void save(string serializedObj);
private:
    fstream * stream;
};

vector<string> split(string str, char delimiter);
