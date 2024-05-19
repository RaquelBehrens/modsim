#include "FSM_ModalModel.h"
#include "../../kernel/simulator/Simulator.h"
#include "../../kernel/simulator/PluginManager.h"

ModelDataDefinition* FSM_ModalModel::NewInstance(Model* model, std::string name) {
	return new FSM_ModalModel(model, name);
}

FSM_ModalModel::FSM_ModalModel(Model* model, std::string name) : ModelComponent(model, Util::TypeOf<FSM_ModalModel>(), name) {
	_name = name;
}

PluginInformation* FSM_ModalModel::GetPluginInformation() {
	PluginInformation* info = new PluginInformation(Util::TypeOf<FSM_ModalModel>(), &FSM_ModalModel::LoadInstance, &FSM_ModalModel::NewInstance);
	info->setDescriptionHelp("//@TODO");
    //info->setAuthor("...");
	//info->setDate("...");
	//info->setObservation("...");
    return info;
}

ModelComponent* FSM_ModalModel::LoadInstance(Model* model, PersistenceRecord *fields) {
	FSM_ModalModel* newComponent = new FSM_ModalModel(model);
	try {
		newComponent->_loadInstance(fields);
	} catch (const std::exception& e) {

	}
	return newComponent;
}

void FSM_ModalModel::_saveInstance(PersistenceRecord *fields, bool saveDefaultValues) {
	fields->saveField("name", _name, "");
}

bool FSM_ModalModel::_loadInstance(PersistenceRecord *fields) {
    bool res = true;
    try {
        _name = fields->loadField("name", "");
	} catch (...) {
		res = false;
    }

    return res;
}

void FSM_ModalModel::_onDispatchEvent(Entity* entity, unsigned int inputPortNumber){
   _efsm->enterEFSM(entity, this->getConnections()->getFrontConnection()->component);
}

std::string FSM_ModalModel::show(){
	return ModelComponent::show() + _efsm->show();
}

void FSM_ModalModel::setEFSMData(ExtendedFSM* efsm) {
	_efsm = efsm;
}

ExtendedFSM* FSM_ModalModel::getEFSM() const {
	return _efsm;
}

void FSM_ModalModel::_createInternalAndAttachedData() {
	PluginManager* pm = _parentModel->getParentSimulator()->getPlugins();

	// attached
	if (_efsm == nullptr) {
		_efsm = pm->newInstance<ExtendedFSM>(_parentModel, getName() + "." + "efsm");
	}

	_attachedDataInsert("EFSM", _efsm);
}
