#include <cassert>
#include "analysis.h"

// алгоритм Мерфи и Рангараж

const int m_filter_size = 8;
const int n_filter_size = 8;

void r_filter(const std::vector<float> & in, std::vector<float> & out)
{
    assert(in.size() > m_filter_size && in.size() > n_filter_size);
    
    std::vector<float> g1;
    g1.resize(in.size(), 0.0f);
    for(unsigned int count = n_filter_size; count < in.size(); count++)
    {
        float sum = 0.0f;
        for(unsigned int i = 0; i < n_filter_size; i++)
        {
            sum = sum + ((in[count - i + 1] - in[count - i])*(in[count - i + 1] - in[count - i])) 
                            * (n_filter_size - i + 1);
        }
        g1[count] = sum;
    }
    
    out.clear();
    out.resize(g1.size(), 0.0f);
    float m_inv = 1.0f / m_filter_size;
    for(unsigned int count = m_filter_size; count < g1.size(); count++)
    {
        float sum = 0.0f;
        for(unsigned int i = 0; i < m_filter_size; i++)
        {
            sum = sum + g1[count - i];
        }
        out[count] = m_inv * sum;
    }
}
