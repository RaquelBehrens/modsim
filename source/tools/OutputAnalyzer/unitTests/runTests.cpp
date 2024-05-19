#include <cassert>
#include "../OutputAnalyser.h"
#include "test.h"

using namespace std;

int totalErrors;
int size;
Statistics* ss;
HypothesisTester_if* tester;
CollectorOutputAnalyser* collector;
Fitter_if* fitter;

void ss_min() {
    totalErrors += TEST_EQUAL_FP(ss->min(), 25.51, "Mínimo");
}

void ss_max() {
    totalErrors += TEST_EQUAL_FP(ss->max(),  74.94, "Máximo");
}

void ss_average() {
    totalErrors += TEST_EQUAL_FP(ss->average(), 50.4078, "Média");
}

void ss_variance() {
    totalErrors += TEST_EQUAL_FP(ss->variance(), 87.7589, "Variância");
}

void ss_stddeviation() {
    totalErrors += TEST_EQUAL_FP(ss->stddeviation(), 9.3679, "Desvio padrão");
}

void ss_variationCoef() {
    totalErrors += TEST_EQUAL_FP(ss->variationCoef(), 0.1858, "Coeficiente de variância");
}

void ss_mode() {
    totalErrors += TEST_EQUAL_FP(ss->mode(), 40.07, "Moda");
}

void ss_mediane() {
    totalErrors += TEST_EQUAL_FP(ss->mediane(), 50.73, "Mediana");
}

void ss_quartil() {
    totalErrors += TEST_EQUAL_FP(ss->quartil(1), 43.58, "Quartil Q1");
    totalErrors += TEST_EQUAL_FP(ss->quartil(2), 50.67, "Quartil Q2");
    totalErrors += TEST_EQUAL_FP(ss->quartil(3), 56.13, "Quartil Q3");
}

void ss_averageInterval() {
    auto avgInterval = tester->averageConfidenceInterval(ss->average(), ss->stddeviation(), collector->numElements(), 0.95);
    totalErrors += TEST_EQUAL_FP(avgInterval.inferiorLimit(), 49.1015, "Intervalo de confiança da média: limite inferior");
    totalErrors += TEST_EQUAL_FP(avgInterval.superiorLimit(), 51.7141, "Intervalo de confiança da média: limite superior");
}

void ss_varianceInterval() {
    auto varInterval = tester->varianceConfidenceInterval(ss->variance(), collector->numElements(), 0.95);
    totalErrors += TEST_EQUAL_FP(varInterval.inferiorLimit(), 72.7790, "Intervalo de confiança da variância: limite inferior");
    totalErrors += TEST_EQUAL_FP(varInterval.superiorLimit(), 107.9184, "Intervalo de confiança da variância: limite superior");
}

void ss_proportionInterval() {
    auto propInterval = tester->proportionConfidenceInterval(0.6, collector->numElements(), 0.95);
    totalErrors += TEST_EQUAL_FP(propInterval.inferiorLimit(), 0.5316, "Intervalo de confiança da proporção: limite inferior");
    totalErrors += TEST_EQUAL_FP(propInterval.superiorLimit(), 0.6683, "Intervalo de confiança da proporção: limite superior");
}

void ss_averageDifferenceConfidenceInterval() {
    // Valores iguais aos utilizados nos testes dos trabalhos disponibilizados.
    auto ci = tester->averageDifferenceConfidenceInterval(-50.0, 5, 30, -55, 5.5, 60, 0.95);
    totalErrors += TEST_EQUAL_FP(ci.inferiorLimit(), 2.6268777282956, "Intervalo de confiança da diferença da média: limite inferior");
    totalErrors += TEST_EQUAL_FP(ci.superiorLimit(), 7.3731222717044, "Intervalo de confiança da diferença da média: limite superior");

    ci = tester->averageDifferenceConfidenceInterval(-150.0, 15, 80, -180, 30, 65, 0.80);
    totalErrors += TEST_EQUAL_FP(ci.inferiorLimit(), 24.7315108021291, "Intervalo de confiança da diferença da média: limite inferior");
    totalErrors += TEST_EQUAL_FP(ci.superiorLimit(), 35.2684891978709, "Intervalo de confiança da diferença da média: limite superior");
}

