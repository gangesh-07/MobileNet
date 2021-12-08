#ifndef RELULAYER_H
#define RELULAYER_H

class ReluLayer
{
public:
    ReluLayer(int nInputSize);
    ~ReluLayer();
    void forward(float *Input);
    float *GetOutput();

private:
    int InputSize;
    float *Output;
};

#endif