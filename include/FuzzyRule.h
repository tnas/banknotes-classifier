#ifndef FUZZYRULE_H
#define FUZZYRULE_H

#include <LinguisticConfiguration.h>

class FuzzyRule
{
    unsigned int numberOfVariables;
    LinguisticTerm* antecedents;
    Consequent consequent;

    public:
        FuzzyRule(unsigned int nvars, LinguisticTerm* terms, Consequent output);
        virtual ~FuzzyRule();
};

#endif // FUZZYRULE_H