// void ss_varianceRatioConfidenceInterval() {
//     // Valores iguais aos utilizados nos testes dos trabalhos disponibilizados.
//     auto ci = tester->varianceRatioConfidenceInterval(46.5, 8, 23.4, 17, 0.90);
//     totalErrors += TEST_EQUAL_FP(ci.inferiorLimit(), 0.747848121969653, "Variance Ratio: limite inferior");
//     totalErrors += TEST_EQUAL_FP(ci.superiorLimit(), 6.94401607090069, "Variance Ratio: limite superior");
// }

void fitUniform(Fitter_if * fitter) {
    cout << "-------------- FIT UNIFORM --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double min;
    double max;
    unsigned int k = 10;
    fitter->fitUniform(k, &chi2Result, &ksResult, &min, &max); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 7.11777192741181E-10, "p-value");
    // totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 63.72, "estatística de teste");
    // totalErrors += TEST_EQUAL_FP(chi2Result.acceptanceInferiorLimit(), 0.0, "limite inferior da região de aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(chi2Result.acceptanceSuperiorLimit(), 18.3070380532751, "limite superior da região de aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(min, 92.2428, "parâmetro 'min' da distribuição");
    // totalErrors += TEST_EQUAL_FP(max, 170.322, "parâmetro 'max' da distribuição");
}

void fitNormal(Fitter_if * fitter) {
    cout << "-------------- FIT NORMAL --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double avg;
    double stddev;
    unsigned int k = 8;
    fitter->fitNormal(k, &chi2Result, &ksResult, &avg, &stddev); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 7.11777192741181E-10, "p-value");
    // totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 63.72, "estatística de teste");
    // totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.0688, "estatistica de teste");
    // totalErrors += TEST_EQUAL_FP(avg, 130, "parâmetro 'avg' da distribuição");
    // totalErrors += TEST_EQUAL_FP(stddev, 16.4, "parâmetro 'stddev' da distribuição");
}

void fitExpo(Fitter_if * fitter) {
    cout << "-------------- FIT EXPO --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double avg;
    unsigned int k = 8;
    fitter->fitExpo(k, &chi2Result, &ksResult, &avg); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 7.11777192741181E-10, "p-value");
    // totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 63.72, "estatística de teste");
    // totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.0688, "estatistica de teste");
    // totalErrors += TEST_EQUAL_FP(avg, 130, "parâmetro 'avg' da distribuição");
}

void fitErlang(Fitter_if * fitter) {
    cout << "-------------- FIT ERLANG --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double avg;
    double m;
    unsigned int k = 8;
    fitter->fitErlang(k, &chi2Result, &ksResult, &avg, &m); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 7.11777192741181E-10, "p-value");
    // totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 63.72, "estatística de teste");
    // totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.0688, "estatistica de teste");
    // totalErrors += TEST_EQUAL_FP(avg, 130, "parâmetro 'avg' da distribuição");
}

void fitBeta(Fitter_if * fitter) {
    cout << "-------------- FIT BETA --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double alpha;
    double beta;
    double infLim;
    double supLim;
    unsigned int k = 8;
    fitter->fitBeta(k, &chi2Result, &ksResult, &alpha, &beta, &infLim, &supLim); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 7.11777192741181E-10, "p-value");
    // totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 63.72, "estatística de teste");
    // totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.0688, "estatistica de teste");
    // totalErrors += TEST_EQUAL_FP(alpha, 2.31, "parâmetro 'alpha' da distribuição");
    // totalErrors += TEST_EQUAL_FP(beta, 2.48, "parâmetro 'beta' da distribuição");
}

void fitWeibull(Fitter_if * fitter) {
    cout << "-------------- FIT WEIBULL --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    double alpha;
    double scale;
    unsigned int k = 8;
    fitter->fitWeibull(k, &chi2Result, &ksResult, &alpha, &scale); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 7.11777192741181E-10, "p-value");
    // totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 63.72, "estatística de teste");
    // totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.0688, "estatistica de teste");
}

