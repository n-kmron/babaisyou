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

#endif // LEVEL_H
