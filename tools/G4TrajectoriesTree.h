#ifndef G4TrajectoriesTree_H_seen
#define G4TrajectoriesTree_H_seen
/// An include file to be used in ROOT macros. 
/// 
/// Define a global variable that will be filled with the G4Trajectories tree.
///

#include "AnalysisTreeBase.h"

#include "captDSTProjectHeaders.h"

#include <iostream>

/// The structure that will be attached to the branches of the G4Trajectories
/// tree.  This is filled by the TFile::GetEntry() methods.
class G4TrajectoriesTree : public AnalysisTreeBase {
public: 
    /// [TREE MEMBER] The branch containing the trajectories.  This is
    /// attached during setup.
    std::vector<CP::TG4TrajectoriesModule::TG4Trajectory> Trajectory;

    ///////////////////////////////////////////////
    // The methods are defined below this marker
    ///////////////////////////////////////////////

    G4TrajectoriesTree() : AnalysisTreeBase("TruthDir/G4Trajectories") {}
    virtual ~G4TrajectoriesTree();
    
    /// A method to attach the branches.  This must be used after the chain
    /// has been defined.
    virtual void Setup();

private:    
    /// The address of the tree member needed for reading the tree.
    std::vector<CP::TG4TrajectoriesModule::TG4Trajectory>* fTrajectoryAddr;
    
    ClassDef(G4TrajectoriesTree,0);
};

/// The global variable for the G4Trajectories tree.
extern G4TrajectoriesTree gG4Trajectories;

#endif
// Local Variables:
// mode:c++
// c-basic-offset:4
// End:
