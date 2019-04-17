#ifndef FUZZYRULE_H
#define FUZZYRULE_H

#include <LinguisticConfiguration.h>
#include <FuzzyPartition.h>
#include <vector>
#include <algorithm>

using namespace std;

class FuzzyRule
{
    vector<FuzzyPartition> antecedents;
    Consequent consequent;
    double firingStrenght;

    public:
        FuzzyRule(vector<FuzzyPartition> antecedents, Consequent output);
        virtual ~FuzzyRule();
        bool isRedundant(FuzzyRule rule);
        bool isInconsistent(FuzzyRule rule);
        bool operator< (const FuzzyRule &other) const;
        bool operator> (const FuzzyRule &other) const;
        void show();
        vector<FuzzyPartition> getAntecedents();
        Consequent getConsequent();
        void setFiringStrenght(double inputs[Variable::length]);
        double getFiringStrenght();
};

#endif // FUZZYRULE_H
