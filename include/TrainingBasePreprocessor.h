#ifndef TRAININGBASEPREPROCESSOR_H
#define TRAININGBASEPREPROCESSOR_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <LinguisticConfiguration.h>
#include <FuzzyPartition.h>

#define TRAINING_PERCENTAGE 0.8

using namespace std;

class TrainingBasePreprocessor
{
    string fileName;
    unsigned int numberOfVariables;
    unsigned int numberOfRegisters;
    unsigned int numberOfAuthentics;
    unsigned int numberOfFalsifieds;
    unsigned int trainingAuthentics;
    unsigned int trainingFalsifieds;

    public:
        TrainingBasePreprocessor();
        TrainingBasePreprocessor(string baseFile, unsigned int numberOfVars);
        virtual ~TrainingBasePreprocessor();
        void scanTrainingBase();
        map<Variable, vector<FuzzyPartition>> createSpacePartition();
        string getBaseFileName();
        unsigned int getNumberOfRegisters();
        unsigned int getNumberOfAuthentics();
        unsigned int getNumberOfFalsifieds();
        unsigned int getTrainingAuthentics();
        unsigned int getTrainingFalsifieds();
        void display();
};

#endif // TRAININGBASEPREPROCESSOR_H
