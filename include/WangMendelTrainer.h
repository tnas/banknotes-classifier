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
    vector<FuzzyRule> fuzzyRules;

    public:
        WangMendelTrainer(TrainingBasePreprocessor preProcessor);
        virtual ~WangMendelTrainer();
        void generateCompleteRulesBase();
        void refineRulesBase();
        vector<FuzzyRule> getFuzzyRules();
        void displayRules();
};

#endif // WANGMENDELTRAINER_H
