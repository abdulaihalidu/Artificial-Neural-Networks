#include "pch.h"
#include <windows.h>
#include <time.h>
#include <iostream>
#include <random>
#include <cmath>

float* Add_Data(float* sample, int Size, float* x, int Dim) {
	float* temp;
	temp = new float[Size * Dim];
	for (int i = 0; i < (Size - 1) * Dim; i++)
		temp[i] = sample[i];
	for (int i = 0; i < Dim; i++)
		temp[(Size - 1) * Dim + i] = x[i];
	//Deallocate memory
	delete[] sample;
	return temp;
}//Add_data
float* Add_Labels(float* Labels, int Size, int label) {
	float* temp;
	temp = new float[Size];
	for (int i = 0; i < Size - 1; i++)
		temp[i] = Labels[i];
	temp[Size - 1] = float(label);
	//Deallocate memory
	delete[] Labels;
	return temp;
}
float* init_array_random(int len) {
	float* arr = new float[len];
	for (int i = 0; i < len; i++)
		arr[i] = ((float)rand() / RAND_MAX) - 0.5f;
	return arr;
}
int YPoint(int x, float w[], float bias, float Carpan = 1.0) {
	return (int)((Carpan * bias + w[0] * x) / (-w[1]));
}//YPoint


int sign(double net) {
	return net >= 0.0 ? 1 : -1;
}

double bipolar_continous_activation_fun(double net) {
	float fnet;
	fnet = (2 / (1 + exp(-net))) - 1;
	return fnet;
}

float* normalizeData(float* Samples, int numSample, int inputDim) {
	float* tempSamples = new float[numSample * inputDim];

	double Mx = 0;
	double My = 0;
	double number = 0;
	double x_sDeviation = 0;
	double y_sDeviation = 0;

	for (int i = 0; i < (numSample * inputDim); i++) {
		tempSamples[i] = Samples[i];
	}

	for (int i = 0; i <= ((numSample * inputDim)) - 2; (i += inputDim)) {
		Mx += Samples[i];
		My += Samples[i + 1];
		number++;
	}
	Mx = (Mx) / number;
	My = (My) / number;

	for (int i = 0; i <= ((numSample * inputDim) - 2); (i += inputDim)) {
		x_sDeviation += pow((tempSamples[i] - Mx), 2);
		y_sDeviation += pow((tempSamples[i + 1] - My), 2);
	}

	x_sDeviation = sqrt(x_sDeviation / number);
	y_sDeviation = sqrt(y_sDeviation / number);


	for (int i = 0; i <= ((numSample * inputDim) - 2); (i += inputDim)) {
		tempSamples[i] = (tempSamples[i] - Mx) / x_sDeviation;
		tempSamples[i + 1] = (tempSamples[i + 1] - My) / y_sDeviation;
	}
	return tempSamples;
}

double* initialize_random_weight(int size)
{
	double* W = new double[size];
	for (int i = 0; i < size; i++)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_real_distribution<double> dist(0.00, 1.00);
		W[i] = dist(mt);


	}
	return W;
}

double* update_weight_discrete(double* Weights, double* SamplesArray, int size, int where, int Output, double desired, double learningRate)
{
	for (int i = 0; i < size; i++)
	{
		Weights[i] = Weights[i] + learningRate * (desired - Output) * (SamplesArray[where + i]);
	}
	return Weights;
}

double sDerivative(double out) {
	double fnetDerivative; // the derivative of the sigmoid activation function

	fnetDerivative = 0.5 * (1 - (out * out));

	return fnetDerivative;
}

float perceptronTraining(float* Samples, float* Weights, float* targets, float* bias, int numSample, int inputDim) {
	int numNeuron = 1; // number of Neurons
	float err;
	float totalErr = 0;
	double net;
	//float maxErr = 0.0f;
	float c = 1.0; // learning constant
	float* output = new float[numNeuron];
	float* desired = new float[numNeuron];
	for (int i = 0; i < numSample; i++) {
		for (int n = 0; n < numNeuron; n++) {

			err = 0.0;
			net = 0.0;
			for (int j = 0; j < inputDim; j++) {
				net += Weights[j] * Samples[i * inputDim + j];
			}
			net += bias[n];

			output[n] = sign(net);

			// align 1 to class1 and -1 to class 2;
			if (targets[i] == 0)
				desired[n] = 1.0;
			else
				desired[n] = -1.0;
			err += abs(desired[n] - output[n]);
		}

		// update weights;
		for (int n = 0; n < numNeuron; n++) {
			for (int j = 0; j < inputDim; j++) {
				Weights[j] += c * (desired[n] - output[n]) * Samples[i * inputDim + j];
			}
			bias[n] += c * (desired[n] - output[n]);
		}
		totalErr += err;
		//textBox1->Text = "Total Error: " + totalErr + " w: " + Weights[0] + " b: " + bias[0];
	}
	return totalErr;

}

