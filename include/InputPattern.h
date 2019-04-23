#ifndef INPUTPATTERN_H
#define INPUTPATTERN_H


class InputPattern
{
    double variance;
    double skewness;
    double curtosis;
    double entropy;
    int output;

    public:
        InputPattern();
        InputPattern(double var, double ske, double cur, double ent, int out);
        virtual ~InputPattern();
        double getVariance();
        double getSkewness();
        double getCurtosis();
        double getEntropy();
        void loadAntecedents(double* antecedents);
        int getOutput();
        void setVariance(double value);
        void setSkewness(double value);
        void setCurtosis(double value);
        void setEntropy(double value);
        void setOutput(int value);
        void show();
};

#endif // INPUTPATTERN_H
