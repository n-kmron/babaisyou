#include "levelmechanics.h"


void LevelMechanics::setElements(const std::vector<GameObject>& elements) {
    elements_ = elements;
}

void LevelMechanics::setLevel(const Level& level) {
    level_ = level;
}

void LevelMechanics::setRules(const RuleManager& rules) {
    rules_ = rules;
}

LevelMechanics& LevelMechanics::operator=(const LevelMechanics & other) {
        // Vérification de l'auto-assignation
        if (this != &other) {
            this->setElements(elements_);
            this->setLevel(other.level_);
            this->setRules(other.rules_);
        }
        // Renvoie une référence à l'objet this pour permettre les affectations en cascade
        return *this;
    }
