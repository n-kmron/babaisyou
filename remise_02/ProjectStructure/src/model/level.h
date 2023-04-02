#ifndef LEVEL_H
#define LEVEL_H

/**
 * @brief The Level class
 *
 * note that we did an inline class because of the small size
 */
class Level
{
    private:
        int height_;
        int width_;

    public:


        //getters
        inline int height() const;
        inline int width() const;
};

int Level::height() const {
    return height_;
}

int Level::width() const {
    return width_;
}

#endif // LEVEL_H
