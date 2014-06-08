#ifndef AnalysisTreeBase_H_seen
#define AnalysisTreeBase_H_seen

#include <string>
#include <TROOT.h>
#include <TChain.h>

class AnalysisTreeBase {
public:
    /// A pointer to the chain that is used for this tree.
    TChain* Chain;

    /// The name of the tree in the chain.
    std::string TreeName;

    /// [TREE MEMBER] The run number.
    int RunId;

    /// [TREE MEMBER] The subrun number
    int SubrunId;

    /// [TREE MEMBER] The event number
    int EventId;

    /// [TREE MEMBER] The flag that this event is preselected.
    int Preselected;

    ///////////////////////////////////////////////
    // The methods are defined below this marker
    ///////////////////////////////////////////////

    AnalysisTreeBase(const char* name);
    virtual ~AnalysisTreeBase();

    /// Add a file to the chain.
    virtual void AddFileList(const char* fileList);
     
    /// Add a file to the chain.
    virtual void AddFile(const char* file);
     
    /// A method to attach the branches.  This must be used after the chain
    /// has been defined.
    virtual void Setup();

    ClassDef(AnalysisTreeBase,0);
};

#endif
// Local Variables:
// mode:c++
// c-basic-offset:4
// End:
