#ifndef READDATA_H
#define READDATA_H


class ReadData
{
public:
	ReadData( int nInputWidth, int nInputHeight, int nInputChannel);
	~ReadData();
	float *ReadInput(const char *pcName);

private:
	int m_nInputSize, m_nInputWidth, m_nInputHeight, m_nInputChannel, m_nImageSize;
	float* InputData;

};


#endif
