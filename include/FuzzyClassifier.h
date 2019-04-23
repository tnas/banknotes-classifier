#ifndef FUZZYCLASSIFIER_H
#define FUZZYCLASSIFIER_H

#include <TrainingBasePreprocessor.h>
#include <WangMendelTrainer.h>

class FuzzyClassifier
{

    TrainingBasePreprocessor preProcessor;
    WangMendelTrainer wangTrainer;

    public:
        FuzzyClassifier();
        virtual ~FuzzyClassifier();
        void classify();
};

#endif // FUZZYCLASSIFIER_H
