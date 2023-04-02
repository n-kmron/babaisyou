#include "rulemanager.h"
#include "gameobject.h"
#include "../util.cpp"

using namespace std;


RuleManager::RuleManager() {
    //initialize a vector 'material_'
    material_.push_back(Element::TEXT_BABA);
    material_.push_back(Element::TEXT_WALL);
    material_.push_back(Element::TEXT_ROCK);
    material_.push_back(Element::TEXT_LAVA);
    material_.push_back(Element::TEXT_GRASS);
    material_.push_back(Element::TEXT_METAL);
    material_.push_back(Element::TEXT_GOOP);
    material_.push_back(Element::TEXT_FLAG);

    //initialize a vector 'aspect_'
    aspect_.push_back(Element::YOU);
    aspect_.push_back(Element::WIN);
    aspect_.push_back(Element::STOP);
    aspect_.push_back(Element::SINK);
    aspect_.push_back(Element::PUSH);
    aspect_.push_back(Element::KILL);
    aspect_.push_back(Element::TEXT_BABA);
    aspect_.push_back(Element::TEXT_WALL);
    aspect_.push_back(Element::TEXT_ROCK);
    aspect_.push_back(Element::TEXT_LAVA);
    aspect_.push_back(Element::TEXT_GRASS);
    aspect_.push_back(Element::TEXT_METAL);
    aspect_.push_back(Element::TEXT_GOOP);
    aspect_.push_back(Element::TEXT_FLAG);
}

map<Element, vector<Element>> RuleManager::rules() {
    return rules_;
}


void RuleManager::addRule(const Element & aspect,const Element & material) {
    if (rules_.find(aspect) == rules_.end()) {
        rules_[aspect] = vector<Element>();
    }
    rules_[aspect].push_back(material);
}

void RuleManager::checkRules(const vector<GameObject> & elements, int isIndex, Direction materialDir, Direction aspectDir) {
    Position materialPos = elements.at(isIndex).pos().next(materialDir);
    vector<Element> materialElements = findElementAtPosition(elements, materialPos);

    if(!materialElements.empty()) {
        Position aspectPos = elements.at(isIndex).pos().next(aspectDir);
        vector<Element> aspectElements = findElementAtPosition(elements, aspectPos);

        if(!aspectElements.empty()) {
            int materialIndex = -1;
            int aspectIndex = - 1;

             for(int vectorIndex=0; vectorIndex<materialElements.size(); ++vectorIndex) {
                if(isMaterial(materialElements.at(vectorIndex))) {
                    materialIndex = vectorIndex;
                }
             }

             for(int vectorIndex=0; vectorIndex<aspectElements.size(); ++vectorIndex) {
                if(isAspect(aspectElements.at(vectorIndex))) {
                    aspectIndex = vectorIndex;
                }
             }
             if(materialIndex != -1 && aspectIndex != -1) {
                 addRule(aspectElements.at(aspectIndex), materialElements.at(materialIndex));
             }

        }
    }
}

void RuleManager::scanRules(const vector<GameObject> & elements) {
    //empty it before complete it
    rules_.clear();

    for(int i=0; i<elements.size(); ++i) {
        if(elements.at(i).element() == Element::IS) { //chercher les is
            checkRules(elements, i, Direction::LEFT, Direction::RIGHT);
            checkRules(elements, i, Direction::UP, Direction::DOWN);
        }
    }
}

bool RuleManager::isMaterial(const Element & element) {
    for(int i=0; i<material_.size(); ++i) {
        if(element == material_.at(i)) {
            return true;
        }
    }
    return false;
}

bool RuleManager::isAspect(const Element & element) {
    for(int i=0; i<aspect_.size(); ++i) {
        if(element == aspect_.at(i)) {
            return true;
        }
    }
    return false;
}




