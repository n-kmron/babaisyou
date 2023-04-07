#include "levelmechanics.h"
#include "../util.cpp"
#include <vector>

using namespace std;

LevelMechanics::LevelMechanics(const std::vector<GameObject> & elements) : elements_ { elements }, rules_ { RuleManager() } {
    rules_.scanRules(elements_);
}

bool LevelMechanics::contains(const Position & pos) {
    int row = pos.row();
    int col = pos.col();
    return !(row > 18 || row < 0 || col > 18 || col < 0);

}

void LevelMechanics::setElementPosition(const GameObject & element) {
    elements_.push_back(element);
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
        for(unsigned int secondIndex=0; secondIndex<allIsYou.size(); ++secondIndex) {
            if(isMovable(dir,allIsYou.at(secondIndex))) {
                changePosition(dir, allIsYou.at(secondIndex));
                pushable(dir, allIsYou.at(secondIndex).pos());
            }
        }
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
        return Element::GOOP;
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

bool LevelMechanics::isMovable(const Direction & dir, const GameObject & element) {
    Position pos = element.pos().next(dir);
    if(!contains(pos)) return false;
    vector<Element> elementsOnNewPosition = findElementAtPosition(elements_, pos);

    //check if the element on the new pos makes a stop
    vector<Element> isStop = rules_.rules()[Element::STOP];
    for(unsigned int index=0; index<elementsOnNewPosition.size(); ++index) {
        for(unsigned int secondIndex=0; secondIndex<isStop.size(); ++secondIndex) {
            if(elementsOnNewPosition.at(index) == fromRuleToPlayable(isStop.at(secondIndex))) {
                return false;
            }
        }
    }
    return true;
}

bool LevelMechanics::isWon() {
    //check if the element on the new pos makes a win
    vector<Element> isWin = rules_.rules()[Element::WIN];
    for(unsigned int isWinIndex=0; isWinIndex<isWin.size(); ++isWinIndex) {
        Element isWinType = fromRuleToPlayable(isWin.at(isWinIndex));
        vector<GameObject> allIsWin = findAllElement(isWinType);

        //for each winning type, find all occurences on the map and check if a isYou element is on the same position
        vector<Element> isYou = rules_.rules()[Element::YOU];
        for(unsigned int isYouIndex=0; isYouIndex<isYou.size(); ++isYouIndex) {
            Element isYouType = fromRuleToPlayable(isYou.at(isYouIndex));
            vector<GameObject> allIsYou = findAllElement(isYouType);

            for(unsigned int i=0; i<allIsYou.size(); ++i) {
                for(unsigned int j=0; j<allIsWin.size(); ++j) {
                    if(allIsYou.at(i).pos() == allIsWin.at(j).pos()) return true;
                }
            }
        }
    }
    return false;
}

bool LevelMechanics::isKill() {
    //intialize a vector with all playable elements that can kill
    vector<Element> murdered;
    vector<Element> isSink = rules_.rules()[Element::SINK];
    vector<Element> isKill = rules_.rules()[Element::KILL];
    for(unsigned int index=0; index<isSink.size(); ++index) {
        murdered.push_back(fromRuleToPlayable(isSink.at(index)));
    }
    for(unsigned int index=0; index<isKill.size(); ++index) {
        murdered.push_back(fromRuleToPlayable(isKill.at(index)));
    }

    //for each murder type, find all occurences on the map and check if a isYou element is on the same position
    for(unsigned int index=0; index<murdered.size(); ++index) {
        vector<GameObject> allMurderers = findAllElement(murdered.at(index));

        vector<Element> isYou = rules_.rules()[Element::YOU];
        for(unsigned int isYouIndex=0; isYouIndex<isYou.size(); ++isYouIndex) {
            Element isYouType = fromRuleToPlayable(isYou.at(isYouIndex));
            vector<GameObject> allIsYou = findAllElement(isYouType);

            for(unsigned int i=0; i<allIsYou.size(); ++i) {
                for(unsigned int j=0; j<allMurderers.size(); ++j) {
                    if(allIsYou.at(i).pos() == allMurderers.at(j).pos()) return true;
                }
            }
        }
    }
    return false;
}

void LevelMechanics::pushable(const Direction & dir, const Position & pos) {
    Position temp = pos;
    Position newPos = temp.next(dir);

    vector<Element> isPush = rules_.rules()[Element::PUSH];
    for(unsigned int index=0; index<isPush.size(); ++index) {
        Element isPushType = fromRuleToPlayable(isPush.at(index));
        vector<GameObject> allIsPush = findAllElement(isPushType);
        for(unsigned int secondIndex=0; secondIndex<allIsPush.size(); ++secondIndex) {
            if(allIsPush.at(secondIndex).pos() == newPos) {
                if(isMovable(dir, allIsPush.at(secondIndex))) {
                    pushable(dir, newPos);
                    changePosition(dir, allIsPush.at(secondIndex));
                }
            }
        }
    }
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
