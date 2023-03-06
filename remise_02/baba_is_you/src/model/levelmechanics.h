#ifndef LEVELMECHANICS_H
#define LEVELMECHANICS_H

#include "gameobject.h"
#include <iostream>
#include <vector>

class LevelMechanics
{
    private:
        /**
         * @brief elements_ la liste des éléments composant le plateau de jeu
         */
        std::vector<GameObject> elements_;

        /**
         * @brief level_ les données du niveau
         */
        Level level_;

        /**
         * @brief rules_ les règles actives du niveau
         */
        RuleManager rules_;

    public:

        /**
         * @brief Constrcutteur LevelMechanics à partir de ses éléments et ses règles
         *
         * @param elements les éléments actifs
         * @param rules les règles actives
         */
        inline LevelMechanics(const std::vector<GameObject> & elements, const std::vector<RuleManager> & rules);

        // getters
        /*!
         * \brief Accesseur en lecture des éléments du niveau
         *
         * \return un vector d'éléments
         */
        inline std::vector<GameObject> elements() const;

        /*!
         * \brief Accesseur en lecture des données uniques du niveau (dimensions)
         *
         * \return le niveau
         */
        inline Level level() const;

        /**
         * @brief Accesseur en lecture des règles actives du niveau
         *
         * @return les règles
         */
        inline RuleManager rules() const;

        // autres méthodes

        /*!
         * \brief Permet d'afficher le plateau de jeu sous forme d'une chaine de charactères.
         *
         *
         * \return le niveau sous forme de chaîne de caractères
         */
        inline std::string to_string() const;

        /**
         * @brief supprime le dernier élément sur une case à partir d'une position sur un plateau
         * @param pos la position
         */
        inline void dropElement(const Position & pos);

        /**
         * @brief vérifie qu'une position est bien contenue dans les limites du jeu
         * @param pos la position
         * @return un bool
         */
        inline bool contains(const Position & pos);

        /**
         * @brief trouve tous les éléments et leur position (GameObject) d'un certain type
         * @param element le type d'élément à trouver
         * @return un vector contenant tous les éléments d'un type
         */
        inline std::vector<GameObject> findAllElement(const Element & element);

        /**
         * @brief déplace l'élément isYou vers une nouvelle direction
         * @param dir la direction
         */
        inline void move(const Direction & dir);

        /**
         * @brief place un élément sur la plateau à une position définie
         * @param element l'élément à placer
         * @param pos la position
         */
        inline void setElementPosition(const Element & element, const Position & pos);

        /**
         * @brief vérifie si un élément à une position peut être déplacé
         * @param pos la nouvelle position à déplacer
         * @param element l'element
         * @return un bool
         */
        inline bool isMovable(const Position & pos, const GameObject & element);

        /**
         * @brief vérifie si le niveau est gagné
         * @return un bool
         */
        inline bool isWon();

        /**
         * @brief vérifie si le joueur est mort
         * @return un bool
         */
        inline bool isKill();

        /**
         * @brief vérifie si un élément est poussable
         * @return un bool
         */
        inline bool pushable();

        /**
         * @brief scanne l'ensemble du plateau de jeu pour trouver les règles actives et met à jour la liste des règles
         */
        inline void findAllRules();
};

#endif // LEVELMECHANICS_H
