#include "Network.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Network::Network()
{

	cout << "Initializing Network..." << endl;

	m_Readdata = new ReadData( 224, 224, 3);

    m_Layers_bn = new Layers_Bn(3, 32, 224, 2, "..\\binary_files\\conv1.weights", "..\\binary_files\\conv1_bn.mean", "..\\binary_files\\conv1_bn.variance", "..\\binary_files\\conv1_bn.filler",
        "..\\binary_files\\conv1_bn.bias_filler");

    m_Layers_ds2_1 = new Layers_Ds(32, 64, 112, 1, "..\\binary_files\\conv2_1_dw.weights", "..\\binary_files\\conv2_1_bn_dw.mean", "..\\binary_files\\conv2_1_bn_dw.variance", "..\\binary_files\\conv2_1_bn_dw.filler",
        "..\\binary_files\\conv2_1_bn_dw.bias_filler", "..\\binary_files\\conv2_1_sep.weights", "..\\binary_files\\conv2_1_bn_sep.mean", "..\\binary_files\\conv2_1_bn_sep.variance", "..\\binary_files\\conv2_1_bn_sep.filler",
        "..\\binary_files\\conv2_1_bn_sep.bias_filler");

    m_Layers_ds2_2 = new Layers_Ds(64, 128, 112, 2, "..\\binary_files\\conv2_2_dw.weights", "..\\binary_files\\conv2_2_bn_dw.mean", "..\\binary_files\\conv2_2_bn_dw.variance", "..\\binary_files\\conv2_2_bn_dw.filler",
        "..\\binary_files\\conv2_2_bn_dw.bias_filler", "..\\binary_files\\conv2_2_sep.weights", "..\\binary_files\\conv2_2_bn_sep.mean", "..\\binary_files\\conv2_2_bn_sep.variance", "..\\binary_files\\conv2_2_bn_sep.filler",
        "..\\binary_files\\conv2_2_bn_sep.bias_filler");

    m_Layers_ds3_1 = new Layers_Ds(128, 128, 56, 1, "..\\binary_files\\conv3_1_dw.weights", "..\\binary_files\\conv3_1_bn_dw.mean", "..\\binary_files\\conv3_1_bn_dw.variance", "..\\binary_files\\conv3_1_bn_dw.filler",
        "..\\binary_files\\conv3_1_bn_dw.bias_filler", "..\\binary_files\\conv3_1_sep.weights", "..\\binary_files\\conv3_1_bn_sep.mean", "..\\binary_files\\conv3_1_bn_sep.variance", "..\\binary_files\\conv3_1_bn_sep.filler",
        "..\\binary_files\\conv3_1_bn_sep.bias_filler");

    m_Layers_ds3_2 = new Layers_Ds(128, 256, 56, 2, "..\\binary_files\\conv3_2_dw.weights", "..\\binary_files\\conv3_2_bn_dw.mean", "..\\binary_files\\conv3_2_bn_dw.variance", "..\\binary_files\\conv3_2_bn_dw.filler",
        "..\\binary_files\\conv3_2_bn_dw.bias_filler", "..\\binary_files\\conv3_2_sep.weights", "..\\binary_files\\conv3_2_bn_sep.mean", "..\\binary_files\\conv3_2_bn_sep.variance", "..\\binary_files\\conv3_2_bn_sep.filler",
        "..\\binary_files\\conv3_2_bn_sep.bias_filler");

    m_Layers_ds4_1 = new Layers_Ds(256, 256, 28, 1, "..\\binary_files\\conv4_1_dw.weights", "..\\binary_files\\conv4_1_bn_dw.mean", "..\\binary_files\\conv4_1_bn_dw.variance", "..\\binary_files\\conv4_1_bn_dw.filler",
        "..\\binary_files\\conv4_1_bn_dw.bias_filler", "..\\binary_files\\conv4_1_sep.weights", "..\\binary_files\\conv4_1_bn_sep.mean", "..\\binary_files\\conv4_1_bn_sep.variance", "..\\binary_files\\conv4_1_bn_sep.filler",
        "..\\binary_files\\conv4_1_bn_sep.bias_filler");

    m_Layers_ds4_2 = new Layers_Ds(256, 512, 28, 2, "..\\binary_files\\conv4_2_dw.weights", "..\\binary_files\\conv4_2_bn_dw.mean", "..\\binary_files\\conv4_2_bn_dw.variance", "..\\binary_files\\conv4_2_bn_dw.filler",
        "..\\binary_files\\conv4_2_bn_dw.bias_filler", "..\\binary_files\\conv4_2_sep.weights", "..\\binary_files\\conv4_2_bn_sep.mean", "..\\binary_files\\conv4_2_bn_sep.variance", "..\\binary_files\\conv4_2_bn_sep.filler",
        "..\\binary_files\\conv4_2_bn_sep.bias_filler");

    m_Layers_ds5_1 = new Layers_Ds(512, 512, 14, 1, "..\\binary_files\\conv5_1_dw.weights", "..\\binary_files\\conv5_1_bn_dw.mean", "..\\binary_files\\conv5_1_bn_dw.variance", "..\\binary_files\\conv5_1_bn_dw.filler",
        "..\\binary_files\\conv5_1_bn_dw.bias_filler", "..\\binary_files\\conv5_1_sep.weights", "..\\binary_files\\conv5_1_bn_sep.mean", "..\\binary_files\\conv5_1_bn_sep.variance", "..\\binary_files\\conv5_1_bn_sep.filler",
        "..\\binary_files\\conv5_1_bn_sep.bias_filler");

    m_Layers_ds5_2 = new Layers_Ds(512, 512, 14, 1, "..\\binary_files\\conv5_2_dw.weights", "..\\binary_files\\conv5_2_bn_dw.mean", "..\\binary_files\\conv5_2_bn_dw.variance", "..\\binary_files\\conv5_2_bn_dw.filler",
        "..\\binary_files\\conv5_2_bn_dw.bias_filler", "..\\binary_files\\conv5_2_sep.weights", "..\\binary_files\\conv5_2_bn_sep.mean", "..\\binary_files\\conv5_2_bn_sep.variance", "..\\binary_files\\conv5_2_bn_sep.filler",
        "..\\binary_files\\conv5_2_bn_sep.bias_filler");

    m_Layers_ds5_3 = new Layers_Ds(512, 512, 14, 1, "..\\binary_files\\conv5_3_dw.weights", "..\\binary_files\\conv5_3_bn_dw.mean", "..\\binary_files\\conv5_3_bn_dw.variance", "..\\binary_files\\conv5_3_bn_dw.filler",
        "..\\binary_files\\conv5_3_bn_dw.bias_filler", "..\\binary_files\\conv5_3_sep.weights", "..\\binary_files\\conv5_3_bn_sep.mean", "..\\binary_files\\conv5_3_bn_sep.variance", "..\\binary_files\\conv5_3_bn_sep.filler",
        "..\\binary_files\\conv5_3_bn_sep.bias_filler");

    m_Layers_ds5_4 = new Layers_Ds(512, 512, 14, 1, "..\\binary_files\\conv5_4_dw.weights", "..\\binary_files\\conv5_4_bn_dw.mean", "..\\binary_files\\conv5_4_bn_dw.variance", "..\\binary_files\\conv5_4_bn_dw.filler",
        "..\\binary_files\\conv5_4_bn_dw.bias_filler", "..\\binary_files\\conv5_4_sep.weights", "..\\binary_files\\conv5_4_bn_sep.mean", "..\\binary_files\\conv5_4_bn_sep.variance", "..\\binary_files\\conv5_4_bn_sep.filler",
        "..\\binary_files\\conv5_4_bn_sep.bias_filler");

    m_Layers_ds5_5 = new Layers_Ds(512, 512, 14, 1, "..\\binary_files\\conv5_5_dw.weights", "..\\binary_files\\conv5_5_bn_dw.mean", "..\\binary_files\\conv5_5_bn_dw.variance", "..\\binary_files\\conv5_5_bn_dw.filler",
        "..\\binary_files\\conv5_5_bn_dw.bias_filler", "..\\binary_files\\conv5_5_sep.weights", "..\\binary_files\\conv5_5_bn_sep.mean", "..\\binary_files\\conv5_5_bn_sep.variance", "..\\binary_files\\conv5_5_bn_sep.filler",
        "..\\binary_files\\conv5_5_bn_sep.bias_filler");

    m_Layers_ds6 = new Layers_Ds(512, 1024, 14, 2, "..\\binary_files\\conv6_dw.weights", "..\\binary_files\\conv6_bn_dw.mean", "..\\binary_files\\conv6_bn_dw.variance", "..\\binary_files\\conv6_bn_dw.filler",
        "..\\binary_files\\conv6_bn_dw.bias_filler", "..\\binary_files\\conv6_sep.weights", "..\\binary_files\\conv6_bn_sep.mean", "..\\binary_files\\conv6_bn_sep.variance", "..\\binary_files\\conv6_bn_sep.filler",
        "..\\binary_files\\conv6_bn_sep.bias_filler");

    m_Layers_ds7 = new Layers_Ds(1024, 1024, 7, 1, "..\\binary_files\\conv7_dw.weights", "..\\binary_files\\conv7_bn_dw.mean", "..\\binary_files\\conv7_bn_dw.variance", "..\\binary_files\\conv7_bn_dw.filler",
        "..\\binary_files\\conv7_bn_dw.bias_filler", "..\\binary_files\\conv7_sep.weights", "..\\binary_files\\conv7_bn_sep.mean", "..\\binary_files\\conv7_bn_sep.variance", "..\\binary_files\\conv7_bn_sep.filler",
        "..\\binary_files\\conv7_bn_sep.bias_filler");

    m_Poollayer = new GlobalPoolLayer(1024, 7);

    //m_Convlayer7 = new ConvLayer("..\\binary_files\\fc7.weights", 1024, 12, 1, 1, 0, 1, 1, "..\\binary_files\\fc7.biases");
    m_Fclayer = new FcLayer("..\\binary_files\\fc.weights", "..\\binary_files\\fc.biases", 1024, 325);

 
    Softmax = new SoftmaxLayer(325);

	
    ifstream input("..\\class_list.txt");
    //input.open("..\\class_list.txt");
    string line,temp;
    const char* str;
    int c = 0;
    while (getline(input, line))
    {
        //istringstream ss(line);
        //ss >> temp;
        cout << line << endl;
        str = line.c_str();
        m_vcClass.push_back(str);
    }
    
    input.close();

    //315 directories, but tensorflow detected 325 classes for some reason. Add 10 other categories 
    for (int i = 0; i < 10; i++)
        m_vcClass.push_back("Other");

    cout << "Classes: " << m_vcClass.size() << "--->" << m_vcClass[0] << endl;

	cout << "Initializing Done..." << endl;
	cout << endl;

}


