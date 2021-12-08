#define _CRT_SECURE_NO_WARNINGS

#include "reluLayer.h"
#include <iostream>

using namespace std;

ReluLayer::ReluLayer(int nInputSize) : InputSize(nInputSize)
{
    Output = new float[InputSize];
}

ReluLayer::~ReluLayer()
{
    delete[] Output;
}

void ReluLayer::forward(float *pfInput)
{
    for (int i = 0; i < InputSize; i++)
    {
        if (pfInput[i] > 0)
            Output[i] = pfInput[i];
        else
            Output[i] = 0;
    }
}

float *ReluLayer::GetOutput()
{
    return Output;
}