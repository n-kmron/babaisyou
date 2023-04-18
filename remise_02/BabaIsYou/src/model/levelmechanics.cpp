#include "levelmechanics.h"
#include "../util.cpp"
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

LevelMechanics::LevelMechanics(const std::vector<GameObject> & elements, const unsigned int numLevel) : elements_ { elements }, rules_ { RuleManager() }, level_ { Level(numLevel) } {
    rules_.scanRules(elements_);
}


// BREAK LINE -> help functions (private)

bool LevelMechanics::contains(const Position & pos) {
    int row = pos.row();
    int col = pos.col();
    return !(row > level_.height()-2 || row < 1 || col > level_.width()-2 || col < 1);

}

void LevelMechanics::setElementPosition(const GameObject & element) {
    elements_.push_back(element);
}

vector<GameObject> LevelMechanics::findAllElement(const Element & element) {
    vector<GameObject> typeElement;
    for(unsigned int elementIndex=0; elementIndex<elements_.size(); ++elementIndex) {
        if(elements_.at(elementIndex).element() == element) {
            typeElement.push_back(elements_.at(elementIndex));
        }
    }
    return typeElement;
}

void LevelMechanics::setNewPosition(const Direction & dir, const GameObject & object) {
    for(unsigned int index=0; index<elements_.size(); ++index) {
        GameObject current = elements_.at(index);
        if(current.element() == object.element() && current.pos() == object.pos()) {
            Position pos = current.pos().next(dir);
            elements_.at(index).setPosition(pos);
        }
    }
}

vector<GameObject> LevelMechanics::fromRuleToGameObjectOccurences(const Element & rule) {
    vector<GameObject> allRules;
    vector<Element> isRule = rules_.rules()[rule];
    for(unsigned int isYouIndex=0; isYouIndex<isRule.size(); ++isYouIndex) {
        Element isRuleType = fromRuleTypeToPlayableType(isRule.at(isYouIndex));
        allRules = findAllElement(isRuleType);
    }
    return allRules;
}