Network::~Network()
{
	delete m_Readdata;
    delete m_Layers_bn;
    delete m_Layers_ds1;
    delete m_Layers_ds2_1;
    delete m_Layers_ds2_2;
    delete m_Layers_ds3_1;
    delete m_Layers_ds3_2;
    delete m_Layers_ds4_1;
    delete m_Layers_ds4_2;
    delete m_Layers_ds5_1;
    delete m_Layers_ds5_2;
    delete m_Layers_ds5_3;
    delete m_Layers_ds5_4;
    delete m_Layers_ds5_5;
    delete m_Layers_ds6;
    delete m_Layers_ds7;
    delete m_Poollayer;
    //delete m_Convlayer7;
    delete m_Fclayer;
    delete Softmax;
}


float *Network::Forward(const char *pcName)
{

    m_Layers_bn->forward(m_Readdata->ReadInput(pcName));

    m_Layers_ds2_1->forward(m_Layers_bn->GetOutput());
    m_Layers_ds2_2->forward(m_Layers_ds2_1->GetOutput());
    
    m_Layers_ds3_1->forward(m_Layers_ds2_2->GetOutput());
    m_Layers_ds3_2->forward(m_Layers_ds3_1->GetOutput());

    m_Layers_ds4_1->forward(m_Layers_ds3_2->GetOutput());
    m_Layers_ds4_2->forward(m_Layers_ds4_1->GetOutput());

    m_Layers_ds5_1->forward(m_Layers_ds4_2->GetOutput());
    m_Layers_ds5_2->forward(m_Layers_ds5_1->GetOutput());
    m_Layers_ds5_3->forward(m_Layers_ds5_2->GetOutput());
    m_Layers_ds5_4->forward(m_Layers_ds5_3->GetOutput());
    m_Layers_ds5_5->forward(m_Layers_ds5_4->GetOutput());
    
    m_Layers_ds6->forward(m_Layers_ds5_5->GetOutput());
    m_Layers_ds7->forward(m_Layers_ds6->GetOutput());

    m_Poollayer->forward(m_Layers_ds7->GetOutput());

    //m_Convlayer7->forward(m_Poollayer6->GetOutput());
    m_Fclayer->forward(m_Poollayer->GetOutput());

  
    Softmax->forward(m_Fclayer->GetOutput());

    float *Output = Softmax->GetOutput();
	vector <int> argmax;
	vector <float> Max;

    //int nOutputSize = m_Convlayer7->GetOutputSize();
    int nOutputSize = m_Fclayer->GetOutputSize();
	for (int i = 0; i<nOutputSize; i++)
	{

		if (Output[i] > 0.5)
		{
			argmax.push_back(i);
			Max.push_back(Output[i]);
		}
	}
	cout << endl;
	for (int i = 0; i < argmax.size(); i++)
	{
		cout << Max[i] << ": " << argmax[i] << ": " << m_vcClass[argmax[i]] << endl;
	}
	cout << endl;
    
    return Output;
}
