#ifndef RULEMANAGER_H
#define RULEMANAGER_H

#include <iostream>
#include <vector>
#include <map>
#include "element.h"
#include "gameobject.h"

class RuleManager
{
    private:
        std::map<Element,std::vector<Element>> rules_;
        inline static std::vector<Element> material_; //left words
        inline static std::vector<Element> aspect_; //right words

        /**
         * @brief used to 'scanRules'
         */
        void checkRules(const std::vector<GameObject> & elements, int isIndex, Direction materialDir, Direction aspectDir);

    public:

        /**
         * @brief Constructor of a RuleManager
         * instantiate the two static vectors
         */
        RuleManager();

        //getter
        std::map<Element,std::vector<Element>> rules();

        /*!
         * \brief add a new effective rule
         *
         *
         * \param aspect the behaviour that define the rule
         * \param material the element type on what the rule will apply
         *
         */
        void addRule(const Element & aspect,const Element & material);

        /**
         * @brief scan the whole board to find the active rules
         */
        void scanRules(const std::vector<GameObject> & elements);


        /*!
         * \brief check if an element could be considered as a  'material', word who could be placed on the left/the top of a IS.
         *
         */
        bool isMaterial(const Element & element);

        /*!
         * \brief check if an element could be considred as an 'aspect', word who could be placed on the right/the bottom of a IS.
         *
         */
        bool isAspect(const Element & element);
};

#endif // RULEMANAGER_H
