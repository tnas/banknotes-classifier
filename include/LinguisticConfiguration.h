#ifndef LINGUISTICTERM_H
#define LINGUISTICTERM_H

enum Variable
{
    variance,
    skewness,
    curtosis,
    entropy,
    length
};

enum LinguisticTerm
{
    highVariance, lowVariance,
    highSkewness, lowSkewness,
    highCurtosis, lowCurtosis,
    highEntropy, lowEntropy
};

enum Consequent
{
    authentic, falsified
};

#endif // LINGUISTICTERM_H
