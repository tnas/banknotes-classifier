#ifndef WANGMENDELTRAINER_H
#define WANGMENDELTRAINER_H

#include <string>
#include <vector>
#include <FuzzyRule.h>
#include <TrainingBasePreprocessor.h>

using namespace std;

class WangMendelTrainer
{
    TrainingBasePreprocessor preProcessor;

    public:
        WangMendelTrainer(TrainingBasePreprocessor preProcessor);
        virtual ~WangMendelTrainer();
        vector<FuzzyRule> execute();
};

#endif // WANGMENDELTRAINER_H
