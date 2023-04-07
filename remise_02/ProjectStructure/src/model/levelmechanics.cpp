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
    rules_.scanRules(elements_);
    vector<Element> isYou = rules_.rules()[Element::YOU];
    for(int index=0; index<isYou.size(); ++index) {
        Element isYouType = fromRuleToPlayable(isYou.at(index));
        vector<GameObject> allIsYou = findAllElement(isYouType);
        changePosition(dir, allIsYou.at(index));
    }
}

void LevelMechanics::changePosition(const Direction & dir, const GameObject & object) {
    for(unsigned int index=0; index<elements_.size(); ++index) {
        GameObject current = elements_.at(index);
        if(current.element() == object.element() && current.pos() == object.pos()) {
            Position pos = current.pos().next(dir);
            elements_.at(index).setPosition(pos);
        }
    }
}

Element LevelMechanics::fromRuleToPlayable(const Element & element) {
    if(element == Element::TEXT_BABA) {
        return Element::BABA;
    } if(element == Element::TEXT_FLAG) {
        return Element::FLAG;
    } if(element == Element::TEXT_GOOP) {
        return Element::SINK;
    } if(element == Element::TEXT_GRASS) {
        return Element::GRASS;
    } if(element == Element::TEXT_LAVA) {
        return Element::LAVA;
    } if(element == Element::TEXT_METAL) {
        return Element::METAL;
    } if(element == Element::TEXT_ROCK) {
        return Element::ROCK;
    } if(element == Element::TEXT_WALL) {
        return Element::WALL;
    } throw invalid_argument("This rule type does not have a playable type");
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
