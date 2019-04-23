#include "FuzzyClassifier.h"
#include <string>
#include <vector>
#include <limits>
#include <iostream>
#include <LinguisticConfiguration.h>
#include <InputPattern.h>

using namespace std;

static string defaultDataFile = "./data/bank-authentication-data.txt";

FuzzyClassifier::FuzzyClassifier()
{
    this->preProcessor = TrainingBasePreprocessor(defaultDataFile, Variable::length);
    this->wangTrainer  = WangMendelTrainer(preProcessor);
}

FuzzyClassifier::~FuzzyClassifier()
{
}

void FuzzyClassifier::classify()
{
    this->wangTrainer.generateCompleteRulesBase();
    this->wangTrainer.refineRulesBase();
    //this->wangTrainer.displayRules();
    vector<FuzzyRule> rulesBase = this->wangTrainer.getFuzzyRules();
    vector<InputPattern> trainingBase = this->preProcessor.getTrainingPattern();
    double maxFiringStrength;
    int obtainedOutput, success, fail;
    success = fail = 0;

    for (InputPattern input : trainingBase)
    {
        maxFiringStrength = numeric_limits<double>::min();

        for (FuzzyRule rule : rulesBase)
        {
            double antecedents[Variable::length];
            input.loadAntecedents(antecedents);
            rule.setFiringStrenght(antecedents);

            if (rule.getFiringStrenght() > maxFiringStrength)
            {
                maxFiringStrength = rule.getFiringStrenght();
                obtainedOutput = rule.getConsequent();
            }
        }

        input.show();

        if (obtainedOutput == input.getOutput()) ++success;
        else ++fail;
    }

    cout << "Total of successes: " << success << endl;
    cout << "Total of fails: " << fail << endl;
}


