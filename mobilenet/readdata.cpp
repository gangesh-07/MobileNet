#include "readdata.h"
#include <opencv2/opencv.hpp>
#include "opencv2/imgcodecs/legacy/constants_c.h"
#include <iostream>
#include <ctime>
#include <cassert>
#include <fstream>

using namespace std;

ReadData::ReadData(int nInputWidth, int nInputHeight, int nInputChannel):
			m_nInputWidth(nInputWidth), m_nInputHeight(nInputHeight), m_nInputChannel(nInputChannel)
{
	m_nImageSize = nInputWidth * nInputHeight;
	m_nInputSize = nInputWidth * nInputHeight * nInputChannel;
	InputData = new float[m_nInputSize];
	
}

ReadData::~ReadData()
{
	delete[] InputData;
}

float *ReadData::ReadInput(const char *pcName)
{
	cout << "Reading Picture: " << pcName << "..." << endl;

	const char *pstrImageName = pcName;

	
	//CvSize czSize;
	//IplImage *pSrcImage = cvLoadImage(pstrImageName, CV_LOAD_IMAGE_UNCHANGED);
	//IplImage *pDstImage = NULL;
	//czSize.width = m_nInputWidth;
	//czSize.height = m_nInputHeight;

	cv::Mat img;
	cv::imread(pstrImageName, cv::IMREAD_COLOR).convertTo(img, CV_32FC3, (1. / 255.));
	//cv::Mat pDstImage;
	//cout<<"Dimension:"<<img.

	
	//cv::resize(img, pDstImage, cv::Size(m_nInputWidth, m_nInputHeight));

	/*
	*	C_api is Depreciated in opencv2
	* 
	cvResize(pSrcImage, pDstImage, CV_INTER_LINEAR);
	pDstImage = cvCreateImage(czSize, pSrcImage->depth, pSrcImage->nChannels);
	uchar *pucData = (uchar *)pDstImage->imageData;
	int nStep = pDstImage.widthStep / sizeof(uchar);
	int nChannel = pDstImage->nChannels;
	int nOutputIndex = 0;

	*/

	//float* rgb_data = new float(img.rows * img.cols * img.channels()); // Dst
	//float* dataPointer = reinterpret_cast<float*>(img.data); // Src
	// pointer from, pointer two, size in bytes
	std::memcpy(InputData, img.data, 224*224*3 * sizeof(float));


	
	cout << "Reading Picture Done..." << endl;

	return InputData;
}
