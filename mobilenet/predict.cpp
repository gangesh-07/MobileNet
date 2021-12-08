#include "predict.h"
#include "MobileNet.h"
#include <string>
#include <fstream>
#include <direct.h>

float Accuracy(float *Pred, int *Label, int nclass)
{
    float flag = 0.0;
    for (int i = 0; i < nclass; i++)
    {
        //cout << Pred[i] << ':' << Label[i] << endl;
        if (Pred[i] >=0.5 && Label[i] == 1)
            flag = 1.0;
    }
    return flag;
}

void run(const char *pcTestListFile, const char *pcTestLabelsFile, const char *pcTestImageSet)
{
    Network network;

    ifstream file(pcTestListFile);   //name list of test images
    ifstream lab(pcTestLabelsFile);  //label list of test image
    string filename;
    const char *file_name;
    string line, label;
    string filepath = pcTestImageSet;  //path of image data

    char tmp[256];
    getcwd(tmp, 256);
    cout << "Current working directory: " << tmp << endl << pcTestListFile << ":" << pcTestLabelsFile << endl;

    int nNum = 3618, nClass = 12;
    float *Predict;
    int *nLl = new int[nClass];

    float accuracy = 0.0;

    int i = 0;
    cout << endl;
    if (file && lab)
    {
        while (getline(file, line) && getline(lab, label))
        {
            filename = filepath + line;
            file_name = filename.c_str();
            cout << "Image file: " << file_name << endl;
            Predict = network.Forward(file_name);
            for (int j = 0; j < nClass; j++)
                nLl[j] = label[2 * j] - '0'; 
            accuracy += Accuracy(Predict, nLl, nClass);

            i += 1;

        }
    }
    else
    {
        cout << "no such file" << endl;
    }

    cout << "i:" << i << endl;

    float AccurSum = accuracy / i;

    cout << "Accuracy: " << AccurSum << endl;
    
    system("pause");
	
    // You can use following codes to test only one image
	//input an image
    /*
    network.Forward(".\\data\\0.jpg");
    network.Forward(".\\data\\1.jpg");
    system("pause");
    */
}