float deltaTraining(float* Samples, float* Weights, float* targets, float* bias, int numSample, int inputDim) {

	int K = 1; // number of Neurons
	float err;
	float totalErr = 0.0f;
	double net;
	double fnetprime;  // derivative of fnet
	float c = 0.5f; // learning constant
	float* output = new float[K];
	float* desired = new float[K];

	//normalizeData(Samples, numSample, inputDim);
	for (int i = 0; i < numSample; i++) {
		err = 0.0;
		for (int k = 0; k < K; k++) {
			net = 0.0;
			for (int j = 0; j < inputDim; j++) {
				net += Weights[j] * Samples[i * inputDim + j];
			}
			net += bias[k];

			output[k] = bipolar_continous_activation_fun(net);
			fnetprime = sDerivative(output[k]);

			// align 1 to class1 and -1 to class2
			if (targets[i] == 0)
				desired[k] = 1.0;
			else
				desired[k] = -1.0;
			err += 0.5 * pow((desired[k] - output[k]), 2);
		}

		// update weights;
		for (int k = 0; k < K; k++) {
			for (int j = 0; j < inputDim; j++) {
				Weights[j] += c * (desired[k] - output[k]) * fnetprime * Samples[i * inputDim + j];
			}
			bias[k] += c * (desired[k] - output[k]) * fnetprime;
		}
		totalErr += err;
	}
	return totalErr;
}

float multiPerceptronTraining(float* Samples, float* Weights, float* targets, float* bias, int numSample, int inputDim, int numClass) {
	int neuronCount = numClass; // the number of classes determines the number of neurons needed to train the perceptron
	float err;    // error generated by the neuron upon misclassification
	float totalErr = 0.0f;
	double* net = new double[neuronCount];  // response by the neuron
	float c = 0.5; // learning constant
	float* output = new float[neuronCount];
	float* desired = new float[neuronCount];


	for (int i = 0; i < numSample; i++) {
		err = 0.0;

		for (int n = 0; n < neuronCount; n++) {
			net[n] = 0;
		}
		for (int n = 0; n < neuronCount; n++) {


			for (int j = 0; j < inputDim; j++) {
				net[n] += Weights[2 * n + j] * Samples[i * inputDim + j];
			}
			net[n] += bias[n];

			output[n] = sign(net[n]);

			if (targets[i] == n)
				desired[n] = 1.0;
			else
				desired[n] = -1.0;
			err += abs(desired[n] - output[n]);
		}


		for (int n = 0; n < neuronCount; n++) {
			//if (desired[n] != output[n]) {  // update weights of neuron(s) whose outputs were different from the expected output

			for (int j = 0; j < inputDim; j++) {
				Weights[inputDim * n + j] += c * (desired[n] - output[n]) * Samples[i * inputDim + j];
				bias[n] += c * (desired[n] - output[n]);
			}

			//}
		}
		totalErr += err;
		for (int n = 0; n < neuronCount; n++) {
			net[n] = 0;
		}
	}
	return totalErr;
}

float multiDeltaTraining(float* Samples, float* Weights, float* targets, float* bias, int numSample, int inputDim, int numClass) {
	int K = numClass; // number of Neurons - each neuron represents one class
	float err;
	float totalErr = 0.0f;
	double* net = new double[K];
	double* fnetprime = new double[K];  // derivative of fnet
	float c = 0.5; // learning constant
	float* output = new float[K];
	float* desired = new float[K];


	for (int n = 0; n < K; n++) {
		net[n] = 0;
	}
	for (int s = 0; s < numSample; s++) {
		err = 0.0;
		for (int neuron = 0; neuron < K; neuron++) {
			for (int j = 0; j < inputDim; j++) {
				net[neuron] += Weights[2 * neuron + j] * Samples[s * inputDim + j];
			}
			net[neuron] += bias[neuron];

			output[neuron] = bipolar_continous_activation_fun(net[neuron]);
			fnetprime[neuron] = sDerivative(output[neuron]);

			if (targets[s] == neuron)
				desired[neuron] = 1.0;
			else
				desired[neuron] = -1.0;
			err += 0.5 * pow((desired[neuron] - output[neuron]), 2);
		}
		err = err / K; // determine average error produced

		// update weights;
		for (int k = 0; k < K; k++) {
			for (int j = 0; j < inputDim; j++) {
				Weights[2 * k + j] += c * (desired[k] - output[k]) * fnetprime[k] * Samples[s * inputDim + j];
			}
			bias[k] += c * (desired[k] - output[k]) * fnetprime[k];
		}
		totalErr += err;
		for (int n = 0; n < K; n++) {
			net[n] = 0;
		}
	}
	return totalErr;
}
