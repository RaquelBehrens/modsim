#include "BoundaryCondition.h"
#include "Lattice.h"
#include <iostream>

BoundaryCondition::BoundaryCondition(Lattice* lattice, Neighborhood* neighborhood) {
    this->lattice = lattice;
    this->neighborhood = neighborhood;
}

BoundaryCondition::BoundaryCondition(const BoundaryCondition& orig) {
}

void BoundaryCondition::setNeighborhood(Neighborhood* neighborhood) {
    this->neighborhood = neighborhood;
}

Neighborhood* BoundaryCondition::getNeighborhood() const {
    return neighborhood;
}

void BoundaryCondition::setLattice(Lattice* lattice) {
    this->lattice = lattice;
}

Lattice* BoundaryCondition::getLattice() const {
    return lattice;
}

std::string BoundaryCondition::getName() const {
    return name;
}

std::string BoundaryCondition::show() {
    return name;
}

