#ifndef FSM_MODALMODEL_H
#define FSM_MODALMODEL_H

#include "../../kernel/simulator/ModelComponent.h"
#include "../data/EFSM.h"
#include <string>

class FSM_ModalModel : public ModelComponent {
public:
	FSM_ModalModel(Model* model, std::string name = "");
	
	virtual ~FSM_ModalModel() = default;

	void setName(std::string name){
		_name = name;
	}

	std::string getName(){
		return _name;
	}

	void setEFSMData(ExtendedFSM* efsm);

	ExtendedFSM* getEFSM() const;

	ExtendedFSM* getInternalDataDefinition(){
		return _efsm;
	}

	int _value;

public: // static
	static PluginInformation* GetPluginInformation();
	static ModelComponent* LoadInstance(Model* model, PersistenceRecord *fields);
	static ModelDataDefinition* NewInstance(Model* model, std::string name = "");

public: // virtual
	virtual std::string show();
protected: /// virtual protected method that must be overriden
	virtual void _createInternalAndAttachedData();
	virtual bool _loadInstance(PersistenceRecord *fields);
	virtual void _saveInstance(PersistenceRecord *fields, bool saveDefaultValues);
	/// new virtual methods for all ModelComponents
	virtual void _onDispatchEvent(Entity* entity, unsigned int inputPortNumber); ///< This method is only for ModelComponents, not ModelDataElements


private:
	std::string _name;
    ExtendedFSM* _efsm = nullptr;
};

#endif /* FSM_MODALMODEL_H */
