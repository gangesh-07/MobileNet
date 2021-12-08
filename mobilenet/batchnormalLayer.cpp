
#define _CRT_SECURE_NO_WARNINGS

#include "batchnormalLayer.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <cassert>
#include <cmath> 

using namespace std;

BatchNormalLayer::BatchNormalLayer(const char *pcMname, const char *pcVname, const char *pcFname, const char *pcBname, int nInputNum, int nInputWidth) :
    InputNum(nInputNum), InputWidth(nInputWidth)
{
    InputSize = InputWidth * InputWidth;
    Output = new float[InputNum * InputSize];
    Mean = new float[InputNum];
    Var = new float[InputNum];
    Filler = new float[InputNum];
    Bias = new float[InputNum];
    ReadParam(pcMname, pcVname, pcFname, pcBname);
}

BatchNormalLayer::~BatchNormalLayer()
{
    delete[] Output;
    delete[] Mean;
    delete[] Var;
    delete[] Filler;
    delete[] Bias;
}

void BatchNormalLayer::forward(float *pfInput) 
{
    for (int i = 0; i < InputNum; i++)
    {
        for (int j = 0; j < InputSize; j++)
        {
            int nOutputIndex = i * InputSize + j;

            Output[nOutputIndex] = Filler[i] * ((pfInput[nOutputIndex] - Mean[i])
                / sqrt(Var[i] + 1e-5)) + Bias[i];
        }
    }
}

void BatchNormalLayer::ReadParam(const char *pcMname, const char *pcVname, const char *pcFname, const char *pcBname)
{
    int nMsize, nVsize, nFsize, nBsize, nMreadsize, nVreadsize, nFreadsize, nBreadsize;
    FILE *pM, *pV, *pF, *pB;
    pM = fopen(pcMname, "rb");
    pV = fopen(pcVname, "rb");
    pF = fopen(pcFname, "rb");
    pB = fopen(pcBname, "rb");

    assert((pM != NULL) && (pV != NULL) && (pF != NULL) && (pB != NULL));

    nMsize = InputNum;
    nVsize = InputNum;
    nFsize = InputNum;
    nBsize = InputNum;

    nMreadsize = fread(Mean, sizeof(float), nMsize, pM);
    assert(nMreadsize <= nMsize);

    fclose(pM);
    cout << "mean: " << nMreadsize << ", ";

    nVreadsize = fread(Var, sizeof(float), nVsize, pV);
    assert(nVreadsize <= nVsize);

    cout << "variance: " << nVreadsize << ", ";

    nFreadsize = fread(Filler, sizeof(float), nFsize, pF);
    assert(nFreadsize <= nFsize);

    cout << "filler: " << nFreadsize << ", ";

    nBreadsize = fread(Bias, sizeof(float), nBsize, pB);
    assert(nBreadsize <= nBsize);

    cout << "bias_filler: " << nBreadsize << endl;

}

float *BatchNormalLayer::GetOutput()
{
    return Output;
}

int BatchNormalLayer::GetOutputSize()
{
    return InputNum * InputSize;
}
