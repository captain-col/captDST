#include "AnalysisTreeBase.h"

#include <fstream>
#include <string>

AnalysisTreeBase::AnalysisTreeBase(const char* name) :
    Chain(NULL), TreeName(name) {}

AnalysisTreeBase::~AnalysisTreeBase() {}

void AnalysisTreeBase::AddFileList(const char* fileList) {
    ifstream in(fileList);
    if (!in || in.bad()) {
        std::cout << "missing input file" << std::endl;
        return;
    }
    
    std::string file;
    while (true) {
        in >> file;
        if (in.fail()) break;
        if (file.find(".root") == std::string::npos) continue;
        AddFile(file.c_str());
    }
    in.close();
}

void AnalysisTreeBase::AddFile(const char* file) {
    if (!Chain) {
        Chain = new TChain(TreeName.c_str());
    }
    Chain->Add(file);
}

void AnalysisTreeBase::Setup() {
    Chain->SetBranchAddress("RunId",
                            &RunId);
    Chain->SetBranchAddress("SubrunId",
                            &SubrunId);
    Chain->SetBranchAddress("EventId",
                            &EventId);
    Chain->SetBranchAddress("Preselected",
                            &Preselected);
}


