#include "rulemanager.h"
#include "gameobject.h"

using namespace std;


RuleManager::RuleManager() {
    //création du vector material_
    material_.push_back(Element::TEXT_BABA);
    material_.push_back(Element::TEXT_WALL);
    material_.push_back(Element::TEXT_ROCK);
    material_.push_back(Element::TEXT_LAVA);
    material_.push_back(Element::TEXT_GRASS);
    material_.push_back(Element::TEXT_METAL);
    material_.push_back(Element::TEXT_GOOP);
    material_.push_back(Element::TEXT_FLAG);

    //création du vector aspect_
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

vector<Element> findElementAtPosition(const vector<GameObject> & elements, const Position & pos) {
    vector<Element> elementsAtPos;
    for(int elementIndex=0; elementIndex<elements.size(); ++elementIndex) {
        if(elements.at(elementIndex).pos() == pos) {
            elementsAtPos.push_back(elements.at(elementIndex).element());
        }
    }
    return elementsAtPos;
}

void RuleManager::scanRules(const vector<GameObject> & elements) {
    //on vide l'ensemble des règles avant de les rescanner
    rules_.clear();

    //on scanne l'ensemble des éléments
    for(int i=0; i<elements.size(); ++i) {
        if(elements.at(i).element() == Element::IS) { //chercher les is
            Position leftPos(elements.at(i).pos().row(), elements.at(i).pos().col()-1);
            vector<Element> leftElements = findElementAtPosition(elements, leftPos);
            if(!leftElements.empty()) {
                Position rightPos(elements.at(i).pos().row(), elements.at(i).pos().col()+1);
                vector<Element> rightElements = findElementAtPosition(elements, rightPos);
                if(!rightElements.empty()) {
                    int materialIndex = -1;
                    int aspectIndex = - 1;
                     for(int vectorIndex=0; vectorIndex<leftElements.size(); ++vectorIndex) {
                        if(isMaterial(leftElements.at(vectorIndex))) {
                            materialIndex = vectorIndex;
                        }
                     }
                     for(int vectorIndex=0; vectorIndex<rightElements.size(); ++vectorIndex) {
                        if(isMaterial(rightElements.at(vectorIndex))) {
                            aspectIndex = vectorIndex;
                        }
                     }
                     if(materialIndex != -1 && aspectIndex != -1) {
                         addRule(rightElements.at(aspectIndex), leftElements.at(materialIndex));
                     }

                }
            }
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




