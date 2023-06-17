#pragma once
#include "common.hpp"


struct ProcessNode {

	ProcessNode* previous;
	ProcessNode* next;
	Base* base;

	//0204d57c
	void unlink();

};
NTR_SIZE_GUARD(ProcessNode, 0xC);


struct PriorityNode : public ProcessNode {

	u16 currentPriority;
	u16 sortPriority;

	//0204d560
	void unlink();

};
NTR_SIZE_GUARD(PriorityNode, 0x10);


struct SceneNode {

	SceneNode* parent;
	SceneNode* firstChild;
	SceneNode* previous;
	SceneNode* next;
	Base* object;

	//02043b58
	SceneNode();

	//02043b40
	void reset();

	//02043a2c
	//returns the next tree's node or (if none could be found) the next parent's next node. May return null if no parent with siblings exists.
	SceneNode* getNext();

	//020439f0
	//Traverses the tree upwards and returns the next parent's next node. If no parent has siblings anymore, null is returned.
	SceneNode* getParentNext();

};
NTR_SIZE_GUARD(SceneNode, 0x14);


struct LinkedList {

	ProcessNode* first;
	ProcessNode* last;

	//020438e8
	bool append(ProcessNode* node);

	//02043920
	sym	bool remove(ProcessNode* node);

	//020438b0
	bool prepend(ProcessNode* node);

	//02043990
	bool insert(ProcessNode* node, ProcessNode* previous);

	//0204d428
	ProcessNode* getNodeByID(u32 id);


};
NTR_SIZE_GUARD(LinkedList, 0x8);


struct ProcessList : public LinkedList {

	BaseProcessFunction executor;

	//0204d46c
	//Traverses the whole list and calls the executor on every node. Always returns true.
	bool execute();

};
NTR_SIZE_GUARD(ProcessList, 0x10);


struct ProcessSet : public ProcessList {

	//0204d4e4
	bool add(PriorityNode* node);

};
NTR_SIZE_GUARD(ProcessSet, 0x10);


struct SceneGraph {

	SceneNode* root;
	BaseProcessFunction executor;

	//02043acc
	//Adds child to the scene graph as a child of parent. returns true if the node was added successfully, false if node is null or if parent is null (indicating the root node) but root is already set.
	bool addChild(SceneNode* child, SceneNode* parent);

	//02043a54
	//Removes the child from the scene graph. returns true only if child has no children itself, false otherwise.
	bool removeChild(SceneNode* child);

	//0204d7b4
	//Traverses the graph and calls the executor on every node. Always returns true.
	bool execute();

};
NTR_SIZE_GUARD(SceneGraph, 0xC);
