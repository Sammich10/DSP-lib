#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SAMPLES 320

extern double InputSignal_f32_1kHz_15kHz[SAMPLES];

double calcSigMean(double *sig, int len);
double calcSigVar(double *sig, double mean, int len);
double calcSigStd(double var);

int main() {
    double sigMean = calcSigMean(InputSignal_f32_1kHz_15kHz, SAMPLES);

    double variance = calcSigVar(InputSignal_f32_1kHz_15kHz, sigMean, SAMPLES);

    double sigStd = calcSigStd(variance);

    printf("Signal mean: %f\n", sigMean);

    printf("Signal variance: %f\n", variance);

    printf("Signal standard deviation: %f\n", sigStd);

    return 0;
}

// Compute signal mean
double calcSigMean(double *sig, int len)
{
    double sum = 0.0;
    for(int i = 0; i < len; i++)
    {
        sum += sig[i];
    }

    return sum / (double)len;
}

// Compute signal variance
double calcSigVar(double *sig, double mean, int len)
{
    double var = 0.0;
    for(int i = 0; i < len; i++)
    {
        var += (sig[i] - mean) * (sig[i] - mean);
    }

    return var / (double)(len-1);
}

double calcSigStd(double var)
{
    return sqrt(var);
}