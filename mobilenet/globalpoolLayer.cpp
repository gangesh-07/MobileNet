#include "globalpoolLayer.h"
#include <iostream>


GlobalPoolLayer::GlobalPoolLayer(int nOutputNum, int nInputWidth):
                        OutputNum(nOutputNum), InputWidth(nInputWidth), PoolWidth(nInputWidth)
{
    OutputWidth = 1;
    OutputSize = OutputWidth *OutputWidth;
    InputSize = InputWidth * InputWidth;
    
    Output = new float [OutputNum * OutputSize];
}

GlobalPoolLayer::~GlobalPoolLayer()
{
    delete[] Output;
}

void GlobalPoolLayer::forward(float *Input)
{
    for (int nOutmapIndex = 0; nOutmapIndex < OutputNum; nOutmapIndex++)
    {
        int nInputIndexStart, nInputIndex, nOutputIndex;
        nOutputIndex = nOutmapIndex * OutputSize;
        nInputIndexStart = nOutmapIndex * InputSize;
        float fSum = 0;
        for (int m = 0; m < PoolWidth; m++)
        {
            for (int n = 0; n<PoolWidth; n++)
            {
                nInputIndex = nInputIndexStart + m * InputWidth + n;
                fSum += Input[nInputIndex];
            }
        }

        Output[nOutputIndex] = fSum / InputSize;
    }    
}

float *GlobalPoolLayer::GetOutput()
{
    return Output;
}