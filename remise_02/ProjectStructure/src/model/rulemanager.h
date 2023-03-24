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

    public:

        /**
         * @brief Constructeur de RuleManager
         * instancie les 2 vector static
         */
        RuleManager();

        /**
         * @brief getter of rules_ attribute
         * @return
         */
        std::map<Element,std::vector<Element>> rules();

        /*!
         * \brief Permet d'ajouter une regles à la map rules en attributs.
         *
         *
         * \param complement l'action/le comportement qui défini la règle.
         * \param subject le type de l'element sur le quel s'appliquera la règle.
         *
         */
        void addRule(const Element & aspect,const Element & material);

        /**
         * @brief scanne l'ensemble du plateau de jeu pour trouver les règles actives et met à jour la liste des règles
         */
        void scanRules(const std::vector<GameObject> & elements);

        std::vector<Element> findElementAtPosition(const std::vector<GameObject> & elements, const Position & pos);

        /*!
         * \brief Permet de verifier si l'element est un 'material' d'une règle, mot qui peut se placer à gauche/en haut d'un IS.
         *
         */
        bool isMaterial(const Element & element);

        /*!
         * \brief Permet de verifier si l'element est un 'aspect' d'une règle, mot qui peut se placer à droite/en bas d'un IS.
         *
         */
        bool isAspect(const Element & element);
};

#endif // RULEMANAGER_H
