#include "FuzzyPartition.h"
#include <limits>
#include <iostream>

using namespace std;

FuzzyPartition::FuzzyPartition()
{
    this->limInf = numeric_limits<double>::max();
    this->limSup = numeric_limits<double>::min();
    this->updateCenterPoint();
}

FuzzyPartition::FuzzyPartition(LinguisticTerm term, double inf, double sup, double central)
{
    this->limInf = inf;
    this->limSup = sup;
    this->centralPoint = central;
    this->linguisticTerm = term;
}

FuzzyPartition::~FuzzyPartition()
{
}


double FuzzyPartition::applyBelongingFunction(double val)
{
    if (val <= this->limInf || val > this->limSup)
    {
        return 0;
    }
    else if (val > this->limInf && val <= this->centralPoint)
    {
        return (val - this->limInf) / (this->centralPoint - this->limInf);
    }
    else if (val > this->centralPoint && val <= this->limSup)
    {
        return (this->limSup - val) / (this->limSup - this->centralPoint);
    }
    else // val == this->centerPoint
    {
        return 1;
    }
}

LinguisticTerm FuzzyPartition::getLinguisticTerm()
{
    return this->linguisticTerm;
}

void FuzzyPartition::setLinguisticTerm(LinguisticTerm term)
{
    this->linguisticTerm = term;
}

void FuzzyPartition::updateCenterPoint()
{
    this->centralPoint = (this->limSup + this->limInf) / 2;
}

void FuzzyPartition::updateLimits(double value)
{
    if (value < this->limInf) this->limInf = value;
    if (value > this->limSup) this->limSup = value;
    this->updateCenterPoint();
}

void FuzzyPartition::display()
{
    cout << "Linguistic term: " << this->linguisticTerm << endl;
    cout << "Inferior limit: " << this->limInf << endl;
    cout << "Center Point: " << this->centralPoint << endl;
    cout << "Superior limit: " << this->limSup << endl;
}

double FuzzyPartition::getInferiorLimit()
{
    return this->limInf;
}

double FuzzyPartition::getSuperiorLimit()
{
    return this->limSup;
}

double FuzzyPartition::getCentralPoint()
{
    return this->centralPoint;
}
