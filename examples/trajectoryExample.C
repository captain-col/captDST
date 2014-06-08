////////////////////////////////////////////////////////////////
// An example that prints the trajectory information contained in a DST file.
//
// This example assumes that you have already got a dst file written by
// CAPTAINSUMMARY.exe (I'm assuming it's called example.root, but the name
// doesn't matter). 

// A simple way to run this example is:
// 
// The captDST package needs to be in your path when you run
// dst-tools-setup, but it only needs to be run once.
//
// dst-tools-setup example.root
//
// This creates a captDST subdirectory in your analysis work area.
//
// Assuming ROOT is in your path, the script can then be run as:
//
// root -b -q captDST/load.C trajectoryExample.C++(\"example.root\")
//

#include <iostream>

#include "TSystem.h"
#include "captDST/G4TrajectoriesTree.h"

void trajectoryExample(const char* file) {
    gG4Trajectories.AddFile(file);
    gG4Trajectories.Setup();
    
    int nLimit = gG4Trajectories.Chain->GetEntries();

    for (int entry = 0; entry < nLimit; ++entry) {
        gG4Trajectories.Chain->GetEntry(entry);
        std::cout << entry 
                  << " " << nLimit
                  << " " << gG4Trajectories.RunId
                  << " " << gG4Trajectories.SubrunId
                  << " " << gG4Trajectories.EventId
                  << " " << gG4Trajectories.Trajectory.size()
                  << std::endl;
        for (std::size_t i = 0; i<gG4Trajectories.Trajectory.size(); ++i) {
            std::cout << "     "
                      << " " << gG4Trajectories.Trajectory[i].TrajId
                      << " " << gG4Trajectories.Trajectory[i].ParentId
                      << " " << gG4Trajectories.Trajectory[i].PrimaryId
                      << " " << gG4Trajectories.Trajectory[i].PDG
                      << " " << gG4Trajectories.Trajectory[i].Mass
                      << " " << gG4Trajectories.Trajectory[i].Charge
                      << std::endl;
        }
    }
    
    std::cout << "ALL DONE" << std::endl;
}
