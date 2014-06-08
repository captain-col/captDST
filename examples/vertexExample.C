////////////////////////////////////////////////////////////////
// An example that prints the vertex information contained in a DST file.
//
// This example assumes that you have already got a dst file written by
// CAPTAINSUMMARY.exe (I'm assuming it's called example.root, but the name
// doesn't matter). 

// A simple way to run this example is:
// 
// The dstTools package needs to be in your path when you run
// dst-tools-setup, but it only needs to be run once.
//
// dst-tools-setup example.root
//
// This creates a dstTools subdirectory in your analysis work area.
//
// Assuming ROOT is in your path, the script can then be run as:
//
// root -b -q dstTools/load.C vertexExample.C++(\"example.root\")
//

#include <iostream>

#include "TSystem.h"
#include "dstTools/G4VerticesTree.h"

void vertexExample(const char* file) {
    gG4Vertices.AddFile(file);
    gG4Vertices.Setup();
    
    int nLimit = gG4Vertices.Chain->GetEntries();

    for (int entry = 0; entry < nLimit; ++entry) {
        gG4Vertices.Chain->GetEntry(entry);
        std::cout << entry 
                  << " " << nLimit
                  << " " << gG4Vertices.RunId
                  << " " << gG4Vertices.SubrunId
                  << " " << gG4Vertices.EventId
                  << " " << gG4Vertices.Vertex.size()
                  << std::endl;
        for (std::size_t i = 0; i<gG4Vertices.Vertex.size(); ++i) {
            std::cout << "  "
                      << " " << i
                      << " " << gG4Vertices.Vertex[i].VertexId
                      << " " << gG4Vertices.Vertex[i].Particles.size()
                      << std::endl;
            std::size_t nParticles = gG4Vertices.Vertex[i].Particles.size();
            for (std::size_t j=0; j<nParticles; ++j) {
                std::cout << "    "
                          << " " << i
                          << " " << j
                          << " " << gG4Vertices.Vertex[i].Particles[j]
                          << std::endl;
            }
        }
    }
    
    std::cout << "ALL DONE" << std::endl;
}
