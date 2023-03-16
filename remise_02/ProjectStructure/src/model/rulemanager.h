#ifndef RULEMANAGER_H
#define RULEMANAGER_H

#include <iostream>
#include <vector>
#include <map>
#include "element.h"

class RuleManager
{
    private:
        std::map<Element,std::vector<Element>> rules_;
        inline static const std::vector<Element> leftWords_;
        inline static const std::vector<Element> rightWords_;

    public:

        /*!
         * \brief Constructeur de RuleManager à partir d'une liste de d'element sur lesquels vont s'appliquer
         * le complement pour former une règle.
         *
         *
         * \param subject les sujet sur qui une actions est appliqué(complement) pour faire une règles.
         * \param complement l'action/le comportement que l'on souhaite appliqué aux elements de subject.
         *
         * \throw std::invalid_argument si un des paramètres n'est pas valide.
         */
        RuleManager(const std::vector<Element> & subject,const Element & complement);


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
         * \throw std::invalid_argument si un des paramètres n'est pas valide.
         */
        void addRule(const Element & complement,const Element & subject);

        /*!
         * \brief Permet de retirer une règle de la map rules.
         *
         *
         * \param complement l'action/le comportement qui défini la règle à supprimer.
         * \param subject le type de l'element sur le quel s'applique la règle à supprimer.
         *
         * \throw std::invalid_argument si un des paramètres n'est pas valide.
         */
        void removeRule(const Element & complement,const Element & subject);

        /**
         * @brief scanne l'ensemble du plateau de jeu pour trouver les règles actives et met à jour la liste des règles
         */
        void scanRules();

        /*!
         * \brief Permet de verifier si l'element est un mot qui peut se placer à gauche/en haut d'un IS.
         *
         */
        bool isWordLeft();

        /*!
         * \brief Permet de verifier si l'element est un mot qui peut se placer à droite/en bas d'un IS.
         *
         */
        bool isWordRight();
};

#endif // RULEMANAGER_H
