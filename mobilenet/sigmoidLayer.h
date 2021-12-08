#ifndef SIGMOIDLAYER_H
#define SIGMOIDLAYER_H

class SigmoidLayer
{
public:
    SigmoidLayer(int InputSize);
    ~SigmoidLayer();
    void forward(float *Input);
    float *GetOutput();

private:
    int InputSize;
    float *Output;
};

#endif
