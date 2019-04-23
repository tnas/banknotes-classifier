#include "InputPattern.h"
#include <LinguisticConfiguration.h>
#include <iostream>

using namespace std;

InputPattern::InputPattern()
{
}

InputPattern::~InputPattern()
{
}

InputPattern::InputPattern(double var, double ske, double cur, double ent, int out)
{
    this->variance = var;
    this->skewness = ske;
    this->curtosis = cur;
    this->entropy  = ent;
    this->output   = out;
}

double InputPattern::getVariance()
{
    return this->variance;
}

double InputPattern::getSkewness()
{
    return this->skewness;
}

double InputPattern::getCurtosis()
{
    return this->curtosis;
}

double InputPattern::getEntropy()
{
    return this->entropy;
}

void InputPattern::loadAntecedents(double* antecedents)
{
    antecedents[Variable::variance] = this->variance;
    antecedents[Variable::skewness] = this->skewness;
    antecedents[Variable::curtosis] = this->curtosis;
    antecedents[Variable::entropy] = this->entropy;
}


int InputPattern::getOutput()
{
    return this->output;
}

void InputPattern::setVariance(double value)
{
    this->variance = value;
}

void InputPattern::setSkewness(double value)
{
    this->skewness = value;
}

void InputPattern::setCurtosis(double value)
{
    this->curtosis = value;
}

void InputPattern::setEntropy(double value)
{
    this->entropy = value;
}

void InputPattern::setOutput(int value)
{
    this->output = value;
}

void InputPattern::show()
{
    cout << "[" <<
        this->variance << ", " <<
        this->skewness << ", " <<
        this->curtosis << ", " <<
        this->entropy << ", " <<
        "] -> " << this->output << endl;
}

