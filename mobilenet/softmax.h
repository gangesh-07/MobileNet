#ifndef SOFTMAX_H
#define SOFTMAX_H

class SoftmaxLayer
{
public:
    SoftmaxLayer(int InputSize);
    ~SoftmaxLayer();
    void forward(float* Input);
    float* GetOutput();

private:
    int InputSize;
    float* Output;
};

#endif
