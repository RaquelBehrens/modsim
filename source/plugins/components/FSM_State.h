#ifndef FSM_STATE_H
#define FSM_STATE_H

#include "../../kernel/simulator/ModelComponent.h"
#include "FSM_Transition.h"
#include "../data/EFSM.h"
#include <string>

class ExtendedFSM;

class FSM_State : public ModelComponent {
public:

    FSM_State(Model* model, std::string name = "");
    virtual ~FSM_State() = default;

    void setName(std::string name) {
        _name = name;
    }

    std::string getName() const {
        return _name;
    }

    void setIsFinalState(bool isFinalState) {
        _isFinalState = isFinalState;
    }

    bool isFinalState() const {
        return _isFinalState;
    }

    void setMustBeImmediate() {
        _mustBeImmediate = true;
    }

    void resetRefinment();
    void setAsInitialState();
    void setEFSM(ExtendedFSM* efsm);
    void setRefinement(ExtendedFSM* refinement);
    ExtendedFSM* getRefinement();

private: 
    void fire(Entity* entity);
    void fireWithOnlyImmediate(Entity* entity);

public: // static
    static PluginInformation* GetPluginInformation();
    static ModelComponent* LoadInstance(Model* model, PersistenceRecord *fields);
    static ModelDataDefinition* NewInstance(Model* model, std::string name = "");

public: // virtual
    virtual std::string show();
protected: /// virtual protected method that must be overriden
    virtual bool _loadInstance(PersistenceRecord *fields);
    virtual void _saveInstance(PersistenceRecord *fields, bool saveDefaultValues);
    /// new virtual methods for all ModelComponents
    virtual void _onDispatchEvent(Entity* entity, unsigned int inputPortNumber); ///< This method is only for ModelComponents, not ModelDataElements

private:
    std::string _name;
    bool _isFinalState = false;
    bool _mustBeImmediate = false;
    ExtendedFSM* _refinement = nullptr;
    ExtendedFSM* _efsm;
};
#endif /* FSM_STATE_H */
