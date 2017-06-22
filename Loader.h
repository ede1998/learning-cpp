//
// Created by erik on 18.06.17.
//

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using std::string;
using std::vector;

class Loader {
public:
    Loader(const string &filename);
    ~Loader();


    string load();
    void save(string serializedObj);
private:
    const string m_filename;
};

vector<string> split(string str, char delimiter);
