#pragma once

#include "Lattice.h"
#include "Neighborhood.h"
#include <string>
#include <vector>



class BoundaryCondition {
public:
	BoundaryCondition(Lattice* lattice = nullptr, Neighborhood* neighborhood=nullptr){
		this->lattice = lattice;
		this->neighborhood = neighborhood;
	}
	BoundaryCondition(const BoundaryCondition& orig){}
    virtual ~BoundaryCondition()=default;
public:
	virtual std::string show() {

	}
	virtual Cell* getNeighborCell(std::vector<int> cellPosition, std::vector<int> neighborCellPosition) = 0; ///< Pure virtual method that has to be overiden by derived class, responsable for defining the missing neighbor of a cell
public:
	void setNeighborhood(Neighborhood* neighborhood){
		this->neighborhood = neighborhood;
	}
	Neighborhood* getNeighborhood() const{
		return neighborhood;
	}
	void setLattice(Lattice* lattice){
		this->lattice = lattice;
	}
	Lattice* getLattice() const{
		return lattice;
	}
protected:
    Lattice* lattice;
    Neighborhood* neighborhood;
private:
};
