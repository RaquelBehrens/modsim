#include "LocalRule.h"
#include "Cell.h"
#include "CellularAutomata.h"

/* **************
 *  PUBLIC
 * **************/

LocalRule::LocalRule(CellularAutomata* parentCellularAutomata, StateSet* stateSet) {
    this->parentCellularAutomata = parentCellularAutomata;
    parentCellularAutomata->setLocalRule(this);
    if (stateSet != nullptr)
        this->stateSet = stateSet;
    else
        this->stateSet = parentCellularAutomata->getStateSet();
}

LocalRule::LocalRule(const LocalRule& orig) {

}

/* **************
 *  PUBLIC
 * **************/

void LocalRule::setStateSet(StateSet* stateSet) {
    this->stateSet = stateSet;
}