void fitAll(Fitter_if * fitter) {
    cout << "-------------- FIT ALL --------------" << endl;
    HypothesisTester_if::TestResult chi2Result;
    HypothesisTester_if::TestResult ksResult;
    unsigned int k = 8;
    string name;
    fitter->fitAll(k, &chi2Result, &ksResult, &name); 
    totalErrors += TEST_EQUAL_FP(chi2Result.acceptH0(), true, "Aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(chi2Result.pValue(), 7.11777192741181E-10, "p-value");
    // totalErrors += TEST_EQUAL_FP(chi2Result.testStat(), 63.72, "estatística de teste");
    // totalErrors += TEST_EQUAL_FP(ksResult.acceptH0(), true, "Aceitação de H0");
    // totalErrors += TEST_EQUAL_FP(ksResult.testStat(), 0.0688, "estatistica de teste");
}

// int runCorrelogramTest() {
//     OutputAnalyser outputAnalyser("unitTests/correlogramtestData.txt");
//     outputAnalyser.setReplication(1);
//     //Teste autocorrelograma de todos os dados
//     std::vector<double> autocorrelogram = {1, 0.131643, -0.193991, -0.519624, -0.193991, 0.131643, 0.565822, 0.131643, -0.193991}; 
//     Correlogram correlogram = outputAnalyser.getCorrelogram(0,-1);
//     std::vector<double> result = correlogram.getAutoCorrelation();
//     for (size_t i=0;i<autocorrelogram.size();i++)
//     {
        
//         assert((autocorrelogram[i] - result[i] ) < 1e-5 );
//     }

//     //Teste autocorrelograma de um intervalo dos dados
//     autocorrelogram = {0.82821, 0.556962, 0.15009, 0.15009};
//     correlogram = outputAnalyser.getCorrelogram(5,12);
//     result = correlogram.getAutoCorrelation();
//     for (size_t i=0;i<autocorrelogram.size();i++)
//     {
        
//         assert((autocorrelogram[i] - result[i] ) < 1e-5 );
//     }
//     return 0;
// }

int runFitterTest() {
    auto outputAnalyser = OutputAnalyser("../Files/UniformDist.txt");
    outputAnalyser.setReplication(1);
    fitter = outputAnalyser.fitter();

    fitUniform(fitter);

    outputAnalyser.loadDataSet("../Files/NormalDist.txt");
    fitNormal(fitter);

    outputAnalyser.loadDataSet("../Files/ExpoDist.txt");
    fitExpo(fitter);

    outputAnalyser.loadDataSet("../Files/ErlangDist.txt");
    fitErlang(fitter);

    outputAnalyser.loadDataSet("../Files/BetaDist.txt");
    fitBeta(fitter);

    outputAnalyser.loadDataSet("../Files/WeibullDist.txt");
    fitWeibull(fitter);

    outputAnalyser.loadDataSet("../Files/ExpoDist.txt");
    fitAll(fitter);

}

int runStatisticsTest() {
    ss_min();
    ss_max();
    ss_average();
    ss_variance();
    ss_stddeviation();
    ss_variationCoef();
    ss_mode();
    ss_mediane();
    ss_quartil();
    ss_averageInterval();
    ss_varianceInterval();
    ss_proportionInterval();
    ss_averageDifferenceConfidenceInterval();
    // ss_varianceRatioConfidenceInterval();

    return 0;
}

int main() {
    auto outputAnalyser = OutputAnalyser("../Files/normalDist_genesys");
    outputAnalyser.setReplication(1);

    ss = outputAnalyser.statisticsDataFile();
    tester = outputAnalyser.tester();
    collector = outputAnalyser.collector();

    runStatisticsTest();
    runFitterTest(); // Apenas as distribuições foram geradas, parâmetros não foram configurados
    // runCorrelogramTest();

    if (totalErrors == 0)
        cout << "Succesfully runned all unit tests" << endl;
    else
        cout << "Total errors: " << totalErrors << endl;
    return 0;
}
