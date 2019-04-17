#include "FuzzyRule.h"
#include <iostream>
#include <cstdlib>
#include <limits>

FuzzyRule::FuzzyRule(vector<FuzzyPartition> input, Consequent output)
{
    this->antecedents = input;
    this->consequent  = output;
}

FuzzyRule::~FuzzyRule()
{
}

bool FuzzyRule::isRedundant(FuzzyRule rule)
{
    for (int var = Variable::variance; var < Variable::length; ++var)
    {
        if (this->antecedents.at(var).getLinguisticTerm() != rule.getAntecedents().at(var).getLinguisticTerm())
            return false;
    }

    return true;
}

bool FuzzyRule::isInconsistent(FuzzyRule rule)
{
    return this->isRedundant(rule) && this->getConsequent() != rule.getConsequent();
}

void FuzzyRule::show()
{
    for (FuzzyPartition fPartition : this->antecedents)
    {
            fPartition.display();
    }

    cout << "Firing Strenght: " << this->firingStrenght << endl;
    cout << "--------------------------" << endl;
}

bool FuzzyRule::operator<(const FuzzyRule& other) const
{
    return this->firingStrenght < other.firingStrenght;
}

bool FuzzyRule::operator>(const FuzzyRule& other) const
{
    return this->firingStrenght > other.firingStrenght;
}

vector<FuzzyPartition> FuzzyRule::getAntecedents()
{
    return this->antecedents;
}

Consequent FuzzyRule::getConsequent()
{
    return this->consequent;
}

void FuzzyRule::setFiringStrenght(double inputs[Variable::length])
{
    double minNormValue = numeric_limits<double>::max();

    // t-minimal norm
    for (int var = Variable::variance; var < Variable::length; ++var)
    {
        double normValue = abs(this->antecedents.at(var).applyBelongingFunction(inputs[var]));
        if (normValue < minNormValue)
            minNormValue = normValue;
    }

    this->firingStrenght = minNormValue;
}

double FuzzyRule::getFiringStrenght()
{
    return this->firingStrenght;
}


