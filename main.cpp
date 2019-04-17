#include <TrainingBasePreprocessor.h>
#include <WangMendelTrainer.h>

using namespace std;

int main()
{
    string dataFile = "./data/bank-authentication-data.txt";

    TrainingBasePreprocessor preProcessor(dataFile, Variable::length);
    WangMendelTrainer wangTrainer(preProcessor);
    wangTrainer.generateCompleteRulesBase();
    wangTrainer.refineRulesBase();
    wangTrainer.displayRules();

    return 0;
}
