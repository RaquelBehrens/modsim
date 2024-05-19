#include <stdexcept>
#include "FSM_State.h"

ModelDataDefinition* FSM_State::NewInstance(Model* model, std::string name) {
	return new FSM_State(model, name);
}

FSM_State::FSM_State(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<FSM_State>(), name) {
	_name = name;
}

PluginInformation* FSM_State::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<FSM_State>(), &FSM_State::LoadInstance, &FSM_State::NewInstance);
	info->setDescriptionHelp("//@TODO");
	info->setReceiveTransfer(true);
	info->setSendTransfer(true);
    //info->setAuthor("...");
	//info->setDate("...");
	//info->setObservation("...");
    return info;
}

ModelComponent* FSM_State::LoadInstance(Model* model, PersistenceRecord *fields) {
	FSM_State* newComponent = new FSM_State(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void FSM_State::_saveInstance(PersistenceRecord *fields, bool saveDefaultValues) {
	fields->saveField("name", _name, "");
}

bool FSM_State::_loadInstance(PersistenceRecord *fields) {
    bool res = true;
    try {
        _name = fields->loadField("name", "");
        //_isInitialState = fields->loadField("isInitialState", );
	} catch (...) {
		res = false;
    }

    return res;
}

std::string FSM_State::show(){
    return ModelComponent::show();
}

void FSM_State::setAsInitialState() {
    _efsm->setInitialState(this);
}

void FSM_State::setEFSM(ExtendedFSM* efsm) {
    _efsm = efsm;
}

void FSM_State::setRefinement(ExtendedFSM* refinement) {
    _refinement = refinement;
}

void FSM_State::resetRefinment() {
    if (_refinement != nullptr) {
        _refinement->reset();
    }
}
ExtendedFSM* FSM_State::getRefinement() {
    return _refinement;
}

void FSM_State::fire(Entity* entity) {
    auto connections = this->getConnections()->connections();
    auto transitionChosen = dynamic_cast<FSM_Transition*>(connections->begin()->second->component);
    auto transitionDefault = transitionChosen;

    auto anyDefaultConnected = false;
    auto totalEnableds = 0;
    auto deterministicEnabled = false;
    auto nonDefaultEnabled = false;

    for(auto connection: *connections) {
        auto transition = dynamic_cast<FSM_Transition*>(connection.second->component);

        if (transition->isDefault()) {
            anyDefaultConnected = true;
            transitionDefault = transition;
        }

        if (transition->isEnabled()) {
            ++totalEnableds;

            if (transition->isDeterministic()) {
                deterministicEnabled = true;
            }

            if (transition->isDefault()){
                if (not nonDefaultEnabled) {
                    transitionChosen = transition;
                }
            } else {
                nonDefaultEnabled = true;
                transitionChosen = transition;
            }
        }
    }

    if (deterministicEnabled and totalEnableds > 1) {
        throw std::domain_error("More than a transition and at least one is deterministic.");
    }

    if (totalEnableds == 0) {
        transitionChosen = transitionDefault;
    }

    if (_refinement != nullptr and not transitionChosen->isPreemptive()) {
        _refinement->enterEFSM(entity, transitionChosen);
    }

   this->_parentModel->sendEntityToComponent(entity, transitionChosen); 
}

void FSM_State::fireWithOnlyImmediate(Entity* entity) {
    auto connections = this->getConnections()->connections();
    auto transitionChosen = dynamic_cast<FSM_Transition*>(connections->begin()->second->component);

    auto totalEnableds = 0;
    auto deterministicEnabled = false;
    auto nonDefaultEnabled = false;

    for(auto connection: *connections) {
        auto transition = dynamic_cast<FSM_Transition*>(connection.second->component);

        if (transition->isImmediate() and transition->isEnabled()) {
            ++totalEnableds;

            if (transition->isDeterministic()) {
                deterministicEnabled = true;
            }

            if (transition->isDefault()){
                if (not nonDefaultEnabled) {
                    transitionChosen = transition;
                }
            } else {
                nonDefaultEnabled = true;
                transitionChosen = transition;
            }
        }
    }
    if (deterministicEnabled and totalEnableds > 1) {
        throw std::domain_error("More than a transition and at least one is deterministic.");
    }

    if (totalEnableds > 0) {
        if (_refinement != nullptr and not transitionChosen->isPreemptive()) {
            _refinement->enterEFSM(entity, transitionChosen);
        }

        this->_parentModel->sendEntityToComponent(entity, transitionChosen); 
    } else {
        _efsm->leaveEFSM(entity, this);
    }
}


void FSM_State::_onDispatchEvent(Entity* entity, unsigned int inputPortNumber) {
    if (_mustBeImmediate) {
        _mustBeImmediate = false;

        if (isFinalState()) {
            _efsm->leaveEFSM(entity, this);
        }

        fireWithOnlyImmediate(entity);
    } else {
        fire(entity);
    }
}

