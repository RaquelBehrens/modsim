#include "EFSM.h"
#include <vector>
#include <string>
#include <map>
#include <utility>


#ifdef PLUGINCONNECT_DYNAMIC

extern "C" StaticGetPluginInformation GetPluginInformation() {
    return &ExtendedFSM::GetPluginInformation;
}
#endif

ExtendedFSM::ExtendedFSM(Model* model, std::string name) : ModelDataDefinition(model, Util::TypeOf<ExtendedFSM>(), name) {}

std::string ExtendedFSM::show(){
    auto txt = ModelDataDefinition::show() + ",variables=[";
    for (auto* var: *_variables) {
        txt += var->show() + ",";
    }
    txt = txt.substr(0, txt.length() - 1) + "]";
    return txt;
}

void ExtendedFSM::_createInternalAndAttachedData(){
    ModelDataManager* elems = _parentModel->getDataManager();
    
    for (Variable* variable : *_variables) {
        _attachedDataInsert(getName() + "." + variable->getName(), variable);
    }

}

void ExtendedFSM::_saveInstance(PersistenceRecord *fields, bool saveDefaultValues) {}

bool ExtendedFSM::_loadInstance(PersistenceRecord *fields) {
    bool res = true;
    try {
    } catch (...) {
        res = false;
    }

    return res;
}

PluginInformation* ExtendedFSM::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<ExtendedFSM>(), &ExtendedFSM::LoadInstance, &ExtendedFSM::NewInstance);
    return info;
}

ModelDataDefinition* ExtendedFSM::NewInstance(Model* model, std::string name) {
    return new ExtendedFSM(model, name);
}

ModelDataDefinition* ExtendedFSM::LoadInstance(Model* model, PersistenceRecord *fields) {
    ExtendedFSM* newElement = new ExtendedFSM(model);
    try {
        newElement->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newElement;
}

bool ExtendedFSM::_check(std::string* errorMessage){
    return true;
}

void ExtendedFSM::_initBetweenReplications(){
    _returnModels->clear();
    _currentState = _initialState;
    for (auto* var: *_variables) {
        InitBetweenReplications(var);
        for (auto value: *var->getValues()) {
            _parentModel->parseExpression(value.first + " = " + std::to_string(value.second));
        }
    }
}
void ExtendedFSM::reset(){
    this->_initBetweenReplications();
}

void ExtendedFSM::insertVariable(Variable* variable) {
    _variables->push_back(variable);
}

std::string ExtendedFSM::getCurrentState(){
    return _currentState->getName();
}


void ExtendedFSM::setInitialState(FSM_State* state) {
    _initialState = state;
}

void ExtendedFSM::setCurrentState(FSM_State* state) {
    _currentState = state;
}

void ExtendedFSM::leaveEFSM(Entity* entity, FSM_State* newCurrentState) {
    setCurrentState(newCurrentState);

    auto returnComponent = _returnModels->back();
    _returnModels->pop_back();
    this->_parentModel->sendEntityToComponent(entity, returnComponent); 
}

void ExtendedFSM::enterEFSM(Entity* entity, ModelComponent* returnState) {
    if (_currentState->isFinalState()) {
        this->_parentModel->sendEntityToComponent(entity, returnState); 
    } else {
        _returnModels->push_back(returnState);
        this->_parentModel->sendEntityToComponent(entity, _currentState); 
    }
}