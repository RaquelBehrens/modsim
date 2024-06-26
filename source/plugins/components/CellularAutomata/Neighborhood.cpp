#include "Neighborhood.h"
#include "CellularAutomata.h"

#include <iostream>

/* **************
 *  PUBLIC
 * **************/

Neighborhood::Neighborhood(CellularAutomata* parentCellularAutomata, unsigned short radius, BoundaryCondition* boundary,bool includeCellItself) {
    this->parentCellularAutomata = parentCellularAutomata;
    parentCellularAutomata->setNeighborhood(this);
    this->radius = radius;
    this->boundary = boundary;
    this->includeCellItself = includeCellItself;
}

Neighborhood::Neighborhood(const Neighborhood& orig) {
}

/* **************
 *  PUBLIC
 * **************/

std::string Neighborhood::show() {
    return "-";
}


/* **************
 *  PUBLIC
 * **************/

void Neighborhood::setRadius(unsigned short radius) {
    this->radius = radius;
}

unsigned short Neighborhood::getRadius() const {
    return radius;
}

void Neighborhood::setBoundary(BoundaryCondition* boundary) {
    this->boundary = boundary;
    boundary->setNeighborhood(this);
}

BoundaryCondition* Neighborhood::getBoundary() const {
    return boundary;
}

void Neighborhood::setIncludeCellItself(bool includeCellItself) {
    this->includeCellItself = includeCellItself;
} 

bool Neighborhood::getIncludeCellItself() const {
    return includeCellItself;
}


/* **************
 *  PROTECTED
 * **************/

Cell* Neighborhood::getNeighborCell(std::vector<int>* cellPosition, std::vector<std::pair<unsigned short, int>> dimensionChanges) {
    std::vector<int> neighborPosition;
    neighborPosition = *cellPosition;
    for (std::pair<unsigned short, int> change : dimensionChanges) {
        neighborPosition.at(change.first) += change.second;
    }
    //std::cout << "Neig pos from "<<Util::showNDimPosition(cellPosition)<< " is " <<Util::showNDimPosition(&neighborPosition);
    Cell* neighCell = boundary->getNeighborCell(*cellPosition, neighborPosition);
    //std::cout << std::endl;
    return neighCell;
}

