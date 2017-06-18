//
// Created by erik on 18.06.17.
//

#include "Loader.h"

Loader::Loader(string filename) {
 stream = new fstream(filename);
}

Loader::~Loader() {
    stream->close();
    delete stream;
    stream = nullptr;
}

string Loader::load() {
    string str = "";
    *stream >> str;
    return str;
}

void Loader::save(string serializedObj) {
    *stream << serializedObj;
}

vector<string> split(string str, char delimiter) {
    stringstream ss(str);
    vector<string> result;

    while( ss.good() )
    {
        string substr;
        getline( ss, substr, delimiter );
        result.push_back( substr );
    }
    return result;
}