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


void RuleManager::scanRules(const vector<GameObject> & elements) {
    //on vide l'ensemble des règles avant de les rescanner
    rules_.clear();

    //on scanne l'ensemble des éléments
    for(int i=0; i<elements.size(); ++i) {
        if(elements.at(i).element() == Element::IS) { //chercher les is
            for(int j=0; j<elements.size(); ++j) {


                //chercher si il y a un mot à gauche et à droite
                if(elements.at(i).pos().row() == elements.at(j).pos().row() && elements.at(i).pos().col() == elements.at(j).pos().col()-1) {
                    for(int k=0; k<elements.size(); ++k) {
                        if(elements.at(i).pos().row() == elements.at(k).pos().row() && elements.at(i).pos().col() == elements.at(k).pos().col()+1) { //chercher si il y a un mot à droite
                            //CA VEUT DIRE QUON A UN ELEMENT A GAUCHE ET A DROITE
                            if(isMaterial(elements.at(j).element()) && isAspect(elements.at(k).element())) {
                                addRule(elements.at(k).element(), elements.at(j).element());
                            }
                        }
                    }
                }



                //chercher si il y a un mot en haut et en bas
                if(elements.at(i).pos().row() == elements.at(j).pos().row()-1 && elements.at(i).pos().col() == elements.at(j).pos().col()) {
                    for(int k=0; k<elements.size(); ++k) {
                        if(elements.at(i).pos().row() == elements.at(k).pos().row()+1 && elements.at(i).pos().col() == elements.at(k).pos().col()) {
                            //CA VEUT DIRE QUON A UN ELEMENT EN HAUT ET EN BAS
                            if(isMaterial(elements.at(j).element()) && isAspect(elements.at(k).element())) {
                                addRule(elements.at(k).element(), elements.at(j).element());
                            }
                        }
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
