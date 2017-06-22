//
// Created by erik on 18.06.17.
//

#include "Loader.h"

Loader::Loader(const string &filename)
        : m_filename(filename)
{
}

Loader::~Loader() {
}

string Loader::load() {
    std::ifstream stream(m_filename);
    string str = "";
    stream >> str;
    return str;
}

void Loader::save(string serializedObj) {
    std::ofstream stream(m_filename);
    stream << serializedObj;
}

vector<string> split(string str, char delimiter) {
    std::stringstream ss(str);
    vector<string> result;

    while( ss.good() )
    {
        string substr;
        getline( ss, substr, delimiter );
        result.push_back( substr );
    }
    return result;
}