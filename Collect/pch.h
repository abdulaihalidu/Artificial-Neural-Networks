// pch.h: Dies ist eine vorkompilierte Headerdatei.
// Die unten aufgeführten Dateien werden nur einmal kompiliert, um die Buildleistung für zukünftige Builds zu verbessern.
// Dies wirkt sich auch auf die IntelliSense-Leistung aus, Codevervollständigung und viele Features zum Durchsuchen von Code eingeschlossen.
// Die hier aufgeführten Dateien werden jedoch ALLE neu kompiliert, wenn mindestens eine davon zwischen den Builds aktualisiert wird.
// Fügen Sie hier keine Dateien hinzu, die häufig aktualisiert werden sollen, da sich so der Leistungsvorteil ins Gegenteil verkehrt.

#ifndef PCH_H
#define PCH_H

// Fügen Sie hier Header hinzu, die vorkompiliert werden sollen.

int sign(double net);
double* initialize_random_weight(int size);
double* update_weight_discrete(double* Weights, double* SamplesArray, int size, int where, int Output, double desired, double learningRate);
double sDerivative(double out);
double sDerivative(double out);

float* normalizeData(float* Weights, int numSample, int inputDim);

double bipolar_continous_activation_fun(double net);


float perceptronTraining(float* Samples, float* Weights, float* targets, float* bias, int numSample, int inputDim);
float deltaTraining(float* Samples, float* Weights, float* targets, float* bias, int numSample, int inputDim);
float multiPerceptronTraining(float* Samples, float* Weights, float* targets, float* bias, int numSample, int inputDim, int numClass);
float multiDeltaTraining(float* Samples, float* Weights, float* targets, float* bias, int numSample, int inputDim, int numClass);







#endif //PCH_H
