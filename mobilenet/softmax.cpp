#define _CRT_SECURE_NO_WARNINGS

#include "softmax.h"
#include <cmath>

SoftmaxLayer::SoftmaxLayer(int nInputSize) : InputSize(nInputSize)
{
    Output = new float[InputSize];
}

SoftmaxLayer::~SoftmaxLayer()
{
    delete[] Output;
}

void SoftmaxLayer::forward(float* Input)
{
	int i;
	float m, sum, constant;

	m = -INFINITY;
	for (i = 0; i < InputSize; ++i) {
		if (m < Input[i]) {
			m = Input[i];
		}
	}

	sum = 0.0;
	for (i = 0; i < InputSize; ++i) {
		sum += exp(Input[i] - m);
	}

	constant = m + log(sum);
	for (i = 0; i < InputSize; ++i) {
		Output[i] =  exp(Input[i] - constant);
	}
}

float* SoftmaxLayer::GetOutput()
{
    return Output;
}