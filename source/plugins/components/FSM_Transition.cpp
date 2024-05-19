#include <iostream>
#include <sstream>
#include "FSM_Transition.h"
#include <iostream>
#include <sstream>



ModelDataDefinition* FSM_Transition::NewInstance(Model* model, std::string name) {
    return new FSM_Transition(model, name);
}

FSM_Transition::FSM_Transition(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<FSM_Transition>(), name) {
        //_name = name;
}

PluginInformation* FSM_Transition::GetPluginInformation() {
    PluginInformation* info = new PluginInformation(Util::TypeOf<FSM_Transition>(), &FSM_Transition::LoadInstance, &FSM_Transition::NewInstance);
    info->setDescriptionHelp("//@TODO");
    //info->setAuthor("...");
    //info->setDate("...");
    //info->setObservation("...");
    return info;
}

ModelComponent* FSM_Transition::LoadInstance(Model* model, PersistenceRecord *fields) {
    FSM_Transition* newComponent = new FSM_Transition(model);
    try {
        newComponent->_loadInstance(fields);
    } catch (const std::exception& e) {

    }
    return newComponent;
}

void FSM_Transition::_saveInstance(PersistenceRecord *fields, bool saveDefaultValues) {
    //fields->saveField("name", _name, "");
}

bool FSM_Transition::_loadInstance(PersistenceRecord *fields) {
    bool res = true;
    // try {
    // } catch (...) {
    //     res = false;
    // }
    return res;
}

bool FSM_Transition::_check(std::string* errorMessage){
    bool resultAll = true;
    resultAll &= _parentModel->checkExpression(_guardExpression, "Transition expression", errorMessage);

    return resultAll;
}

std::string FSM_Transition::show(){
    return ModelComponent::show();
}

void FSM_Transition::_onDispatchEvent(Entity* entity, unsigned int inputPortNumber){
    _parentModel->parseExpression(getOutputActions());

    //postfire
    _parentModel->parseExpression(getSetActions());

    auto connections = getConnections()->connections();
    auto nextState = dynamic_cast<FSM_State*>(connections->begin()->second->component);

    if (not isHistory()) {
        nextState->resetRefinment();
    }

    nextState->setMustBeImmediate();
    this->_parentModel->sendEntityToComponent(entity, nextState); 
}

bool FSM_Transition::isEnabled(){
    if (_guardExpression == "") {
        return true;
    }

    return bool(_parentModel->parseExpression(_guardExpression));
}

void FSM_Transition::executeActions(std::string actions){
    if (actions == "") {
        return;
    }
    auto actions_ss = std::stringstream();
    actions_ss << actions;
    auto action = std::string();

    while(std::getline(actions_ss, action, ';')) {
        _parentModel->parseExpression(action);
    }
}

void FSM_Transition::executeOutputActions() {
    executeActions(_outputActions);
}

void FSM_Transition::executeSetActions() {
    executeActions(_setActions);
}
