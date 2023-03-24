#ifndef LEVEL_H
#define LEVEL_H

class Level
{
    private:
        int height_;
        int width_;

    public:

        /**
         * @brief getter de l'attribut height
         * @return
         */
        inline int height() const;

        /**
         * @brief getter de l'attribut width
         * @return
         */
        inline int width() const;
};

int Level::height() const {
    return height_;
}

int Level::width() const {
    return width_;
}

#endif // LEVEL_H
