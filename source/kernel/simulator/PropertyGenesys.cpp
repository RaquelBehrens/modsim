#include "PropertyGenesys.h"

std::list<ModelComponent*> PropertyEditorGenesys::getElements() {
    return _elements;
}

void PropertyEditorGenesys::changeProperty(std::string id, std::string attribute, std::string value) {
		SimulationControl* property = findProperty(id, attribute);

		if (property) {
			property->setValue(value);
		}
	}

SimulationControl* PropertyEditorGenesys::findProperty(std::string id, std::string attribute) {
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

void PropertyEditorGenesys::addElement(ModelComponent* component) {
    _elements.push_back(component);
}
