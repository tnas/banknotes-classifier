#include "WangMendelTrainer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <FuzzyPartition.h>

WangMendelTrainer::WangMendelTrainer(TrainingBasePreprocessor preProcessor)
{
    this->preProcessor = preProcessor;
}

WangMendelTrainer::~WangMendelTrainer()
{
}

FuzzyPartition getHighestDegreePartition(vector<FuzzyPartition> partitions, double input)
{
    double maxBelongingRate = 0;
    FuzzyPartition bestPartition = partitions.front();

    for (FuzzyPartition fPartition : partitions)
    {
        double belongingRate = fPartition.applyBelongingFunction(input);
        if (belongingRate > maxBelongingRate)
        {
            maxBelongingRate = belongingRate;
            bestPartition    = fPartition;
        }
    }

    return bestPartition;
}

void WangMendelTrainer::generateCompleteRulesBase()
{
    vector<FuzzyRule> completeFuzzyRules;

    this->preProcessor.scanTrainingBase();
    map<Variable, vector<FuzzyPartition>> spacePartition = this->preProcessor.createSpacePartition();
    this->preProcessor.display();

    // TODO: remove duplicated code related to tokenizing data file
    ifstream dataFile(this->preProcessor.getBaseFileName());
    string line;

    if (dataFile.is_open())
    {
        while (getline(dataFile, line))
        {
            stringstream ssin(line);
            unsigned int rSize = 0;
            string token;
            double inputs[Variable::length + 1];

            while (getline(ssin, token, ','))
                inputs[rSize++] = stod(token);

            vector<FuzzyPartition> antecedents;
            for (int var = Variable::variance; var < Variable::length; ++var)
            {
                FuzzyPartition varPartition = getHighestDegreePartition(
                    spacePartition.at(static_cast<Variable>(var)), inputs[var]);

                antecedents.push_back(varPartition);
            }

            FuzzyRule rule = FuzzyRule(antecedents, static_cast<Consequent>(inputs[Variable::length]));
            rule.setFiringStrenght(inputs);
            this->fuzzyRules.push_back(rule);
        }
    }

    dataFile.close();
}

void WangMendelTrainer::refineRulesBase()
{
    sort(this->fuzzyRules.begin(), this->fuzzyRules.end(), greater<FuzzyRule>());

    vector<FuzzyRule> refinedFuzzyRules;

    for (FuzzyRule originalRule : this->fuzzyRules)
    {
        bool isRedundant = false;

        for (FuzzyRule refinedRule : refinedFuzzyRules)
        {
            if (originalRule.isRedundant(refinedRule))
            {
                isRedundant = true;
                break;
            }
        }

        if (!isRedundant) refinedFuzzyRules.push_back(originalRule);
    }

    this->fuzzyRules.clear();
    this->fuzzyRules = refinedFuzzyRules;
}

vector<FuzzyRule> WangMendelTrainer::getFuzzyRules()
{
    return this->fuzzyRules;
}

void WangMendelTrainer::displayRules()
{
    for (FuzzyRule rule : this->fuzzyRules)
        rule.show();
    cout << "Number of Rules: " << this->fuzzyRules.size() << endl;
}


