#ifndef POOLAYER_H
#define POOLAYER_H

class GlobalPoolLayer
{
public:
    GlobalPoolLayer(int nOutputNum, int nInputWidth);
    ~GlobalPoolLayer();
    void forward(float *Input);
    float *GetOutput();

private:
    int OutputNum, PoolWidth, InputWidth;
    int PoolSize, OutputWidth, InputSize, OutputSize;
    
    float *Output;
};

#endif
