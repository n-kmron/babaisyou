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
         * @brief change in elements_ the position in a new direction for the gameobject passed as a parameter
         */
        void changePosition(const Direction & dir, const GameObject & object);


        /**
         * @brief return the type playable of the object affected by a rule
         */
        Element fromRuleToPlayable(const Element & element);
    public:

        /**
         * @brief Constructor of LevelMechanics from the gameobjects
         */
        LevelMechanics(const std::vector<GameObject> & elements, const unsigned int numLevel);

        // getters
        std::vector<GameObject> & elements();

        RuleManager rules() const;

        unsigned int level() const;

        // setters
        void setElements(const std::vector<GameObject> & elements);

        void setRules(const RuleManager & rules);

        // other methods

        /**
         * @brief return if the position is inside of the map
         */
        bool contains(const Position & pos);


        /**
         * @brief add an element on the map
         */
        void setElementPosition(const GameObject & element);

        /**
         * @brief drop the last element on a position in the board
        */
        void dropElement(const Position & pos, const Element & element);

        /**
         * @brief find all the GameObjects from a type of Element
         */
        std::vector<GameObject> findAllElement(const Element & element);

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

        void pushable(const Direction & dir, const Position & pos);

        LevelMechanics & operator=(const LevelMechanics & other);
};


#endif // LEVELMECHANICS_H
