#define _CRT_SECURE_NO_WARNINGS

#include "convLayer.h"
#include <fstream>
#include <cassert>
#include <iostream>
#include <direct.h>

using namespace std;

ConvLayer::ConvLayer(const char *pcWname, int nInputNum, int nOutputNum, int nInputWidth, int nKernelWidth, int nPad, int nStride, int nGroup, const char *pcBname) :
    InputNum(nInputNum), OutputNum(nOutputNum), InputWidth(nInputWidth),
    KernelWidth(nKernelWidth), Pad(nPad), Stride(nStride), Group(nGroup), m_pcBname(pcBname)
{
    KernelSize = KernelWidth * KernelWidth;
    InputSize = InputWidth * InputWidth;
    InputPadWidth = InputWidth + 2 * Pad;
    InputPadSize = InputPadWidth * InputPadWidth;
    OutputWidth = int((InputPadWidth - KernelWidth) / Stride + 1);
    OutputSize = OutputWidth * OutputWidth;
    
	InputPad = new float[InputNum * InputPadWidth * InputPadWidth];

    InputGroupNum = InputNum / Group;
    OutputGroupNum = OutputNum / Group;

    Weight = new float[OutputNum * InputGroupNum * KernelSize];

    if (m_pcBname != NULL)
        Bias = new float[OutputNum];
    Output = new float[OutputNum * OutputSize];

	ReadConvWb(pcWname, pcBname);
}

ConvLayer::~ConvLayer()
{
    delete[] Output;
    if (m_pcBname != NULL)
        delete[] Bias;
    delete[] Weight;
	delete[] InputPad;
}

void ConvLayer::forward(float *pfInput)
{
    Addpad(pfInput);

    for (int g = 0; g < Group; g++)
    {
        for (int nOutmapIndex = 0; nOutmapIndex < OutputGroupNum; nOutmapIndex++)
        {
            for (int i = 0; i < OutputWidth; i++)
            {
                for (int j = 0; j < OutputWidth; j++)
                {
                    float fSum = 0;
                    int nInputIndex, nOutputIndex, nKernelIndex, nInputIndexStart, nKernelStart;
                    nOutputIndex = g * InputGroupNum * OutputSize + nOutmapIndex * OutputSize + i * OutputWidth + j;
                    for (int k = 0; k < InputGroupNum; k++)
                    {
                        nInputIndexStart = g * InputGroupNum * InputPadSize + k * InputPadSize + (i * Stride) * InputPadWidth + (j * Stride);
                        nKernelStart = g * OutputGroupNum * KernelSize + nOutmapIndex * InputGroupNum * KernelSize + k * KernelSize;
                        for (int m = 0; m < KernelWidth; m++)
                        {
                            for (int n = 0; n < KernelWidth; n++)
                            {
                                nKernelIndex = nKernelStart + m * KernelWidth + n;
                                nInputIndex = nInputIndexStart + m * InputPadWidth + n;
                                fSum += InputPad[nInputIndex] * Weight[nKernelIndex];
                            }
                        }
                    }
                    if (m_pcBname != NULL)
                        fSum += Bias[nOutmapIndex];

                    Output[nOutputIndex] = fSum;
                }
            }
        }              
    }
}

void ConvLayer::ReadConvWb(const char *pcWname, const char *pcBname)
{
    int nWsize, nBsize, nWreadsize, nBreadsize;
    FILE *pW, *pB;

    cout << pcWname << endl;
    char tmp[256];
    getcwd(tmp, 256);
    cout << "Current working directory: " << tmp << endl;
 
    pW = fopen(pcWname, "rb");
    
    assert(pW != NULL);

    nWsize = OutputNum * InputGroupNum * KernelSize;
	nWreadsize = fread(Weight, sizeof(float), nWsize, pW);
    fclose(pW);
    cout << "w: " << nWreadsize << endl;


    if (pcBname != NULL)
    {
        pB = fopen(pcBname, "rb");
        assert(pB != NULL);
        nBsize = OutputNum;

        nBreadsize = fread(Bias, sizeof(float), nBsize, pB);
        fclose(pB);
        assert(nBreadsize <= nBsize);
        cout << "b: " << nBreadsize << endl;
    }
}

float *ConvLayer::GetOutput()
{
    return Output;
}

void ConvLayer::Addpad(float *pfInput)
{
	for (int m = 0; m < InputNum; m++)
	{
		for (int i = 0; i < InputPadWidth; i++)
		{
			for (int j = 0; j < InputPadWidth; j++)
			{
                if ((i < Pad) || (i >= InputPadWidth - Pad))
                {
                    InputPad[m * InputPadSize + i * InputPadWidth + j] = 0;
                }
                else if ((j < Pad) || (j >= InputPadWidth - Pad))
                {
                    InputPad[m * InputPadSize + i * InputPadWidth + j] = 0;
                }
                else
                {
                    InputPad[m * InputPadSize + i * InputPadWidth + j] = pfInput[m * InputSize + (i - Pad) * InputWidth + (j - Pad)];
                }
			}
		}
	}
}

int ConvLayer::GetOutputSize()
{
    return OutputNum * OutputSize;
}