#ifndef LEVELMECHANICS_H
#define LEVELMECHANICS_H

#include "level.h"
#include "rulemanager.h"
#include "gameobject.h"
#include <iostream>
#include <vector>

class LevelMechanics
{
    private:
        /**
         * @brief elements_ all the elements (and their position) actually on the board
         */
        std::vector<GameObject> elements_;

        /**
         * @brief rules_ active rules in the game
         */
        RuleManager rules_;

        Level level_;

        /**
         * @brief return if the position is inside of the map
         */
        bool contains(const Position & pos);


        /**
         * @brief set a new position for the gameobject in elements_ in a new direction
         */
        void setNewPosition(const Direction & dir, const GameObject & object);


        /**
         * @brief return the type playable of the object affected by a rule
         */
        Element fromRuleTypeToPlayableType(const Element & element);

        /**
         * @brief find all occurences in the board affected by a rule
         */
        std::vector<GameObject> fromRuleToGameObjectOccurences(const Element & rule);


        /**
         * @brief remember the actual game's state and store it in a vector<string>
         */
        std::vector<std::string> gameStateAsStrings();


        /**
         * @brief intialize a vector with all playable elements that can kill
         */
        std::vector<Element> findAllMurders();


    public:

        LevelMechanics(const std::vector<GameObject> & elements, const unsigned int numLevel);

        // getters
        std::vector<GameObject> & elements();

        RuleManager rules() const;

        unsigned int level() const;

        /**
         * @brief the row is the first member of the pair and col is the second one
         */
        std::pair<unsigned int, unsigned int> levelSize();

        // other methods

        /**
         * @brief move all the 'isYou' elements in a direction
         */
        void move(const Direction & dir);

        /**
         * @brief check if a gameobject can move in a direction
         */
        bool isMovable(const Direction & dir, const GameObject & element);

        bool isWon();

        bool isKill();

        bool isThereIsYou();

        void checkIfRulePushed(const Direction & dir, Position pos);

        void checkIfGameObjectPushed(const Direction & dir, Position pos);

        /**
         * @brief save the current state of the game
         */
        void saveGame(std::string location);

        /**
         * @brief find all the GameObjects from a type of Element
         */
        std::vector<GameObject> findAllElement(const Element & element);

        /**
         * @brief add an element on the map
         */
        void setElementPosition(const GameObject & element);
};


#endif // LEVELMECHANICS_H