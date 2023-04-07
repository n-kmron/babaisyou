#include "levelmechanics.h"
#include "../util.cpp"
#include <vector>

using namespace std;

LevelMechanics::LevelMechanics(const std::vector<GameObject> & elements) : elements_ { elements }, rules_ { RuleManager() } {
}

void LevelMechanics::dropElement(const Position & pos, const Element & element) {
    for(int elementIndex=0; elementIndex<elements_.size(); ++elementIndex) {
        if(elements_.at(elementIndex).pos() == pos && elements_.at(elementIndex).element() == element) {
            elements_.erase(elements_.begin() + elementIndex);
        }
    }
}

vector<GameObject> LevelMechanics::findAllElement(const Element & element) {
    vector<GameObject> typeElement;
    for(int elementIndex=0; elementIndex<elements_.size(); ++elementIndex) {
        if(elements_.at(elementIndex).element() == element) {
            typeElement.push_back(elements_.at(elementIndex));
        }
    }
    return typeElement;
}

void LevelMechanics::move(const Direction & dir) {
    vector<Element> isYou = rules().rules()[Element::YOU];
    for(int index=0; index<isYou.size(); ++index) {
        vector<GameObject> allIsYou = findAllElement(isYou.at(index));
        changePosition(dir, allIsYou.at(index));
    }
}

void LevelMechanics::changePosition(const Direction & dir, const GameObject & object) {
    for(unsigned int index=0; index<elements_.size(); ++index) {
        GameObject current = elements_.at(index);
        if(current.element() == object.element() && current.pos() == object.pos()) {
            Position pos = current.pos().next(dir);
            current.setPosition(pos);
        }
    }
}

void LevelMechanics::setElementPosition(const Element & element, const Position & pos) {
    GameObject gameobject(element, pos);
    elements_.push_back(gameobject);
}

bool LevelMechanics::isMovable(const Direction & dir, const GameObject & element) {
    return false;
}

bool LevelMechanics::isWon() {
    return false;
}

bool LevelMechanics::isKill() {
    return false;
}

bool LevelMechanics::pushable() {
    return false;
}


vector<GameObject> & LevelMechanics::elements() {
    return elements_;
}

RuleManager LevelMechanics::rules() const {
    return rules_;
}

void LevelMechanics::setElements(const vector<GameObject>& elements) {
    elements_ = elements;
}

void LevelMechanics::setRules(const RuleManager& rules) {
    rules_ = rules;
}

LevelMechanics& LevelMechanics::operator=(const LevelMechanics & other) {
        // Vérification de l'auto-assignation
        if (this != &other) {
            this->setElements(elements_);
            this->setRules(other.rules_);
        }
        return *this;
}
