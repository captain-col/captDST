#ifndef G4VerticesTree_H_seen
#define G4VerticesTree_H_seen
/// An include file to be used in ROOT macros. 
/// 
/// Define a global variable that will be filled with the G4Vertices tree.
///

#include "AnalysisTreeBase.h"

#include "captDSTProjectHeaders.h"

#include <iostream>

/// The structure that will be attached to the branches of the G4Vertices
/// tree.  This is filled by the TFile::GetEntry() methods.
class G4VerticesTree : public AnalysisTreeBase {
public: 
    /// [TREE MEMBER] The branch containing the G4 primary vertices for the
    /// event.  This is attached during setup.
    std::vector<CP::TG4VerticesModule::TG4Vertex> Vertex;

    /// [TREE MEMBER] The branch containing the G4 primary particles for the
    /// event.  This is attached during setup.
    std::vector<CP::TG4VerticesModule::TG4Particle> Particle;

    ///////////////////////////////////////////////
    // The methods are defined below this marker
    ///////////////////////////////////////////////

    G4VerticesTree() : AnalysisTreeBase("TruthDir/G4Vertices") {}
    virtual ~G4VerticesTree();
    
    /// A method to attach the branches.  This must be used after the chain
    /// has been defined.
    virtual void Setup();

private:    
    /// The address of the tree member needed for reading the tree.
    std::vector<CP::TG4VerticesModule::TG4Vertex>* fVertexAddr;
    std::vector<CP::TG4VerticesModule::TG4Particle>* fParticleAddr;
    
    ClassDef(G4VerticesTree,0);
};

/// The global variable for the G4Vertices tree.
extern G4VerticesTree gG4Vertices;

#endif
// Local Variables:
// mode:c++
// c-basic-offset:4
// End:
