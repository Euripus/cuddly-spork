#include "PanTompkins.h"
#include "CircularBuffer.h"
#include <vector>

const int M_COUNT = 8;
const int N_COUNT = 30;

struct my_treshold
{
    float treshold1;              // Порог сигнала зубца R
    float treshold2;              // порог шума
    float spki;                   // уровень сигнала
    float npki;                   // уровень шума
};

// globals
my_treshold               g_th  = { 0.8f,            // g_th.treshold1
                    0.4f,            // g_th.treshold2
                    0.35f,           // g_th.spki             // Начальные значения
                    0.35f };         // g_th.npki             // от фонаря :)

CircularBuffer<float, 64>      g_main_buf;
CircularBuffer<float, 64>      g_low_pass_buf;
CircularBuffer<float, 64>      g_high_pass_buf;
CircularBuffer<float, 64>      g_derivative_buf;
CircularBuffer<float, 64>      g_squaring_buf;
CircularBuffer<float, 64>      g_integration_buf;

bool DetectPike();

//  Алгоритм(фильтр) Пана-Томпкинса
bool PanTompkins(float val)
{
    g_main_buf.add(val);
    
    //Low-Pass Filter  фильтр низких частот
    if(g_main_buf.size() < 13)
        g_low_pass_buf.add(0.0f);
    else
        g_low_pass_buf.add(2.0f * g_low_pass_buf[0]
                   - g_low_pass_buf[-1]
                       + g_main_buf[0] 
                       - 2.0f * g_main_buf[-6]
                       + g_main_buf[-12]);
                        
    //High-Pass Filter фильтр высоких частот
    if(g_low_pass_buf.size() < 33)
        g_high_pass_buf.add(0.0f);
    else
        g_high_pass_buf.add(g_high_pass_buf[0]
                            - 1/32.0f * g_low_pass_buf[0]
                            + g_low_pass_buf[-16]
                            - g_low_pass_buf[-17]
                            + 1/32.0f * g_low_pass_buf[-32]);
                        
    //Derivative  оператор производной
    if(g_high_pass_buf.size() < 5)
        g_derivative_buf.add(0.0f);
    else
        g_derivative_buf.add(( 2.0f * g_high_pass_buf[0] 
                               + g_high_pass_buf[-1] 
                               - g_high_pass_buf[-3] 
                               - 2.0f * g_high_pass_buf[-4]) / 8.0f);
                           
    //Squaring Function  возведение в квадрат
    g_squaring_buf.add(g_derivative_buf[0] * g_derivative_buf[0]);
    
    //Moving-Window Integration  интегрирование
    if(g_squaring_buf.size() < N_COUNT)
        g_integration_buf.add(0.0f);
    else
    {
        float inv_n = 1.0 / N_COUNT;
        float sum = 0.0f;
        for(int i = 0; i > -N_COUNT; i--)
        {
            sum = sum + g_squaring_buf[i];
        }
        g_integration_buf.add(inv_n * sum);
    }
    
    return DetectPike();
}

// Фильтр поиска результата
bool DetectPike()
{
    float pike = 0.0f;
    bool res = false;
    
    // сглаживание результатов
    if(g_integration_buf.size() < M_COUNT)
        return res;
    else
    {
        float m_inv = 1.0f / M_COUNT;
        float sum = 0.0f;
        
        for(int i = 0; i > -M_COUNT; i--)
        {
            sum = sum + g_integration_buf[i];
        }
        pike = m_inv * sum;                                        // локальный пик
    }

    
    // пороговая процедура                                     
    if(pike > g_th.treshold1)
    {
        res = true;                                                // зубец R
        g_th.spki = 0.125 * pike + 0.875 * g_th.spki;
        
        g_th.treshold1 = g_th.npki + 0.25 * (g_th.spki - g_th.npki);   // адаптивное изменение пороговых уровней
        g_th.treshold2 = 0.5 * g_th.treshold1;
    }
    else
    {
        if(pike > g_th.treshold2)
        {
            g_th.npki = 0.125 * pike + 0.875 * g_th.npki;
            
            g_th.treshold1 = g_th.npki + 0.25 * (g_th.spki - g_th.npki);
            g_th.treshold2 = 0.5 * g_th.treshold1;
        }
    }
        
    return res;  
}