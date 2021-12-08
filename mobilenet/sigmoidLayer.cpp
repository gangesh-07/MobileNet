#define _CRT_SECURE_NO_WARNINGS

#include "sigmoidLayer.h"
#include <cmath>

SigmoidLayer::SigmoidLayer(int nInputSize) : InputSize(nInputSize)
{
    Output = new float[InputSize];
}

SigmoidLayer::~SigmoidLayer()
{
    delete[] Output;
}

void SigmoidLayer::forward(float *Input)
{
    for (int i = 0; i < InputSize; i++)
    {
        Output[i] = 1 / (1 + exp(-Input[i]));
    }
}

float *SigmoidLayer::GetOutput()
{
    return Output;
}