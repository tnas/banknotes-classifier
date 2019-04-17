#include "TrainingBasePreprocessor.h"
#include <iostream>
#include <fstream>
#include <sstream>

static FuzzyPartition macroPartitions[Variable::length];

TrainingBasePreprocessor::TrainingBasePreprocessor()
{

}

TrainingBasePreprocessor::TrainingBasePreprocessor(string baseFile, unsigned int numberOfVars)
{
    this->fileName = baseFile;
    this->numberOfVariables = numberOfVars;
    this->numberOfAuthentics = this->numberOfFalsifieds =
    this->numberOfRegisters = this->trainingAuthentics =
    this->trainingFalsifieds = 0;
}

TrainingBasePreprocessor::~TrainingBasePreprocessor()
{
}

void TrainingBasePreprocessor::scanTrainingBase()
{
    ifstream dataFile(this->fileName);
    string line;

    if (dataFile.is_open())
    {
        while (getline(dataFile, line))
        {
            stringstream ssin(line);
            unsigned int rSize = 0;
            string token;
            string tokens[Variable::length + 1];

            while (getline(ssin, token, ','))
                tokens[rSize++] = token;

            for (int var = Variable::variance; var < Variable::length; ++var)
                macroPartitions[var].updateLimits(stod(tokens[var]));

            if (stoi(tokens[Variable::length]) == Consequent::authentic)
                ++this->numberOfAuthentics;
            else if (stoi(tokens[Variable::length]) == Consequent::falsified)
                ++this->numberOfFalsifieds;

            ++this->numberOfRegisters;
        }
    }

    dataFile.close();
}

map<Variable, vector<FuzzyPartition>> TrainingBasePreprocessor::createSpacePartition()
{
    map<Variable, vector<FuzzyPartition>> fuzzyPartitions;

    int linguisticTerm = -1;
    for (int var = Variable::variance; var < Variable::length; ++var)
    {
        vector<FuzzyPartition> variablePartitions;

        LinguisticTerm highTerm = static_cast<LinguisticTerm>(++linguisticTerm);
        FuzzyPartition firstPartition(highTerm, macroPartitions[var].getInferiorLimit(),
                macroPartitions[var].getSuperiorLimit(), macroPartitions[var].getCentralPoint());
        variablePartitions.push_back(firstPartition);

        LinguisticTerm lowTerm = static_cast<LinguisticTerm>(++linguisticTerm);
        FuzzyPartition secondPartition(lowTerm, macroPartitions[var].getInferiorLimit(),
                macroPartitions[var].getCentralPoint(), macroPartitions[var].getInferiorLimit());
        variablePartitions.push_back(secondPartition);

        fuzzyPartitions.insert(
            pair<Variable, vector<FuzzyPartition>>(static_cast<Variable>(var), variablePartitions));
    }

    return fuzzyPartitions;
}


string TrainingBasePreprocessor::getBaseFileName()
{
    return this->fileName;
}

unsigned int TrainingBasePreprocessor::getNumberOfRegisters()
{
    return this->numberOfRegisters;
}

unsigned int TrainingBasePreprocessor::getNumberOfAuthentics()
{
    return this->numberOfAuthentics;
}

unsigned int TrainingBasePreprocessor::getNumberOfFalsifieds()
{
    return this->numberOfFalsifieds;
}

unsigned int TrainingBasePreprocessor::getTrainingAuthentics()
{
    return this->trainingAuthentics;
}

unsigned int TrainingBasePreprocessor::getTrainingFalsifieds()
{
    return this->trainingFalsifieds;
}

void TrainingBasePreprocessor::display()
{
    cout << "Number of registers: " << this->numberOfRegisters << endl;
    cout << "Number of authentics: " << this->numberOfAuthentics << endl;
    cout << "Number of falsifieds: " << this->numberOfFalsifieds << endl;
    cout << "Number of training authentics: " << this->trainingAuthentics << endl;
    cout << "Number of training falsifieds: " << this->trainingFalsifieds << endl;
}
