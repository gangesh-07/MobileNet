#ifndef FCLAYER_H
#define FCLAYER_H
#include <string>

class FcLayer
{
public:
    FcLayer(const char *pcWname, const char *pcBname, int nInputSize, int nOutputSize);
    ~FcLayer();
    void forward(float *Input);
    float *GetOutput();
    int GetOutputSize();
    void ReadFcWb(const char *pcWname, const char *pcBname);
    
private:
    int m_nInputSize, m_nOutputSize, m_nWeightSize, m_nRelubool;
    float *Weight, *Bias, *Output;
};

#endif
