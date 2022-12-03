#pragma once
float* Add_Data(float* sample, int Size, float* x, int Dim);
float* Add_Labels(float* Labels, int Size, int label);
float* init_array_random(int len);
int YPoint(int x, float w[], float bias, float Carpan = 1.0);


int sign(double net);
double* initialize_random_weight(int size);
double* update_weight_discrete(double* Weights, double* SamplesArray, int size, int where, int Output, double desired, double learningRate);
double sDerivative(double out);
double sDerivative(double out);

float* normalizeData(float* Samples, int numSample, int inputDim);

double bipolar_continous_activation_fun(double net);


float perceptronTraining(float* Samples, float* Weights, float* targets, float* bias, int numSample, int inputDim);
float deltaTraining(float* Samples, float* Weights, float* targets, float* bias, int numSample, int inputDim);
float multiPerceptronTraining(float* Samples, float* Weights, float* targets, float* bias, int numSample, int inputDim, int numClass);
float multiDeltaTraining(float* Samples, float* Weights, float* targets, float* bias, int numSample, int inputDim, int numClass);
