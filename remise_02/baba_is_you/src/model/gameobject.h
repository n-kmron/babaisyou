#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "element.h"
#include "position.h"
#include <iostream>

class GameObject
{
    private:
        Element element_;
        Position pos_;

    public:

        /*!
         * \brief Constructeur de GameObject à partir de son élément et sa position.
         *
         *
         * \param element l'objet
         * \param pos la position de l'objet
         *
         * \throw std::invalid_argument si un des paramètres n'est pas valide.
         */
        inline GameObject(const Element & element, const Position & pos);


        // autres méthodes
        /*!
         * \brief Représentation d'un GameObject sous la forme d'une chaîne de caractères.
         *
         *
         * \return le GameObject sous forme de chaîne de caractères
         */
        inline std::string to_string() const;

        // getters
        /*!
         * \brief Accesseur en lecture de l'element du GameObject.
         *
         * \return l'element du GameObject
         */
        inline Element element() const;

        /*!
         * \brief Accesseur en lecture de la position du GameObject.
         *
         * \return la position du GameObject
         */
        inline Position pos() const;
};

#endif // GAMEOBJECT_H
