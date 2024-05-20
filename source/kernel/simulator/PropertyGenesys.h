#ifndef PROPERTY_H
#define PROPERTY_H

#include "SimulationControlAndResponse.h"
#include "ModelComponent.h"

class PropertyEditorGenesys {
public: // constructor and destructor
	PropertyEditorGenesys() = default;
	virtual ~PropertyEditorGenesys() = default;
public: // get
	std::list<ModelComponent*> getElements(){
		return _elements;
	}
public:
	void changeProperty(std::string id, std::string attribute, std::string value);
	SimulationControl* findProperty(std::string id, std::string attribute);
	void addElement(ModelComponent* component);
private: // attributes
	std::list<ModelComponent*> _elements;
};

#endif