Element LevelMechanics::fromRuleTypeToPlayableType(const Element & element) {
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

vector<Element> LevelMechanics::findAllMurders() {
    vector<Element> murdered;
    vector<Element> isSink = rules_.rules()[Element::SINK];
    vector<Element> isKill = rules_.rules()[Element::KILL];
    for(unsigned int index=0; index<isSink.size(); ++index) {
        murdered.push_back(fromRuleTypeToPlayableType(isSink.at(index)));
    }
    for(unsigned int index=0; index<isKill.size(); ++index) {
        murdered.push_back(fromRuleTypeToPlayableType(isKill.at(index)));
    }
    return murdered;
}

vector<string> LevelMechanics::gameStateAsStrings() {
    vector<string> levelLines;
    for(unsigned int index=0; index<elements_.size(); ++index) {
        stringstream ss;

        string element { elemConversionFromElementToFile(elements_.at(index).element())};
        string x { to_string(elements_.at(index).pos().col()) };
        string y { to_string(elements_.at(index).pos().row()) };
        ss << element << " " << x << " " << y;
        string line = ss.str();
        levelLines.push_back(line);
    }
    return levelLines;
}

//-------------BREAK LINE -> game functions (public)

void LevelMechanics::move(const Direction & dir) {
    rules_.scanRules(elements_);
    vector<Element> isYou = rules_.rules()[Element::YOU];
    for(unsigned int index=0; index<isYou.size(); ++index) {
        Element isYouType = fromRuleTypeToPlayableType(isYou.at(index));
        vector<GameObject> allIsYou = findAllElement(isYouType);
        for(unsigned int secondIndex=0; secondIndex<allIsYou.size(); ++secondIndex) {
            if(isMovable(dir,allIsYou.at(secondIndex))) {
                setNewPosition(dir, allIsYou.at(secondIndex));
                checkIfGameObjectPushed(dir, allIsYou.at(secondIndex).pos());
                checkIfRulePushed(dir, allIsYou.at(secondIndex).pos());
            }
        }
    }
}

bool LevelMechanics::isMovable(const Direction & dir, const GameObject & element) {
    Position pos = element.pos().next(dir);
    if(!contains(pos)) return false;
    vector<Element> elementsOnNewPosition = findElementAtPosition(elements_, pos);

    //check if the element on the new pos makes a stop
    vector<Element> isStop = rules_.rules()[Element::STOP];
    for(unsigned int index=0; index<elementsOnNewPosition.size(); ++index) {
        for(unsigned int secondIndex=0; secondIndex<isStop.size(); ++secondIndex) {
            if(elementsOnNewPosition.at(index) == fromRuleTypeToPlayableType(isStop.at(secondIndex))) {
                return false;
            }
        }
    }
    return true;
}

bool LevelMechanics::isMovable(const Direction & dir, Position pos) {
    if(!contains(pos)) return false;
    vector<Element> elementsOnNewPosition = findElementAtPosition(elements_, pos);

    //check if the element on the new pos makes a stop
    vector<Element> isStop = rules_.rules()[Element::STOP];
    for(unsigned int index=0; index<elementsOnNewPosition.size(); ++index) {
        for(unsigned int secondIndex=0; secondIndex<isStop.size(); ++secondIndex) {
            if(elementsOnNewPosition.at(index) == fromRuleTypeToPlayableType(isStop.at(secondIndex))) {
                return false;
            }
        }
    }
    return true;
}

bool LevelMechanics::isWon() {
    //check if the element on the new pos makes a win
    vector<GameObject> allIsWin = fromRuleToGameObjectOccurences(Element::WIN);
    vector<GameObject> allIsYou = fromRuleToGameObjectOccurences(Element::YOU);

    //for each winning type, find all occurences on the map and check if a isYou element is on the same position
    for(unsigned int i=0; i<allIsYou.size(); ++i) {
        for(unsigned int j=0; j<allIsWin.size(); ++j) {
            if(allIsYou.at(i).pos() == allIsWin.at(j).pos()) return true;
        }
    }
    return false;
}

bool LevelMechanics::isKill() {
    vector<Element> murdered = findAllMurders();

    //for each murder type, find all occurences on the map and check if a isYou element is on the same position
    for(unsigned int index=0; index<murdered.size(); ++index) {
        vector<GameObject> allMurderers = findAllElement(murdered.at(index));
        vector<GameObject> allIsYou = fromRuleToGameObjectOccurences(Element::YOU);

        for(unsigned int i=0; i<allIsYou.size(); ++i) {
            for(unsigned int j=0; j<allMurderers.size(); ++j) {
                if(allIsYou.at(i).pos() == allMurderers.at(j).pos()) return true;
            }
        }
    }
    return false;
}

bool LevelMechanics::isThereIsYou() {
     vector<Element> isYou = rules_.rules()[Element::YOU];
     return !isYou.empty();
}

void LevelMechanics::checkIfGameObjectPushed(const Direction & dir, Position pos) {
    Position newPos = pos.next(dir);
    vector<GameObject> allIsPush = fromRuleToGameObjectOccurences(Element::PUSH);

    for(unsigned int secondIndex=0; secondIndex<allIsPush.size(); ++secondIndex) {
        if(allIsPush.at(secondIndex).pos() == newPos) {
            if(isMovable(dir, allIsPush.at(secondIndex))) {
                checkIfGameObjectPushed(dir, newPos);
                setNewPosition(dir, allIsPush.at(secondIndex));
            }
        }
    }
}

void LevelMechanics::checkIfRulePushed(const Direction & dir, Position pos) {
    Position posToCheck = pos.next(dir);
    vector<Element> allRulesElement = allRules();

    for(unsigned int index=0; index<allRulesElement.size(); ++index) {
        Element ruleType = allRulesElement.at(index);
        vector<GameObject> occurences = findAllElement(ruleType);

        for(unsigned int occurencesIndex=0; occurencesIndex<occurences.size(); ++occurencesIndex) {
            if(occurences.at(occurencesIndex).pos() == posToCheck) {
                if(isMovable(dir, occurences.at(occurencesIndex))) {
                    checkIfRulePushed(dir, posToCheck);
                    if(isMovable(dir, posToCheck)) {
                        setNewPosition(dir, occurences.at(occurencesIndex));
                    }
                }
            }
        }
    }
}

void LevelMechanics::saveGame(string location) {
    vector<string> levelLines { gameStateAsStrings() };
    ofstream outfile(location);

    if (outfile.is_open())
    {
        unsigned int numLevel = level_.numLevel();
        outfile << numLevel << endl;

        for (const auto& line : levelLines)
        {
            outfile << line << endl;
        }
        outfile.close();
        cout << "The game has been saved !" << endl;
        exit(0);
    }
    else
    {
        cerr << "could not open 'saves' folder to create the save." << endl;
    }
}


// BREAK LINE -> getters

vector<GameObject> & LevelMechanics::elements() {
    return elements_;
}

RuleManager LevelMechanics::rules() const {
    return rules_;
}

unsigned int LevelMechanics::level() const {
    return level_.numLevel();
}

std::pair<unsigned int, unsigned int> LevelMechanics::levelSize() {
    pair<unsigned int, unsigned int> size(level_.height(), level_.width());
    return size;
}
