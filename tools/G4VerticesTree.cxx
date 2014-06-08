#include "G4VerticesTree.h"

G4VerticesTree gG4Vertices;

G4VerticesTree::~G4VerticesTree() {}

void G4VerticesTree::Setup() {
    if (!Chain) {
        std::cout << "Chain for G4Vertices not defined" << std::endl;
        return;
    }

    // Setup the module base.
    AnalysisTreeBase::Setup();

    // Set up the module branches.
    fVertexAddr = &Vertex;
    Chain->SetBranchAddress("Vertex", &fVertexAddr);

    fParticleAddr = &Particle;
    Chain->SetBranchAddress("Particle", &fParticleAddr);
}

