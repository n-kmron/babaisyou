#include "levelmechanics.h"
#include <vector>

using namespace std;

LevelMechanics::LevelMechanics(const std::vector<GameObject> & elements) : elements_ { elements }, rules_ { RuleManager() } {
}

void LevelMechanics::dropElement(const Position & pos) {

}

bool LevelMechanics::contains(const Position & pos) {
    return false;
}

vector<GameObject> LevelMechanics::findAllElement(const Element & element) {
    return vector<GameObject>();
}

void LevelMechanics::move(const Direction & dir) {

}

void LevelMechanics::setElementPosition(const Element & element, const Position & pos) {

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
