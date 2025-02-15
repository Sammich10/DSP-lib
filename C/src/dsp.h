/*************  ✨ DSP Algorithm Library 🌟  *************/
/**
 * \file dsp.h
 * \brief Digital signal processing functions
 */

#ifndef DSP_H
#define DSP_H

#include <stdint.h>
#include <vector>
#include <math.h>

/**
 * \brief Compute signal mean
 * 
 * @param sig Signal
 * @param len Signal length
 * 
 * @return Signal mean
 */
template <typename T>
double calcSigMean
(
    const std::vector<T> &sig
)
{
    // Get signal length
    size_t len = sig.size();
    // Initialize signal mean variable
    double sum = 0.0;
    // Compute signal mean by adding each value
    for(size_t i = 0; i < len; i++)
    {
        sum += sig[i];
    }
    // Return signal mean by dividing the sum by the signal length
    return sum / (double)len;
}


/**
 * \brief Compute signal variance
 * 
 * @param sig Signal
 * @param mean Signal mean
 * @param len Signal length
 * 
 * @return Signal variance
 */
template <typename T>
double calcSigVar
(
    const std::vector<T> &sig
)
{
    // Get signal length
    size_t len = sig.size();
    // Get signal mean
    double mean = calcSigMean(sig);
    // Initialize signal variance variable
    double var = 0.0;
    // Compute signal variance by squaring the difference between each value and the mean
    for(size_t i = 0; i < len; i++)
    {
        var += (sig[i] - mean) * (sig[i] - mean);
    }
    // Return signal variance
    return var / (double)(len-1);
}


/**
 * \brief Compute signal standard deviation
 * 
 * @param var Signal variance
 * 
 * @return Signal standard deviation
 */
template <typename T>
double calcSigStd
(
    const std::vector<T> &sig
)
{
    // Return signal standard deviation by taking the square root of the signal variance
    return std::sqrt(calcSigVar(sig));
}

/**
 * \brief Do a full convolution of signal with kernel
 * 
 * @param sig Signal
 * @param kernel Kernel
 *  
 * @return Convolved signal
 */
template <typename T>
std::vector<T> convolveFull
(
    const std::vector<T> &sig,
    const std::vector<T> &kernel
)
{
    std::vector<T> convolvedSig(sig.size() + kernel.size() - 1);

    for(size_t i = 0; i < sig.size(); i++)
    {
        for(size_t j = 0; j < kernel.size(); j++)
        {
            convolvedSig[i+j] += sig[i] * kernel[j];
        }
    }

    return convolvedSig;
}

/**
 * \brief Do a same convolution of signal with kernel
 * 
 * @param sig Signal
 * @param kernel Kernel
 *  
 * @return Convolved signal
 */
template <typename T>
std::vector<T> convolveSame
(
    const std::vector<T> &sig,
    const std::vector<T> &kernel
)
{
    std::vector<T> convolvedSig(sig.size());

    for(size_t i = 0; i < sig.size(); i++)
    {
        for(size_t j = 0; j < kernel.size(); j++)
        {
            convolvedSig[i] += sig[i-j] * kernel[j];
        }
    }

    return convolvedSig;
}

template <typename T>
std::vector<T> calcRunningSum
(
    const std::vector<T> &sig
)
{
    std::vector<T> runningSum(sig.size());
    runningSum[0] = sig[0];
    for(size_t i = 1; i < sig.size(); i++)
    {
        runningSum[i] = runningSum[i-1] + sig[i];
    }

    return runningSum;
}


#endif