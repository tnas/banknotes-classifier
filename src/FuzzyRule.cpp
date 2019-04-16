#include "FuzzyRule.h"

FuzzyRule::FuzzyRule(unsigned int nvars, LinguisticTerm* terms, Consequent output)
{
    this->numberOfVariables = nvars;
    this->antecedents = new LinguisticTerm[nvars];
    this->consequent = output;
}

FuzzyRule::~FuzzyRule()
{
    delete(this->antecedents);
}
