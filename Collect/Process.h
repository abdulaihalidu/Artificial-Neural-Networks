#pragma once
float* Add_Data(float* sample, int Size, float* x, int Dim);
float* Add_Labels(float* Labels, int Size, int label);
float* init_array_random(int len);
int YPoint(int x, float w[], float bias, float Carpan = 1.0);