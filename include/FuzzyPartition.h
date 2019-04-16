#ifndef FUZZYPARTITION_H
#define FUZZYPARTITION_H

#include <LinguisticConfiguration.h>

class FuzzyPartition
{
    LinguisticTerm linguisticTerm;
    double limInf;
    double limSup;
    double centralPoint;

    public:
        FuzzyPartition();
        FuzzyPartition(LinguisticTerm term, double inf, double sup, double central);
        virtual ~FuzzyPartition();
        double applyBelongingFunction(double val);
        LinguisticTerm getLinguisticTerm();
        void setLinguisticTerm(LinguisticTerm term);
        void updateCenterPoint();
        void updateLimits(double value);
        void display();
        double getInferiorLimit();
        double getSuperiorLimit();
        double getCentralPoint();
};

#endif // FUZZYPARTITION_H
