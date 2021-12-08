#ifndef BATCHNORMAL_H
#define BATCHNORMAL_H

class BatchNormalLayer
{
public:
    BatchNormalLayer(const char *pcMname, const char *pcVname, const char *pcFname, const char *pcBname, int nInputNum, int nInputWidth);
    ~BatchNormalLayer();
    void forward(float *Input);
    float *GetOutput();
    int GetOutputSize();
    void ReadParam(const char *pcMname, const char *pcVname, const char *pcFname, const char *pcBname);

private:
    float Scale;
    int InputNum, InputWidth, InputSize;
    float *Mean, *Var, *Filler, *Bias, *Output;

};

#endif
