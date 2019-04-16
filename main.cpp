#include <iostream>
#include <TrainingBasePreprocessor.h>
#include <WangMendelTrainer.h>

using namespace std;

int main()
{
    string dataFile = "./data/bank-authentication-data.txt";

    TrainingBasePreprocessor preProcessor(dataFile, Variable::length);
    preProcessor.run();
    preProcessor.display();

    WangMendelTrainer wmTrainer(preProcessor);


    return 0;
}
