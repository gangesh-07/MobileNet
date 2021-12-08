#ifndef CONVLAYER_H
#define CONVLAYER_H
#include <string>

class ConvLayer
{
public:
    ConvLayer(const char *pcWname, int nInputNum, int nOutputNum, int nInputWidth, int nKernelWidth, int nPad, int nStride=1, int nGroup=1, const char *pcBname = NULL);
    ~ConvLayer();
    void forward(float *Input);
    float *GetOutput();
    void ReadConvWb(const char *pcWname, const char *pcBname);
	void Addpad(float *Input);
    int GetOutputSize();
    
private:
    int InputNum, OutputNum, InputWidth, KernelWidth, Pad, Stride, Group, InputGroupNum, OutputGroupNum;
    float *InputPad, *Output;
	float *Weight;
    float *Bias;
    const char *m_pcBname;
    int InputPadWidth, OutputWidth;
    int KernelSize, InputSize, InputPadSize, OutputSize;
};

#endif
