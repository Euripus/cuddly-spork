#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "analysis.h"
#include "PanTompkins.h"

#define FILENAME      "ecc.txt"
#define OUT_FILENAME  "r_ecc.txt"

void read_data(std::vector<float> & vec)
{
    vec.clear();
    std::ifstream in(FILENAME, std::ios_base::in);
    if (!in)
    {
        std::cerr << "Cannot open: " << FILENAME << std::endl;
        return;
    }
    
    std::string line;
    while (std::getline(in, line))
    {
        unsigned int tmp(0);
        tmp = std::atoi(line.c_str());
        
        if(tmp > 0 && tmp < 1024)
        {
            vec.push_back(tmp/1024.0f);
        }
        else
        {
            vec.push_back(0.0f);
        }
    }
    
    in.close();
}

void write_data(const std::string & fname, const std::vector<float> & vec)
{
    std::ofstream out(fname.c_str(), std::ios_base::out | std::ios_base::trunc);
    if (!out)
    {
        std::cerr << "Cannot open: " << fname << std::endl;
        return;
    }
    
    for(unsigned int i = 0; i < vec.size(); i++)
    {
        int tmp = vec[i]*1024;
        out << tmp << std::endl;
    }
    
    out.close();
}

int main(int argc, char **argv)
{
    std::vector<float> in_data;
    std::vector<float> r_data;
    
    read_data(in_data);
    
    //std::cout << "Size: " << in_data.size() << std::endl;
    //write_data(std::string("in.txt"), in_data);
    
    //r_filter(in_data, r_data);    
    //write_data(std::string(OUT_FILENAME), r_data);
    
    std::vector<float> pikes;
    for(unsigned int i = 0; i < in_data.size(); i++)
    {
        if(PanTompkins(in_data[i]))
        {
            pikes.push_back(1.0f);
        }
        else
        {
            pikes.push_back(0.0f);
        }       
    }
    write_data(std::string("pikes.txt"), pikes);
    //write_data(std::string("filter.txt"), r_data);
    
    return 0;
}
