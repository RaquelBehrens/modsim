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
	void changeProperty(std::string id, std::string attribute, std::string value) {
		SimulationControl* property = findProperty(id, attribute);

		if (property) {
			property->setValue(value);
		}
	}
	SimulationControl* findProperty(std::string id, std::string attribute){
		for (auto element : _elements) {
			if (std::to_string(element->getId()) == id) {
				for (auto prop : *element->getProperties()->list()) {
					if (prop->getName() == attribute) {
						return prop;
					}
				}
			}
		}
		return nullptr;
	}
	void addElement(ModelComponent* component){
		_elements.push_back(component);
	}
private: // attributes
	std::list<ModelComponent*> _elements;
};

#endif
