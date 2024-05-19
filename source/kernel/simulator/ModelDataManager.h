/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ElementManager.h
 * Author: rafael.luiz.cancian
 *
 * Created on 7 de Novembro de 2018, 12:48
 */

#ifndef ELEMENTMANAGER_H
#define ELEMENTMANAGER_H

#include <list>
#include <map>
#include "../util/List.h"
#include "ModelDataDefinition.h"

//namespace GenesysKernel {
class Model;

/*!
 * The ModelDataManager is responsible for inserting and removing elements (ModelDataDefinition) used by components,
 * in a consistent way.
 * TO FIX: No direct access for insertion or deletion should be allow
 */
class ModelDataManager {
public:
	ModelDataManager(Model* model);
	virtual ~ModelDataManager() = default;
public:
	bool insert(ModelDataDefinition* anElement);
	void remove(ModelDataDefinition* anElement); ///< Deprected
	bool insert(std::string datadefinitionTypename, ModelDataDefinition* anElement); ///< Deprected
	void remove(std::string datadefinitionTypename, ModelDataDefinition* anElement);
	bool check(std::string datadefinitionTypename, ModelDataDefinition* anElement, std::string expressionName, std::string* errorMessage);
	bool check(std::string datadefinitionTypename, std::string elementName, std::string expressionName, bool mandatory, std::string* errorMessage);
	void clear();
public:
	ModelDataDefinition* getDataDefinition(std::string datadefinitionTypename, Util::identification id);
	ModelDataDefinition* getDataDefinition(std::string datadefinitionTypename, std::string name);
	unsigned int getNumberOfDataDefinitions(std::string datadefinitionTypename);
	unsigned int getNumberOfDataDefinitions();
	int getRankOf(std::string datadefinitionTypename, std::string name); ///< returns the position (1st position=0) of the modeldatum if found, or negative value if not found
	std::list<std::string>* getDataDefinitionClassnames() const;

	//private:
public:
	// @TODO: Should be removed and replaced by GetElement(elementType, rank)
	List<ModelDataDefinition*>* getDataDefinitionList(std::string datadefinitionTypename) const;
public:
	void show();
	Model* getParentModel() const;
	bool hasChanged() const;
	void setHasChanged(bool _hasChanged);
private:
	std::map<std::string, List<ModelDataDefinition*>*>* _datadefinitions;
	Model* _parentModel;
	bool _hasChanged = false;
};
//namespace\\}
#endif /* ELEMENTMANAGER_H */

