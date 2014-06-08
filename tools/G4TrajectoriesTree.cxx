#include "G4TrajectoriesTree.h"

G4TrajectoriesTree gG4Trajectories;

G4TrajectoriesTree::~G4TrajectoriesTree() {}

void G4TrajectoriesTree::Setup() {
    if (!Chain) {
        std::cout << "Chain for G4Trajectories not defined" << std::endl;
        return;
    }

    // Setup the module base.
    AnalysisTreeBase::Setup();

    // Set up the module branches.
    fTrajectoryAddr = &Trajectory;
    Chain->SetBranchAddress("Trajectory", 
                            &fTrajectoryAddr);
}

