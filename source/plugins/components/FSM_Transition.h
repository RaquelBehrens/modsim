#ifndef FSM_TRANSITION_H
#define FSM_TRANSITION_H

#include "../../kernel/simulator/ModelComponent.h"
#include "../../kernel/simulator/Model.h"
#include "FSM_State.h"
#include "../data/EFSM.h"

#include <string>

class ExtendedFSM;

class FSM_Transition : public ModelComponent {
public:
	FSM_Transition(Model* model, std::string name = "");

	virtual ~FSM_Transition() = default;

	// getters
    std::string getGuardExpression() {
        return _guardExpression;
    }

    std::string getOutputActions() {
        return _outputActions;
    }

    std::string getSetActions() {
        return _setActions;
    }

	// setters
    void setGuardExpression(std::string guardExpression) {
         _guardExpression = guardExpression;
    }

    void setOutputActions(std::string outputActions) {
         _outputActions = outputActions;
    }

    void setSetActions(std::string setActions) {
         _setActions = setActions;
    }

	void setNondeterministic(bool nondeterministic) {
		_nondeterministic = nondeterministic;
	}

	void setDefault(bool defaultTransition) {
		_default = defaultTransition;
	}

	void setPreemptive(bool preemptive) {
		_preemptive = preemptive;
	}

	void setHistory(bool history) {
		_history = history;
	}

	void setImmediate(bool immediate) {
		_immediate = immediate;
	}

	bool isNondeterministic() {
		return _nondeterministic;
	}

	bool isDeterministic() {
		return not _nondeterministic;
	}

	bool isDefault() {
		return _default;
	}

	bool isPreemptive() {
		return _preemptive;
	}

	bool isHistory() {
		return _history;
	}

	bool isImmediate() {
		return _immediate;
	}

	bool isEnabled();
	void executeOutputActions();
	void executeSetActions();

private:
	void executeActions(std::string actions);

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
	virtual bool _check(std::string* errorMessage);

private:
	std::string _guardExpression;
	std::string _outputActions;
	std::string _setActions;
	bool _nondeterministic = false;
	bool _default = false;
	bool _preemptive = false;
	bool _history = false;
	bool _immediate = false;
    /* Transition:
    Nondeterministic: if not must be the only enabled transition.
    Default: if given a value true, 
        specifies that this transition is enabled if no other non-default transition is enabled and 
        if its guard evaluates to true
    Preemptive: if so the refinement of its source state is not fired.
    History: If false reset the refinment of its destination state.
    Immediate: if so must be taken as soon as its source state is entered, in the same iteration.
    */

};


#endif /* FSM_TRANSITION_H */
